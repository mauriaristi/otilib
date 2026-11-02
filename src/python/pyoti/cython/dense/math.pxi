# Elementary functions over scalars and arrays (dense scalar, SoA and AoS arrays, Gauss-point values).
#
# The C kernels are called through their `_to` variants, which return statuses: a failed call frees the
# C result and raises through _status (MemoryError, ValueError, ...), never returns a half-built value.
# Function pointers of the 18 kernels of each kind are kept in tables indexed by the position of the
# name in _M_NAMES.

import math as _math

# Real arguments take the plain floating-point function, as in pyoti.sparse.
_REAL_FUNCTIONS = {
    "sin": _math.sin, "cos": _math.cos, "tan": _math.tan, "asin": _math.asin, "acos": _math.acos,
    "atan": _math.atan, "sinh": _math.sinh, "cosh": _math.cosh, "tanh": _math.tanh,
    "asinh": _math.asinh, "acosh": _math.acosh, "atanh": _math.atanh, "exp": _math.exp,
    "log": _math.log, "log10": _math.log10, "sqrt": _math.sqrt, "cbrt": np.cbrt, "erf": _math.erf,
}

_M_NAMES = ("sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh", "tanh", "asinh", "acosh",
            "atanh", "exp", "log", "log10", "sqrt", "cbrt", "erf")
_M_INDEX = {name: index for index, name in enumerate(_M_NAMES)}

ctypedef int (*_m_scalar_fn)(const otinum_t*, otinum_t*, dhelpl_t) noexcept
ctypedef int (*_m_soa_fn)(const oarr_t*, oarr_t*, dhelpl_t) noexcept
ctypedef int (*_m_aos_fn)(const arro_t*, arro_t*, dhelpl_t) noexcept

cdef _m_scalar_fn _M_SCALAR[18]
cdef _m_soa_fn _M_SOA[18]
cdef _m_aos_fn _M_AOS[18]


# ********************************************************************************************************
cdef void _m_init_tables():
    """
    Fill the function-pointer tables of the native kernels.
    """

    _M_SCALAR[0] = oti_sin_to
    _M_SOA[0] = oarr_sin_to
    _M_AOS[0] = arro_sin_to

    _M_SCALAR[1] = oti_cos_to
    _M_SOA[1] = oarr_cos_to
    _M_AOS[1] = arro_cos_to

    _M_SCALAR[2] = oti_tan_to
    _M_SOA[2] = oarr_tan_to
    _M_AOS[2] = arro_tan_to

    _M_SCALAR[3] = oti_asin_to
    _M_SOA[3] = oarr_asin_to
    _M_AOS[3] = arro_asin_to

    _M_SCALAR[4] = oti_acos_to
    _M_SOA[4] = oarr_acos_to
    _M_AOS[4] = arro_acos_to

    _M_SCALAR[5] = oti_atan_to
    _M_SOA[5] = oarr_atan_to
    _M_AOS[5] = arro_atan_to

    _M_SCALAR[6] = oti_sinh_to
    _M_SOA[6] = oarr_sinh_to
    _M_AOS[6] = arro_sinh_to

    _M_SCALAR[7] = oti_cosh_to
    _M_SOA[7] = oarr_cosh_to
    _M_AOS[7] = arro_cosh_to

    _M_SCALAR[8] = oti_tanh_to
    _M_SOA[8] = oarr_tanh_to
    _M_AOS[8] = arro_tanh_to

    _M_SCALAR[9] = oti_asinh_to
    _M_SOA[9] = oarr_asinh_to
    _M_AOS[9] = arro_asinh_to

    _M_SCALAR[10] = oti_acosh_to
    _M_SOA[10] = oarr_acosh_to
    _M_AOS[10] = arro_acosh_to

    _M_SCALAR[11] = oti_atanh_to
    _M_SOA[11] = oarr_atanh_to
    _M_AOS[11] = arro_atanh_to

    _M_SCALAR[12] = oti_exp_to
    _M_SOA[12] = oarr_exp_to
    _M_AOS[12] = arro_exp_to

    _M_SCALAR[13] = oti_log_to
    _M_SOA[13] = oarr_log_to
    _M_AOS[13] = arro_log_to

    _M_SCALAR[14] = oti_log10_to
    _M_SOA[14] = oarr_log10_to
    _M_AOS[14] = arro_log10_to

    _M_SCALAR[15] = oti_sqrt_to
    _M_SOA[15] = oarr_sqrt_to
    _M_AOS[15] = arro_sqrt_to

    _M_SCALAR[16] = oti_cbrt_to
    _M_SOA[16] = oarr_cbrt_to
    _M_AOS[16] = arro_cbrt_to

    _M_SCALAR[17] = oti_erf_to
    _M_SOA[17] = oarr_erf_to
    _M_AOS[17] = arro_erf_to

# end function
# --------------------------------------------------------------------------------------------------------


_m_init_tables()


