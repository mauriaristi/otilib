# Elementary functions over scalars and arrays.

import math as _math

# Real arguments take the plain floating-point function, as in pyoti.sparse.
_REAL_FUNCTIONS = {
    "sin": _math.sin, "cos": _math.cos, "tan": _math.tan, "asin": _math.asin, "acos": _math.acos,
    "atan": _math.atan, "sinh": _math.sinh, "cosh": _math.cosh, "tanh": _math.tanh,
    "asinh": _math.asinh, "acosh": _math.acosh, "atanh": _math.atanh, "exp": _math.exp,
    "log": _math.log, "log10": _math.log10, "sqrt": _math.sqrt, "cbrt": np.cbrt, "erf": _math.erf,
}


# ********************************************************************************************************
cdef object _unary(object value, str name):
    """
    Dispatch a scalar or array mathematical function to its native kernel.

    Parameters
    ----------
    value : ssotinum or oarrss or arrss
        Argument.
    name : str
        Mathematical function name.

    Returns
    -------
    ssotinum or oarrss or arrss
        Function result.
    """

    cdef ssotinum scalar
    cdef oarrss array
    cdef arrss aos
    cdef oarrss_t result = oarrss_init()
    cdef arrss_t aos_result = arrss_init()

    # Gauss-point values (semisparse/gauss/base.pxi) run the SoA kernel on their embedded array.
    if isinstance(value, _ssfe):

        return _fe_unary(value, name)

    # end if

    if isinstance(value, Real):

        return _REAL_FUNCTIONS[name](value)

    # end if

    if isinstance(value, sotinum):

        value = ssotinum(value)

    # end if

    if isinstance(value, ssotinum):

        scalar = value

        if name == "sin":

            return ssotinum.wrap(ssoti_sin(&scalar.num, _dhl))

        elif name == "cos":

            return ssotinum.wrap(ssoti_cos(&scalar.num, _dhl))

        elif name == "tan":

            return ssotinum.wrap(ssoti_tan(&scalar.num, _dhl))

        elif name == "asin":

            return ssotinum.wrap(ssoti_asin(&scalar.num, _dhl))

        elif name == "acos":

            return ssotinum.wrap(ssoti_acos(&scalar.num, _dhl))

        elif name == "atan":

            return ssotinum.wrap(ssoti_atan(&scalar.num, _dhl))

        elif name == "sinh":

            return ssotinum.wrap(ssoti_sinh(&scalar.num, _dhl))

        elif name == "cosh":

            return ssotinum.wrap(ssoti_cosh(&scalar.num, _dhl))

        elif name == "tanh":

            return ssotinum.wrap(ssoti_tanh(&scalar.num, _dhl))

        elif name == "asinh":

            return ssotinum.wrap(ssoti_asinh(&scalar.num, _dhl))

        elif name == "acosh":

            return ssotinum.wrap(ssoti_acosh(&scalar.num, _dhl))

        elif name == "atanh":

            return ssotinum.wrap(ssoti_atanh(&scalar.num, _dhl))

        elif name == "exp":

            return ssotinum.wrap(ssoti_exp(&scalar.num, _dhl))

        elif name == "log":

            return ssotinum.wrap(ssoti_log(&scalar.num, _dhl))

        elif name == "log10":

            return ssotinum.wrap(ssoti_log10(&scalar.num, _dhl))

        elif name == "sqrt":

            return ssotinum.wrap(ssoti_sqrt(&scalar.num, _dhl))

        elif name == "cbrt":

            return ssotinum.wrap(ssoti_cbrt(&scalar.num, _dhl))

        else:

            return ssotinum.wrap(ssoti_erf(&scalar.num, _dhl))

        # end if

    elif isinstance(value, oarrss):

        array = value

        if name == "sin":

            oarrss_sin_to(&array.arr, &result, _dhl)

        elif name == "cos":

            oarrss_cos_to(&array.arr, &result, _dhl)

        elif name == "tan":

            oarrss_tan_to(&array.arr, &result, _dhl)

        elif name == "asin":

            oarrss_asin_to(&array.arr, &result, _dhl)

        elif name == "acos":

            oarrss_acos_to(&array.arr, &result, _dhl)

        elif name == "atan":

            oarrss_atan_to(&array.arr, &result, _dhl)

        elif name == "sinh":

            oarrss_sinh_to(&array.arr, &result, _dhl)

        elif name == "cosh":

            oarrss_cosh_to(&array.arr, &result, _dhl)

        elif name == "tanh":

            oarrss_tanh_to(&array.arr, &result, _dhl)

        elif name == "asinh":

            oarrss_asinh_to(&array.arr, &result, _dhl)

        elif name == "acosh":

            oarrss_acosh_to(&array.arr, &result, _dhl)

        elif name == "atanh":

            oarrss_atanh_to(&array.arr, &result, _dhl)

        elif name == "exp":

            oarrss_exp_to(&array.arr, &result, _dhl)

        elif name == "log":

            oarrss_log_to(&array.arr, &result, _dhl)

        elif name == "log10":

            oarrss_log10_to(&array.arr, &result, _dhl)

        elif name == "sqrt":

            oarrss_sqrt_to(&array.arr, &result, _dhl)

        elif name == "cbrt":

            oarrss_cbrt_to(&array.arr, &result, _dhl)

        else:

            oarrss_erf_to(&array.arr, &result, _dhl)

        # end if

        return oarrss.wrap(result)

    elif isinstance(value, arrss):

        aos = value

        if name == "sin":

            arrss_sin_to(&aos.arr, &aos_result, _dhl)

        elif name == "cos":

            arrss_cos_to(&aos.arr, &aos_result, _dhl)

        elif name == "tan":

            arrss_tan_to(&aos.arr, &aos_result, _dhl)

        elif name == "asin":

            arrss_asin_to(&aos.arr, &aos_result, _dhl)

        elif name == "acos":

            arrss_acos_to(&aos.arr, &aos_result, _dhl)

        elif name == "atan":

            arrss_atan_to(&aos.arr, &aos_result, _dhl)

        elif name == "sinh":

            arrss_sinh_to(&aos.arr, &aos_result, _dhl)

        elif name == "cosh":

            arrss_cosh_to(&aos.arr, &aos_result, _dhl)

        elif name == "tanh":

            arrss_tanh_to(&aos.arr, &aos_result, _dhl)

        elif name == "asinh":

            arrss_asinh_to(&aos.arr, &aos_result, _dhl)

        elif name == "acosh":

            arrss_acosh_to(&aos.arr, &aos_result, _dhl)

        elif name == "atanh":

            arrss_atanh_to(&aos.arr, &aos_result, _dhl)

        elif name == "exp":

            arrss_exp_to(&aos.arr, &aos_result, _dhl)

        elif name == "log":

            arrss_log_to(&aos.arr, &aos_result, _dhl)

        elif name == "log10":

            arrss_log10_to(&aos.arr, &aos_result, _dhl)

        elif name == "sqrt":

            arrss_sqrt_to(&aos.arr, &aos_result, _dhl)

        elif name == "cbrt":

            arrss_cbrt_to(&aos.arr, &aos_result, _dhl)

        else:

            arrss_erf_to(&aos.arr, &aos_result, _dhl)

        # end if

        return arrss.wrap(aos_result)

    # end if

    raise TypeError("{} expects a semi-sparse scalar or array".format(name))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def sin(val, out=None):
    """
    Evaluate sine elementwise.

    Parameters
    ----------
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Sine.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Cosine.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Tangent.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Inverse sine.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Inverse cosine.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Inverse tangent.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Hyperbolic sine.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Hyperbolic cosine.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Hyperbolic tangent.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Inverse hyperbolic sine.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Inverse hyperbolic cosine.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Inverse hyperbolic tangent.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Exponential.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Natural logarithm.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Base-10 logarithm.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Square root.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Cube root.
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
    val : ssotinum or oarrss
        Argument.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss
        Error function.
    """

    return _finish(_unary(val, "erf"), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def pow(val, e, out=None):
    """
    Raise a semi-sparse scalar or array to a real power.

    Parameters
    ----------
    val : ssotinum or oarrss or arrss
        Base.
    e : float
        Real exponent, or an OTI scalar.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss or arrss
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
    val : ssotinum or oarrss or arrss
        Argument.
    b : float
        Logarithm base.
    out : ssotinum or oarrss or arrss, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss or arrss
        Logarithm in the given base.
    """

    cdef ssotinum scalar

    if isinstance(val, ssotinum):

        scalar = val
        return _finish(ssotinum.wrap(ssoti_logb(&scalar.num, b, _dhl)), out)

    elif isinstance(val, Real):

        return _math_log(val) / _math_log(b)

    elif isinstance(val, (oarrss, arrss, _ssfe)):

        return _finish(log(val) / _math_log(b), out)

    # end if

    raise TypeError("logb expects a semi-sparse scalar or array")

# end function
# --------------------------------------------------------------------------------------------------------