# ********************************************************************************************************
cdef object _unary(object value, str name):
    """
    Dispatch a scalar or array mathematical function to its native kernel.

    Parameters
    ----------
    value : otinum or omat or arro
        Argument.
    name : str
        Mathematical function name.

    Returns
    -------
    otinum or omat or arro
        Function result.

    Raises
    ------
    TypeError
        If the argument is not a real, an OTI scalar or an OTI array.
    MemoryError
        If a result cannot be allocated.
    """

    cdef otinum scalar
    cdef omat soa
    cdef arro aos
    cdef otinum_t result = oti_init()
    cdef oarr_t soa_result = oarr_init()
    cdef arro_t aos_result = arro_init()
    cdef int status
    cdef int index

    # Gauss-point values (dense/gauss/base.pxi) run the SoA kernel on their embedded array.
    if isinstance(value, _dnfe):

        return _fe_unary(value, name)

    # end if

    if isinstance(value, Real):

        return _REAL_FUNCTIONS[name](value)

    # end if

    index = _M_INDEX[name]

    if isinstance(value, sotinum):

        value = otinum(value)

    # end if

    if isinstance(value, otinum):

        scalar = value
        status = _M_SCALAR[index](&scalar.num, &result, _dhl)

        if status != DN_OK:

            oti_free(&result)
            _status(name, status)

        # end if

        return otinum.wrap(result)

    elif isinstance(value, omat):

        soa = value
        status = _M_SOA[index](&soa.arr, &soa_result, _dhl)

        if status != DN_OK:

            oarr_free(&soa_result)
            _status(name, status)

        # end if

        return omat.wrap(soa_result)

    elif isinstance(value, arro):

        aos = value
        status = _M_AOS[index](&aos.arr, &aos_result, _dhl)

        if status != DN_OK:

            arro_free(&aos_result)
            _status(name, status)

        # end if

        return arro.wrap(aos_result)

    # end if

    raise TypeError("{} expects a dense scalar or array".format(name))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def sin(val, out=None):
    """
    Evaluate sine elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Sine, or None when ``out`` is given.
    """

    return _finish(_unary(val, "sin"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def cos(val, out=None):
    """
    Evaluate cosine elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Cosine, or None when ``out`` is given.
    """

    return _finish(_unary(val, "cos"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def tan(val, out=None):
    """
    Evaluate tangent elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Tangent, or None when ``out`` is given.
    """

    return _finish(_unary(val, "tan"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def asin(val, out=None):
    """
    Evaluate inverse sine elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Inverse sine, or None when ``out`` is given.
    """

    return _finish(_unary(val, "asin"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def acos(val, out=None):
    """
    Evaluate inverse cosine elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Inverse cosine, or None when ``out`` is given.
    """

    return _finish(_unary(val, "acos"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def atan(val, out=None):
    """
    Evaluate inverse tangent elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Inverse tangent, or None when ``out`` is given.
    """

    return _finish(_unary(val, "atan"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def sinh(val, out=None):
    """
    Evaluate hyperbolic sine elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Hyperbolic sine, or None when ``out`` is given.
    """

    return _finish(_unary(val, "sinh"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def cosh(val, out=None):
    """
    Evaluate hyperbolic cosine elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Hyperbolic cosine, or None when ``out`` is given.
    """

    return _finish(_unary(val, "cosh"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def tanh(val, out=None):
    """
    Evaluate hyperbolic tangent elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Hyperbolic tangent, or None when ``out`` is given.
    """

    return _finish(_unary(val, "tanh"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def asinh(val, out=None):
    """
    Evaluate inverse hyperbolic sine elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Inverse hyperbolic sine, or None when ``out`` is given.
    """

    return _finish(_unary(val, "asinh"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def acosh(val, out=None):
    """
    Evaluate inverse hyperbolic cosine elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Inverse hyperbolic cosine, or None when ``out`` is given.
    """

    return _finish(_unary(val, "acosh"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def atanh(val, out=None):
    """
    Evaluate inverse hyperbolic tangent elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Inverse hyperbolic tangent, or None when ``out`` is given.
    """

    return _finish(_unary(val, "atanh"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def exp(val, out=None):
    """
    Evaluate exponential elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Exponential, or None when ``out`` is given.
    """

    return _finish(_unary(val, "exp"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def log(val, out=None):
    """
    Evaluate natural logarithm elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Natural logarithm, or None when ``out`` is given.
    """

    return _finish(_unary(val, "log"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def log10(val, out=None):
    """
    Evaluate base-10 logarithm elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Base-10 logarithm, or None when ``out`` is given.
    """

    return _finish(_unary(val, "log10"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def sqrt(val, out=None):
    """
    Evaluate square root elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Square root, or None when ``out`` is given.
    """

    return _finish(_unary(val, "sqrt"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def cbrt(val, out=None):
    """
    Evaluate cube root elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Cube root, or None when ``out`` is given.
    """

    return _finish(_unary(val, "cbrt"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def erf(val, out=None):
    """
    Evaluate error function elementwise.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Error function, or None when ``out`` is given.
    """

    return _finish(_unary(val, "erf"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def pow(val, e, out=None):
    """
    Raise a dense scalar or array to a real power.

    Parameters
    ----------
    val : otinum or omat or arro
        Base.
    e : float
        Real exponent, or an OTI scalar.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    otinum or omat or arro
        Power, or None when ``out`` is given.
    """

    return _finish(val ** e, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def logb(val, b, out=None):
    """
    Evaluate the logarithm of a scalar, array or Gauss-point value in a specified base.

    Parameters
    ----------
    val : float or otinum or omat or arro
        Argument.
    b : float
        Logarithm base.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    float or otinum or omat or arro
        Logarithm in the given base, or None when ``out`` is given.

    Raises
    ------
    TypeError
        If the argument is not a real, an OTI scalar or an OTI array.
    MemoryError
        If a result cannot be allocated.
    """

    cdef otinum scalar
    cdef otinum_t result = oti_init()
    cdef int status

    if isinstance(val, sotinum):

        val = otinum(val)

    # end if

    if isinstance(val, otinum):

        scalar = val
        status = oti_logb_to(&scalar.num, b, &result, _dhl)

        if status != DN_OK:

            oti_free(&result)
            _status("logb", status)

        # end if

        return _finish(otinum.wrap(result), out)

    elif isinstance(val, Real):

        return _math.log(val) / _math.log(b)

    elif isinstance(val, (omat, arro, _dnfe)):

        return _finish(log(val) / _math.log(b), out)

    # end if

    raise TypeError("logb expects a dense scalar or array")

# end function
# --------------------------------------------------------------------------------------------------------
