"""
Tests every supported sparse OTI array (``matso``) operation up to 4th order derivatives.

Test matrices have the form ``A(x, y) = A0 + x A1 + y A2 + q(x, y) A3`` with ``x = e(1)``,
``y = e(2)`` and ``q = x y + x^3 + x^2 y^2 + y^4``, so every derivative order up to 4 is
populated. The same expression is built symbolically with sympy, the operation is applied there
too, and every derivative d^(a+b) / dx^a dy^b with ``a + b <= ORDER`` is compared at (0, 0).
Operations that only need to agree with the (already verified) scalar path are compared entry by
entry against the scalar functions instead.

Invalid shapes must raise ``ValueError`` (the C core would call ``exit()``). The one known
limitation still open (``det`` of an array larger than 3x3 whose real part is singular) is a strict
``xfail`` test.
"""

import functools
import math
import operator

import numpy as np
import pytest
import scipy.linalg
import sympy
import pyoti.real as real
import pyoti.sparse as oti


# sympy's evalf goes through an mpmath helper that emits a DeprecationWarning per call.
pytestmark = pytest.mark.filterwarnings("ignore:bitcount function is deprecated")

ORDER = 4
REL_TOL = 1e-9
ABS_TOL = 1e-10
# Product residuals (e.g. K inv(K) - I) are compared, per direction, with RES_TOL times the scale of
# the terms that cancel there: 4th derivatives of an inverse reach 1e6, so a fixed absolute tolerance
# does not fit them.
RES_TOL = 1e-14

# Constant real operand used in the real-array operator tests.
CONST = 1.7

X_SYM, Y_SYM = sympy.symbols("x y", real=True)

# Matrix operands as (A0, A1, A2, A3): A(x, y) = A0 + x A1 + y A2 + q(x, y) A3.
# The zeros in A1..A3 give entries different sparsity patterns (x only, y only, x and q, ...).
MATRICES = {
    "A": (
        [[2.0, 1.0], [1.5, 3.0]],
        [[1.0, 0.5], [0.0, 0.0]],
        [[0.0, 0.0], [0.25, 1.0]],
        [[0.0, 0.1], [0.2, 0.0]],
    ),
    "B": (
        [[1.2, 0.7], [0.9, 2.5]],
        [[0.0, 0.3], [0.4, 0.0]],
        [[0.6, 0.0], [0.0, 0.2]],
        [[0.1, 0.0], [0.0, 0.3]],
    ),
    "M1": (
        [[2.5]],
        [[0.5]],
        [[-0.25]],
        [[0.1]],
    ),
    "M3": (
        [[4.0, 1.0, 0.5], [1.0, 3.0, 1.0], [0.5, 1.0, 2.0]],
        [[1.0, 0.0, 0.0], [0.0, 0.0, 0.5], [0.0, 0.0, 0.0]],
        [[0.0, 0.3, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 0.0]],
        [[0.0, 0.0, 0.0], [0.0, 0.0, 0.0], [0.2, 0.0, 0.1]],
    ),
    "C": (
        [[1.0, 2.0, 0.5], [0.3, 1.5, 2.0]],
        [[0.5, 0.0, 0.0], [0.0, 0.0, 1.0]],
        [[0.0, 0.2, 0.0], [0.1, 0.0, 0.0]],
        [[0.0, 0.0, 0.3], [0.0, 0.0, 0.0]],
    ),
    "D": (
        [[1.0, 0.4], [0.2, 2.0], [1.5, 0.7]],
        [[0.0, 0.3], [0.0, 0.0], [1.0, 0.0]],
        [[0.5, 0.0], [0.0, 0.6], [0.0, 0.0]],
        [[0.0, 0.0], [0.2, 0.0], [0.0, 0.1]],
    ),
    "N": (
        [[-1.5, 2.0, -0.7], [0.9, -2.2, 1.1]],
        [[0.5, 0.0, 0.2], [0.0, 0.3, 0.0]],
        [[0.0, -0.4, 0.0], [0.6, 0.0, -0.2]],
        [[0.1, 0.0, 0.0], [0.0, 0.0, 0.2]],
    ),
    # Zero leading real entry: the LU path (n > 3) must pivot.
    "M4": (
        [[0.0, 2.0, 1.0, 0.5], [1.5, 1.0, 0.3, 2.0], [0.4, 0.6, 3.0, 1.0], [2.0, 0.1, 0.8, 1.2]],
        [[0.0, 0.5, 0.0, 0.0], [0.3, 0.0, 0.0, 1.0], [0.0, 0.0, 0.2, 0.0], [0.0, 0.4, 0.0, 0.0]],
        [[1.0, 0.0, 0.0, 0.3], [0.0, 0.0, 0.7, 0.0], [0.5, 0.0, 0.0, 0.0], [0.0, 0.0, 0.0, 0.6]],
        [[0.2, 0.0, 0.1, 0.0], [0.0, 0.3, 0.0, 0.0], [0.0, 0.0, 0.0, 0.4], [0.1, 0.0, 0.0, 0.0]],
    ),
    "b2": (
        [[1.0], [2.0]],
        [[0.5], [0.0]],
        [[0.0], [1.0]],
        [[0.2], [0.0]],
    ),
    "b3": (
        [[1.0], [-1.0], [2.0]],
        [[0.0], [0.5], [0.0]],
        [[1.0], [0.0], [0.0]],
        [[0.0], [0.0], [0.3]],
    ),
    "v": (
        [[3.0], [4.0], [1.5]],
        [[1.0], [0.0], [0.5]],
        [[0.0], [2.0], [0.0]],
        [[0.0], [0.0], [0.4]],
    ),
}

# Scalar OTI operand s(x, y) = S0 + x S1 + y S2 + x y S3.
SCALAR = (1.5, 0.5, -0.25, 0.1)

# Real (dmat) operand.
REAL_MATRIX = [[1.0, 2.0], [3.0, 4.0]]


# ********************************************************************************************************
def _directions(max_order=ORDER):
    """
    Lists every bivariate derivative direction up to a total order, including the real part.

    Parameters
    ----------
    max_order : int
        Maximum total order ``a + b``.

    Returns
    -------
    list of tuple
        Pairs ``(a, b)`` with ``0 <= a + b <= max_order``.

    Examples
    --------
    >>> _directions(1)
    [(0, 0), (0, 1), (1, 0)]
    """
    return [(a, b) for a in range(max_order + 1) for b in range(max_order + 1 - a)]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _humdir(a, b):
    """
    Builds the human-readable imaginary direction for d^(a+b) / dx^a dy^b.

    Parameters
    ----------
    a : int
        Derivative order along basis 1 (x).
    b : int
        Derivative order along basis 2 (y).

    Returns
    -------
    list
        Direction in the ``[[basis, exponent], ...]`` format accepted by ``get_deriv``.

    Examples
    --------
    >>> _humdir(1, 3)
    [[1, 1], [2, 3]]
    """
    return [[basis, exp] for basis, exp in ((1, a), (2, b)) if exp > 0]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _oti_value(obj, a, b):
    """
    Extracts the real part or the derivative d^(a+b) / dx^a dy^b of an OTI object.

    Parameters
    ----------
    obj : matso or sotinum
        OTI array or scalar.
    a : int
        Derivative order along x.
    b : int
        Derivative order along y.

    Returns
    -------
    numpy.ndarray
        Real part (``a = b = 0``) or derivative, as a float array (0-d for scalars).

    Examples
    --------
    >>> _oti_value(oti.number(2.0), 0, 0)
    array(2.)
    """

    if a == 0 and b == 0:

        value = obj.real

    else:

        value = obj.get_deriv(_humdir(a, b))

    # end if

    return np.asarray(value, dtype=float)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sym_q():
    """
    Returns the nonlinear polynomial ``q(x, y) = x y + x^3 + x^2 y^2 + y^4`` multiplying A3.

    Returns
    -------
    sympy.Expr
        Polynomial in ``X_SYM`` and ``Y_SYM``.

    Examples
    --------
    >>> sympy.Poly(_sym_q(), X_SYM, Y_SYM).total_degree()
    4
    """
    return X_SYM * Y_SYM + X_SYM**3 + X_SYM**2 * Y_SYM**2 + Y_SYM**4

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _oti_matrix(name):
    """
    Builds the OTI array ``A0 + x A1 + y A2 + q(x, y) A3`` for an entry of ``MATRICES``.

    Parameters
    ----------
    name : str
        Key in ``MATRICES``.

    Returns
    -------
    matso
        OTI array truncated at ``ORDER``.

    Examples
    --------
    >>> _oti_matrix("A").shape
    (2, 2)
    """
    a0, a1, a2, a3 = MATRICES[name]
    x = oti.e(1, order=ORDER)
    y = oti.e(2, order=ORDER)

    q = x * y + x**3 + (x * y)**2 + y**4

    return oti.array(a0) + x * oti.array(a1) + y * oti.array(a2) + q * oti.array(a3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sym_matrix(name):
    """
    Builds the sympy matrix ``A0 + x A1 + y A2 + q(x, y) A3`` for an entry of ``MATRICES``.

    Parameters
    ----------
    name : str
        Key in ``MATRICES``.

    Returns
    -------
    sympy.Matrix
        Symbolic matrix in ``X_SYM`` and ``Y_SYM``.

    Examples
    --------
    >>> _sym_matrix("M1").shape
    (1, 1)
    """
    a0, a1, a2, a3 = (sympy.Matrix(part) for part in MATRICES[name])

    return a0 + X_SYM * a1 + Y_SYM * a2 + _sym_q() * a3

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _oti_scalar():
    """
    Builds the OTI scalar operand ``s(x, y)`` from ``SCALAR``.

    Returns
    -------
    sotinum
        OTI number truncated at ``ORDER``.

    Examples
    --------
    >>> _oti_scalar().real
    1.5
    """
    s0, s1, s2, s3 = SCALAR
    x = oti.e(1, order=ORDER)
    y = oti.e(2, order=ORDER)

    return s0 + s1 * x + s2 * y + s3 * (x * y)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sym_scalar():
    """
    Builds the sympy expression of the scalar operand ``s(x, y)``.

    Returns
    -------
    sympy.Expr
        Symbolic scalar in ``X_SYM`` and ``Y_SYM``.

    Examples
    --------
    >>> _sym_scalar().subs({X_SYM: 0, Y_SYM: 0})
    1.50000000000000
    """
    s0, s1, s2, s3 = SCALAR

    return s0 + s1 * X_SYM + s2 * Y_SYM + s3 * X_SYM * Y_SYM

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _oti_operands():
    """
    Builds every OTI operand used by the operation tables.

    Returns
    -------
    dict
        Maps operand names (``MATRICES`` keys, ``"s"``, ``"R"``) to OTI / dmat objects.

    Examples
    --------
    >>> sorted(_oti_operands())[:2]
    ['A', 'B']
    """
    operands = {name: _oti_matrix(name) for name in MATRICES}
    operands["s"] = _oti_scalar()
    operands["R"] = real.array(REAL_MATRIX)

    return operands

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sym_operands():
    """
    Builds the sympy counterpart of every operand returned by ``_oti_operands``.

    Returns
    -------
    dict
        Maps operand names to sympy matrices / expressions.

    Examples
    --------
    >>> _sym_operands()["R"].shape
    (2, 2)
    """
    operands = {name: _sym_matrix(name) for name in MATRICES}
    operands["s"] = _sym_scalar()
    operands["R"] = sympy.Matrix(REAL_MATRIX)

    return operands

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sym_elementwise(func, *args):
    """
    Applies a scalar sympy function elementwise, broadcasting scalars against matrices.

    Parameters
    ----------
    func : callable
        Function of ``len(args)`` sympy scalars.
    *args : sympy.Matrix or sympy.Expr or float
        Operands; all matrices must share the same shape.

    Returns
    -------
    sympy.Matrix
        Matrix with ``func`` applied to each entry.

    Examples
    --------
    >>> _sym_elementwise(operator.add, sympy.Matrix([[1, 2]]), 1)
    Matrix([[2, 3]])
    """
    shape = next(arg.shape for arg in args if isinstance(arg, sympy.MatrixBase))

    # ****************************************************************************************************
    def entry(i, j):
        """
        Evaluates ``func`` at entry ``(i, j)``.

        Parameters
        ----------
        i : int
            Row index.
        j : int
            Column index.

        Returns
        -------
        sympy.Expr
            Value of the entry.

        Examples
        --------
        >>> entry(0, 0)  # doctest: +SKIP
        2
        """
        values = [arg[i, j] if isinstance(arg, sympy.MatrixBase) else arg for arg in args]

        return func(*values)

    # end function
    # ----------------------------------------------------------------------------------------------------

    return sympy.Matrix(shape[0], shape[1], entry)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sym_derivs(expr):
    """
    Computes the reference real part and derivatives of a symbolic result at (0, 0).

    Parameters
    ----------
    expr : sympy.Matrix or sympy.Expr
        Symbolic result in ``X_SYM`` and ``Y_SYM``.

    Returns
    -------
    dict
        Maps ``(a, b)`` to a float array with d^(a+b) expr / dx^a dy^b at (0, 0), for all
        ``a + b <= ORDER`` (``(0, 0)`` is the real part).

    Examples
    --------
    >>> _sym_derivs(X_SYM**2)[(2, 0)]
    array(2.)
    """
    is_matrix = isinstance(expr, sympy.MatrixBase)
    entries = list(expr) if is_matrix else [expr]
    shape = expr.shape if is_matrix else ()
    point = {X_SYM: 0, Y_SYM: 0}
    derivs = {(a, b): [] for a, b in _directions()}

    for entry in entries:

        dx = entry

        for a in range(ORDER + 1):

            dxy = dx

            for b in range(ORDER + 1 - a):

                derivs[(a, b)].append(float(dxy.subs(point).evalf(30)))
                dxy = sympy.diff(dxy, Y_SYM)

            # end for

            dx = sympy.diff(dx, X_SYM)

        # end for

    # end for

    return {key: np.array(values).reshape(shape) for key, values in derivs.items()}

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_matches_sympy(result, expr, label):
    """
    Asserts that an OTI result matches every derivative of a symbolic reference.

    Parameters
    ----------
    result : matso or sotinum
        OTI result under test.
    expr : sympy.Matrix or sympy.Expr or dict
        Symbolic reference, or its precomputed ``_sym_derivs`` dictionary.
    label : str
        Name used in assertion messages.

    Examples
    --------
    >>> _assert_matches_sympy(oti.number(2.0), sympy.Integer(2), "two")
    """
    derivs = expr if isinstance(expr, dict) else _sym_derivs(expr)

    for (a, b), ref in derivs.items():

        np.testing.assert_allclose(
            _oti_value(result, a, b), ref, rtol=REL_TOL, atol=ABS_TOL,
            err_msg=f"{label}: d^{a + b} / dx^{a} dy^{b}",
        )

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_oti_equal(result, expected, label):
    """
    Asserts that two OTI objects agree in the real part and every derivative up to ``ORDER``.

    Parameters
    ----------
    result : matso or sotinum
        OTI result under test.
    expected : matso or sotinum or numpy.ndarray
        Reference OTI object, or an object array of ``sotinum`` with the same shape as ``result``.
    label : str
        Name used in assertion messages.

    Examples
    --------
    >>> _assert_oti_equal(oti.number(2.0), oti.number(2.0), "two")
    """

    for a, b in _directions():

        if isinstance(expected, np.ndarray):

            ref = np.vectorize(lambda num: float(_oti_value(num, a, b)))(expected)

        else:

            ref = _oti_value(expected, a, b)

        # end if

        np.testing.assert_allclose(
            _oti_value(result, a, b), ref, rtol=REL_TOL, atol=ABS_TOL,
            err_msg=f"{label}: d^{a + b} / dx^{a} dy^{b}",
        )

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _max_coeff(obj, a, b):
    """
    Largest absolute value of the real part (``a = b = 0``) or of d^(a+b) / dx^a dy^b of an OTI
    object.

    Parameters
    ----------
    obj : matso or sotinum
        OTI array or scalar.
    a : int
        Derivative order along x.
    b : int
        Derivative order along y.

    Returns
    -------
    float
        Maximum over every entry.

    Examples
    --------
    >>> _max_coeff(oti.array([[1.0, -3.0]]), 0, 0)
    3.0
    """
    return float(np.max(np.abs(_oti_value(obj, a, b))))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _product_scale(lhs, rhs, a, b):
    """
    Magnitude of the terms of d^(a+b) (lhs rhs) / dx^a dy^b, the scale of its rounding error.

    By the Leibniz rule the derivative is the sum over a' <= a, b' <= b of
    C(a, a') C(b, b') lhs_(a-a', b-b') rhs_(a', b'); each term is bounded by the largest entries
    times the inner dimension.

    Parameters
    ----------
    lhs : matso
        Left factor.
    rhs : matso
        Right factor.
    a : int
        Derivative order along x.
    b : int
        Derivative order along y.

    Returns
    -------
    float
        ``ncols(lhs) * sum C(a, a') C(b, b') max|lhs_(a-a', b-b')| max|rhs_(a', b')|``.

    Examples
    --------
    >>> _product_scale(oti.eye(2), oti.eye(2), 0, 0)
    2.0
    """
    return lhs.shape[1] * sum(
        math.comb(a, ap) * math.comb(b, bp) * _max_coeff(lhs, a - ap, b - bp) * _max_coeff(rhs, ap, bp)
        for ap in range(a + 1) for bp in range(b + 1)
    )

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_product_residual(lhs, rhs, expected, label):
    """
    Asserts ``lhs rhs = expected`` in every direction, each within ``RES_TOL`` times the scale of
    the terms that cancel in that direction (``_product_scale``).

    Parameters
    ----------
    lhs : matso
        Left factor.
    rhs : matso
        Right factor.
    expected : matso
        Expected product.
    label : str
        Name used in assertion messages.

    Examples
    --------
    >>> _assert_product_residual(oti.eye(2), oti.eye(2), oti.eye(2), "I I")
    """
    residual = oti.dot(lhs, rhs) - expected

    for a, b in _directions():

        np.testing.assert_array_less(
            np.abs(_oti_value(residual, a, b)), RES_TOL * max(1.0, _product_scale(lhs, rhs, a, b)),
            err_msg=f"{label}: d^{a + b} / dx^{a} dy^{b}",
        )

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _entries(arr):
    """
    Returns the entries of an OTI array as an object array of ``sotinum``.

    Parameters
    ----------
    arr : matso
        OTI array.

    Returns
    -------
    numpy.ndarray
        Object array with ``arr[i, j]`` at position ``(i, j)``.

    Examples
    --------
    >>> _entries(oti.zeros((2, 3))).shape
    (2, 3)
    """
    nrows, ncols = arr.shape
    out = np.empty((nrows, ncols), dtype=object)

    for i in range(nrows):

        for j in range(ncols):

            out[i, j] = arr[i, j]

        # end for

    # end for

    return out

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _map_entries(func, arr):
    """
    Applies a scalar OTI function to every entry of an OTI array.

    Parameters
    ----------
    func : callable
        Function of one ``sotinum``.
    arr : matso
        OTI array.

    Returns
    -------
    numpy.ndarray
        Object array with ``func(arr[i, j])`` at position ``(i, j)``.

    Examples
    --------
    >>> _map_entries(oti.sin, oti.zeros((1, 2))).shape
    (1, 2)
    """
    return np.vectorize(func, otypes=[object])(_entries(arr))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _stale_holder(shape):
    """
    Creates an output holder prefilled with nonzero coefficients in every direction up to ORDER.

    Used to check that ``out=`` paths overwrite, rather than accumulate into, the holder.

    Parameters
    ----------
    shape : tuple or None
        Shape of the holder array, or None for a scalar (``sotinum``) holder.

    Returns
    -------
    matso or sotinum
        Holder filled with ``exp(0.3 + e1 + 2 e2)`` in every entry.

    Examples
    --------
    >>> _stale_holder((1, 2)).shape
    (1, 2)
    """
    stale = oti.exp(0.3 + oti.e(1, order=ORDER) + 2.0 * oti.e(2, order=ORDER))

    return stale if shape is None else oti.ones(shape) * stale

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _iadd(lhs, rhs):
    """
    Applies ``+=`` to a copy of ``lhs``.

    Parameters
    ----------
    lhs : matso
        Left operand (not modified).
    rhs : object
        Right operand.

    Returns
    -------
    matso
        ``lhs + rhs`` computed through ``__iadd__``.

    Examples
    --------
    >>> _iadd(oti.ones((1, 1)), 1.0).real
    array([[2.]])
    """
    res = lhs.copy()
    res += rhs

    return res

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _isub(lhs, rhs):
    """
    Applies ``-=`` to a copy of ``lhs``.

    Parameters
    ----------
    lhs : matso
        Left operand (not modified).
    rhs : object
        Right operand.

    Returns
    -------
    matso
        ``lhs - rhs`` computed through ``__isub__``.

    Examples
    --------
    >>> _isub(oti.ones((1, 1)), 1.0).real
    array([[0.]])
    """
    res = lhs.copy()
    res -= rhs

    return res

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _imul(lhs, rhs):
    """
    Applies ``*=`` to a copy of ``lhs``.

    Parameters
    ----------
    lhs : matso
        Left operand (not modified).
    rhs : object
        Right operand.

    Returns
    -------
    matso
        ``lhs * rhs`` computed through ``__imul__``.

    Examples
    --------
    >>> _imul(oti.ones((1, 1)), 2.0).real
    array([[2.]])
    """
    res = lhs.copy()
    res *= rhs

    return res

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _with_out(func, shape):
    """
    Wraps a module function so that it writes into a prefilled (stale) ``out`` holder.

    Parameters
    ----------
    func : callable
        Function accepting an ``out`` keyword.
    shape : tuple or None
        Shape of the ``out`` array, or None for a scalar (``sotinum``) output.

    Returns
    -------
    callable
        Function with the same positional arguments that returns the filled ``out`` object.

    Examples
    --------
    >>> _with_out(oti.transpose, (1, 1))(oti.ones((1, 1))).real
    array([[1.]])
    """

    # ****************************************************************************************************
    def wrapped(*args):
        """
        Calls ``func(*args, out=out)`` and returns ``out``.

        Parameters
        ----------
        *args : object
            Positional arguments of ``func``.

        Returns
        -------
        matso or sotinum
            The filled output holder.

        Examples
        --------
        >>> wrapped(oti.ones((1, 1)))  # doctest: +SKIP
        """
        out = _stale_holder(shape)
        ret = func(*args, out=out)
        assert ret is None, "functions called with out= must return None"

        return out

    # end function
    # ----------------------------------------------------------------------------------------------------

    return wrapped

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------
# Elementwise arithmetic.
# ------------------------------------------------------------------------------------------------

# (id, oti operation on the operand dict, sympy operation on the operand dict)
ARITHMETIC = [
    ("add_OO", lambda o: o["A"] + o["B"], lambda o: o["A"] + o["B"]),
    ("sub_OO", lambda o: o["A"] - o["B"], lambda o: o["A"] - o["B"]),
    ("mul_OO", lambda o: o["A"] * o["B"],
     lambda o: _sym_elementwise(operator.mul, o["A"], o["B"])),
    ("div_OO", lambda o: o["A"] / o["B"],
     lambda o: _sym_elementwise(operator.truediv, o["A"], o["B"])),
    ("add_Or", lambda o: o["A"] + CONST, lambda o: _sym_elementwise(operator.add, o["A"], CONST)),
    ("add_rO", lambda o: CONST + o["A"], lambda o: _sym_elementwise(operator.add, CONST, o["A"])),
    ("sub_Or", lambda o: o["A"] - CONST, lambda o: _sym_elementwise(operator.sub, o["A"], CONST)),
    ("sub_rO", lambda o: CONST - o["A"], lambda o: _sym_elementwise(operator.sub, CONST, o["A"])),
    ("mul_Or", lambda o: o["A"] * CONST, lambda o: o["A"] * CONST),
    ("mul_rO", lambda o: CONST * o["A"], lambda o: CONST * o["A"]),
    ("div_Or", lambda o: o["A"] / CONST, lambda o: o["A"] / CONST),
    ("div_rO", lambda o: CONST / o["A"],
     lambda o: _sym_elementwise(operator.truediv, CONST, o["A"])),
    ("add_Oo", lambda o: o["A"] + o["s"], lambda o: _sym_elementwise(operator.add, o["A"], o["s"])),
    ("add_oO", lambda o: o["s"] + o["A"], lambda o: _sym_elementwise(operator.add, o["s"], o["A"])),
    ("sub_Oo", lambda o: o["A"] - o["s"], lambda o: _sym_elementwise(operator.sub, o["A"], o["s"])),
    ("sub_oO", lambda o: o["s"] - o["A"], lambda o: _sym_elementwise(operator.sub, o["s"], o["A"])),
    ("mul_Oo", lambda o: o["A"] * o["s"], lambda o: o["A"] * o["s"]),
    ("mul_oO", lambda o: o["s"] * o["A"], lambda o: o["s"] * o["A"]),
    ("div_Oo", lambda o: o["A"] / o["s"],
     lambda o: _sym_elementwise(operator.truediv, o["A"], o["s"])),
    ("div_oO", lambda o: o["s"] / o["A"],
     lambda o: _sym_elementwise(operator.truediv, o["s"], o["A"])),
    ("add_OR", lambda o: o["A"] + o["R"], lambda o: o["A"] + o["R"]),
    ("add_RO", lambda o: o["R"] + o["A"], lambda o: o["R"] + o["A"]),
    ("sub_OR", lambda o: o["A"] - o["R"], lambda o: o["A"] - o["R"]),
    ("sub_RO", lambda o: o["R"] - o["A"], lambda o: o["R"] - o["A"]),
    ("mul_OR", lambda o: o["A"] * o["R"],
     lambda o: _sym_elementwise(operator.mul, o["A"], o["R"])),
    ("mul_RO", lambda o: o["R"] * o["A"],
     lambda o: _sym_elementwise(operator.mul, o["R"], o["A"])),
    ("div_OR", lambda o: o["A"] / o["R"],
     lambda o: _sym_elementwise(operator.truediv, o["A"], o["R"])),
    ("div_RO", lambda o: o["R"] / o["A"],
     lambda o: _sym_elementwise(operator.truediv, o["R"], o["A"])),
    ("neg", lambda o: -o["A"], lambda o: -o["A"]),
    ("neg_func", lambda o: oti.neg(o["A"]), lambda o: -o["A"]),
    ("iadd_OO", lambda o: _iadd(o["A"], o["B"]), lambda o: o["A"] + o["B"]),
    ("iadd_Or", lambda o: _iadd(o["A"], CONST),
     lambda o: _sym_elementwise(operator.add, o["A"], CONST)),
    ("isub_OO", lambda o: _isub(o["A"], o["B"]), lambda o: o["A"] - o["B"]),
    ("imul_OO", lambda o: _imul(o["A"], o["B"]),
     lambda o: _sym_elementwise(operator.mul, o["A"], o["B"])),
    ("imul_Oo", lambda o: _imul(o["A"], o["s"]), lambda o: o["A"] * o["s"]),
    ("sum_func_OO", lambda o: oti.sum(o["A"], o["B"]), lambda o: o["A"] + o["B"]),
    ("sum_func_rO", lambda o: oti.sum(CONST, o["A"]),
     lambda o: _sym_elementwise(operator.add, CONST, o["A"])),
    ("sub_func_OO", lambda o: oti.sub(o["A"], o["B"]), lambda o: o["A"] - o["B"]),
    ("sub_func_Or", lambda o: oti.sub(o["A"], CONST),
     lambda o: _sym_elementwise(operator.sub, o["A"], CONST)),
    ("mul_func_OO", lambda o: oti.mul(o["A"], o["B"]),
     lambda o: _sym_elementwise(operator.mul, o["A"], o["B"])),
    ("mul_func_oO", lambda o: oti.mul(o["s"], o["A"]), lambda o: o["s"] * o["A"]),
    ("div_func_OO", lambda o: oti.div(o["A"], o["B"]),
     lambda o: _sym_elementwise(operator.truediv, o["A"], o["B"])),
    ("div_func_Oo", lambda o: oti.div(o["A"], o["s"]),
     lambda o: _sym_elementwise(operator.truediv, o["A"], o["s"])),
    ("sum_out", lambda o: _with_out(oti.sum, (2, 2))(o["A"], o["B"]), lambda o: o["A"] + o["B"]),
    ("sub_out", lambda o: _with_out(oti.sub, (2, 2))(o["A"], o["B"]), lambda o: o["A"] - o["B"]),
    ("mul_out", lambda o: _with_out(oti.mul, (2, 2))(o["A"], o["B"]),
     lambda o: _sym_elementwise(operator.mul, o["A"], o["B"])),
    ("div_out", lambda o: _with_out(oti.div, (2, 2))(o["A"], o["B"]),
     lambda o: _sym_elementwise(operator.truediv, o["A"], o["B"])),
    ("sum_out_rO", lambda o: _with_out(oti.sum, (2, 2))(CONST, o["A"]),
     lambda o: _sym_elementwise(operator.add, CONST, o["A"])),
    ("sum_out_oO", lambda o: _with_out(oti.sum, (2, 2))(o["s"], o["A"]),
     lambda o: _sym_elementwise(operator.add, o["s"], o["A"])),
    ("sub_out_Or", lambda o: _with_out(oti.sub, (2, 2))(o["A"], CONST),
     lambda o: _sym_elementwise(operator.sub, o["A"], CONST)),
    ("sub_out_OR", lambda o: _with_out(oti.sub, (2, 2))(o["A"], o["R"]), lambda o: o["A"] - o["R"]),
    ("mul_out_oO", lambda o: _with_out(oti.mul, (2, 2))(o["s"], o["A"]), lambda o: o["s"] * o["A"]),
    ("mul_out_RO", lambda o: _with_out(oti.mul, (2, 2))(o["R"], o["A"]),
     lambda o: _sym_elementwise(operator.mul, o["R"], o["A"])),
    ("div_out_Oo", lambda o: _with_out(oti.div, (2, 2))(o["A"], o["s"]),
     lambda o: _sym_elementwise(operator.truediv, o["A"], o["s"])),
    ("div_out_rO", lambda o: _with_out(oti.div, (2, 2))(CONST, o["A"]),
     lambda o: _sym_elementwise(operator.truediv, CONST, o["A"])),
    ("matso_add_static", lambda o: oti.matso.add(o["A"], o["B"]), lambda o: o["A"] + o["B"]),
    ("matso_add_static_out", lambda o: _with_out(oti.matso.add, (2, 2))(o["A"], o["B"]),
     lambda o: o["A"] + o["B"]),
]

# ------------------------------------------------------------------------------------------------
# Powers.
# ------------------------------------------------------------------------------------------------

POWERS = [
    ("pow_int", lambda o: o["A"]**3, lambda o: _sym_elementwise(lambda v: v**3, o["A"])),
    ("pow_neg_int", lambda o: o["A"]**-1, lambda o: _sym_elementwise(lambda v: 1 / v, o["A"])),
    ("pow_real", lambda o: o["A"]**2.5,
     lambda o: _sym_elementwise(lambda v: v**sympy.Rational(5, 2), o["A"])),
    ("pow_sotinum", lambda o: o["A"]**o["s"],
     lambda o: _sym_elementwise(operator.pow, o["A"], o["s"])),
    ("pow_matso", lambda o: o["A"]**o["B"],
     lambda o: _sym_elementwise(operator.pow, o["A"], o["B"])),
    ("pow_func_real", lambda o: oti.pow(o["A"], 2.5),
     lambda o: _sym_elementwise(lambda v: v**sympy.Rational(5, 2), o["A"])),
    ("pow_func_sotinum", lambda o: oti.pow(o["A"], o["s"]),
     lambda o: _sym_elementwise(operator.pow, o["A"], o["s"])),
    ("pow_func_matso", lambda o: oti.pow(o["A"], o["B"]),
     lambda o: _sym_elementwise(operator.pow, o["A"], o["B"])),
    ("pow_func_real_out", lambda o: _with_out(oti.pow, (2, 2))(o["A"], 2.5),
     lambda o: _sym_elementwise(lambda v: v**sympy.Rational(5, 2), o["A"])),
    ("pow_func_sotinum_out", lambda o: _with_out(oti.pow, (2, 2))(o["A"], o["s"]),
     lambda o: _sym_elementwise(operator.pow, o["A"], o["s"])),
    ("pow_func_matso_out", lambda o: _with_out(oti.pow, (2, 2))(o["A"], o["B"]),
     lambda o: _sym_elementwise(operator.pow, o["A"], o["B"])),
    ("pow_func_scalar_base", lambda o: oti.pow(o["s"], o["A"]),
     lambda o: _sym_elementwise(operator.pow, o["s"], o["A"])),
    ("pow_func_scalar_base_out", lambda o: _with_out(oti.pow, (2, 2))(o["s"], o["A"]),
     lambda o: _sym_elementwise(operator.pow, o["s"], o["A"])),
]

# ------------------------------------------------------------------------------------------------
# Linear algebra.
# ------------------------------------------------------------------------------------------------

LINALG = [
    ("dot_square", lambda o: oti.dot(o["A"], o["B"]), lambda o: o["A"] * o["B"]),
    ("dot_nonsquare_CD", lambda o: oti.dot(o["C"], o["D"]), lambda o: o["C"] * o["D"]),
    ("dot_nonsquare_DC", lambda o: oti.dot(o["D"], o["C"]), lambda o: o["D"] * o["C"]),
    ("dot_matvec", lambda o: oti.dot(o["M3"], o["b3"]), lambda o: o["M3"] * o["b3"]),
    ("dot_out", lambda o: _with_out(oti.dot, (2, 2))(o["A"], o["B"]), lambda o: o["A"] * o["B"]),
    ("dot_static", lambda o: oti.matso.dot(o["A"], o["B"]), lambda o: o["A"] * o["B"]),
    ("dot_OR", lambda o: oti.dot(o["A"], o["R"]), lambda o: o["A"] * o["R"]),
    ("dot_RO", lambda o: oti.dot(o["R"], o["A"]), lambda o: o["R"] * o["A"]),
    ("matmul_OO", lambda o: o["A"] @ o["B"], lambda o: o["A"] * o["B"]),
    ("matmul_OR", lambda o: o["A"] @ o["R"], lambda o: o["A"] * o["R"]),
    ("matmul_RO", lambda o: o["R"] @ o["A"], lambda o: o["R"] * o["A"]),
    ("dot_static_out", lambda o: _with_out(oti.matso.dot, (2, 2))(o["A"], o["B"]),
     lambda o: o["A"] * o["B"]),
    ("dot_product_OO", lambda o: oti.dot_product(o["A"], o["B"]),
     lambda o: sum(_sym_elementwise(operator.mul, o["A"], o["B"]))),
    ("dot_product_OR", lambda o: oti.dot_product(o["A"], o["R"]),
     lambda o: sum(_sym_elementwise(operator.mul, o["A"], o["R"]))),
    ("dot_product_RO", lambda o: oti.dot_product(o["R"], o["A"]),
     lambda o: sum(_sym_elementwise(operator.mul, o["R"], o["A"]))),
    ("dot_product_out", lambda o: _with_out(oti.dot_product, None)(o["A"], o["B"]),
     lambda o: sum(_sym_elementwise(operator.mul, o["A"], o["B"]))),
    ("dot_product_row_col", lambda o: oti.dot_product(oti.transpose(o["v"]), o["b3"]),
     lambda o: o["v"].dot(o["b3"])),
    ("dot_product_vec", lambda o: oti.dot_product(o["v"], o["b3"]), lambda o: o["v"].dot(o["b3"])),
    ("transpose_square", lambda o: oti.transpose(o["A"]), lambda o: o["A"].T),
    ("transpose_nonsquare", lambda o: oti.transpose(o["C"]), lambda o: o["C"].T),
    ("transpose_attr", lambda o: o["C"].T, lambda o: o["C"].T),
    ("transpose_out", lambda o: _with_out(oti.transpose, (3, 2))(o["C"]), lambda o: o["C"].T),
    ("transpose_static", lambda o: oti.matso.transpose(o["C"]), lambda o: o["C"].T),
    ("transpose_static_out", lambda o: _with_out(oti.matso.transpose, (3, 2))(o["C"]),
     lambda o: o["C"].T),
    ("det_1x1", lambda o: oti.det(o["M1"]), lambda o: o["M1"].det()),
    ("det_2x2", lambda o: oti.det(o["A"]), lambda o: o["A"].det()),
    ("det_3x3", lambda o: oti.det(o["M3"]), lambda o: o["M3"].det()),
    ("det_out", lambda o: _with_out(oti.det, None)(o["M3"]), lambda o: o["M3"].det()),
    # Berkowitz is division-free: the default (Bareiss) divides by the symbolic pivot M4[0, 0],
    # which vanishes at (0, 0), and evaluates to NaN there.
    ("det_4x4", lambda o: oti.det(o["M4"]), lambda o: o["M4"].det(method="berkowitz")),
    ("det_4x4_out", lambda o: _with_out(oti.det, None)(o["M4"]),
     lambda o: o["M4"].det(method="berkowitz")),
    ("norm_default", lambda o: oti.norm(o["A"]), lambda o: _sym_pnorm(o["A"], 2)),
    ("norm_p1", lambda o: oti.norm(o["A"], 1.0), lambda o: _sym_pnorm(o["A"], 1)),
    ("norm_p3", lambda o: oti.norm(o["A"], 3.0), lambda o: _sym_pnorm(o["A"], 3)),
    ("norm_mixed_sign_p1", lambda o: oti.norm(o["N"], 1.0), lambda o: _sym_pnorm(o["N"], 1)),
    ("norm_mixed_sign_p2", lambda o: oti.norm(o["N"]), lambda o: _sym_pnorm(o["N"], 2)),
    ("norm_mixed_sign_p3", lambda o: oti.norm(o["N"], 3.0), lambda o: _sym_pnorm(o["N"], 3)),
    ("norm_vec", lambda o: oti.norm(o["v"]), lambda o: _sym_pnorm(o["v"], 2)),
    ("norm_out", lambda o: _with_out(oti.norm, None)(o["v"], 3.0),
     lambda o: _sym_pnorm(o["v"], 3)),
    ("inv_1x1", lambda o: oti.inv(o["M1"]), lambda o: o["M1"].inv()),
    ("inv_2x2", lambda o: oti.inv(o["A"]), lambda o: o["A"].inv()),
    ("inv_3x3", lambda o: oti.inv(o["M3"]), lambda o: o["M3"].inv()),
    ("inv_out", lambda o: _with_out(oti.inv, (3, 3))(o["M3"]), lambda o: o["M3"].inv()),
    ("inv_static", lambda o: oti.matso.inv(o["A"]), lambda o: o["A"].inv()),
    ("inv_static_out", lambda o: _with_out(oti.matso.inv, (2, 2))(o["A"]),
     lambda o: o["A"].inv()),
    ("inv_block_2x2", lambda o: oti.inv_block(o["A"]), lambda o: o["A"].inv()),
    ("inv_block_3x3", lambda o: oti.inv_block(o["M3"]), lambda o: o["M3"].inv()),
    ("solve_2x2", lambda o: oti.solve(o["A"], o["b2"]), lambda o: o["A"].LUsolve(o["b2"])),
    ("solve_3x3", lambda o: oti.solve(o["M3"], o["b3"]), lambda o: o["M3"].LUsolve(o["b3"])),
    ("solve_out", lambda o: _with_out(oti.solve, (3, 1))(o["M3"], o["b3"]),
     lambda o: o["M3"].LUsolve(o["b3"])),
]

# ********************************************************************************************************
def _sym_abs(value):
    """
    Returns ``|value|`` as a polynomial valid near (0, 0), assuming ``value(0, 0) != 0``.

    Differentiating ``sympy.Abs`` directly produces ``sign`` terms; resolving the sign at the
    expansion point keeps the reference a plain analytic expression.

    Parameters
    ----------
    value : sympy.Expr
        Expression in ``X_SYM`` and ``Y_SYM``.

    Returns
    -------
    sympy.Expr
        ``value`` or ``-value``, whichever is positive at (0, 0).

    Examples
    --------
    >>> _sym_abs(-2 + X_SYM)
    2 - x
    """
    return value if value.subs({X_SYM: 0, Y_SYM: 0}) > 0 else -value

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sym_pnorm(mat, p):
    """
    Symbolic elementwise p-norm ``(sum |a_ij|^p)^(1/p)``, the definition used by ``oti.norm``.

    Parameters
    ----------
    mat : sympy.Matrix
        Symbolic matrix; no entry may vanish at (0, 0).
    p : int
        Norm exponent.

    Returns
    -------
    sympy.Expr
        Symbolic norm.

    Examples
    --------
    >>> _sym_pnorm(sympy.Matrix([[3, -4]]), 2)
    5
    """
    return sum(_sym_abs(v)**p for v in mat)**sympy.Rational(1, p)

# end function
# --------------------------------------------------------------------------------------------------------


SYMPY_CASES = {name: sym_op for name, _, sym_op in ARITHMETIC + POWERS + LINALG}


# ********************************************************************************************************
@functools.lru_cache(maxsize=None)
def _reference(name):
    """
    Computes (and caches) the sympy reference derivatives of a named operation.

    Parameters
    ----------
    name : str
        Case id in ``ARITHMETIC``, ``POWERS`` or ``LINALG``.

    Returns
    -------
    dict
        Output of ``_sym_derivs`` for the symbolic result.

    Examples
    --------
    >>> _reference("add_OO")[(0, 0)].shape
    (2, 2)
    """
    return _sym_derivs(SYMPY_CASES[name](_sym_operands()))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _case_params(cases):
    """
    Converts an operation table into pytest parameters.

    Parameters
    ----------
    cases : list of tuple
        Entries ``(name, oti_op, sym_op)``.

    Returns
    -------
    list
        ``pytest.param(name, oti_op, id=name)`` for each entry.

    Examples
    --------
    >>> len(_case_params(POWERS)) == len(POWERS)
    True
    """
    return [pytest.param(name, oti_op, id=name) for name, oti_op, _ in cases]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name, oti_op", _case_params(ARITHMETIC))
def test_elementwise_arithmetic(name, oti_op):
    """
    Test elementwise arithmetic between arrays, scalars and real arrays against sympy.

    Parameters
    ----------
    name : str
        Case id, also used in assertion messages.
    oti_op : callable
        OTI operation applied to the ``_oti_operands()`` dict.
    """
    _assert_matches_sympy(oti_op(_oti_operands()), _reference(name), name)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name, oti_op", _case_params(POWERS))
def test_elementwise_powers(name, oti_op):
    """
    Test elementwise powers with integer, real, OTI scalar and OTI array exponents.

    Parameters
    ----------
    name : str
        Case id, also used in assertion messages.
    oti_op : callable
        OTI operation applied to the ``_oti_operands()`` dict.
    """
    _assert_matches_sympy(oti_op(_oti_operands()), _reference(name), name)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name, oti_op", _case_params(LINALG))
def test_linear_algebra(name, oti_op):
    """
    Test dot, dot_product, transpose, det, norm, inv and solve against sympy.

    Parameters
    ----------
    name : str
        Case id, also used in assertion messages.
    oti_op : callable
        OTI operation applied to the ``_oti_operands()`` dict.
    """
    _assert_matches_sympy(oti_op(_oti_operands()), _reference(name), name)

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------
# Elementwise math functions: array result vs scalar function applied per entry.
# ------------------------------------------------------------------------------------------------

# (name, function accepting out=, base value of the array entries)
MATH_FUNCTIONS = [
    ("sin", oti.sin, 0.7),
    ("cos", oti.cos, 0.7),
    ("tan", oti.tan, 0.7),
    ("asin", oti.asin, 0.3),
    ("acos", oti.acos, 0.3),
    ("atan", oti.atan, 0.3),
    ("sinh", oti.sinh, 0.7),
    ("cosh", oti.cosh, 0.7),
    ("tanh", oti.tanh, 0.7),
    ("asinh", oti.asinh, 0.7),
    ("acosh", oti.acosh, 1.7),
    ("atanh", oti.atanh, 0.3),
    ("exp", oti.exp, 0.7),
    ("log", oti.log, 1.3),
    ("log10", oti.log10, 1.3),
    ("logb3", lambda v, out=None: oti.logb(v, 3.0, out=out), 1.3),
    ("sqrt", oti.sqrt, 1.3),
    ("cbrt", oti.cbrt, 1.3),
    ("pow_2.5", lambda v, out=None: oti.pow(v, 2.5, out=out), 1.3),
    ("pow_-1.5", lambda v, out=None: oti.pow(v, -1.5, out=out), 1.3),
    ("erf", oti.erf, 0.7),
    ("neg", oti.neg, 0.7),
    ("abs_pos", oti.abs, 1.3),
    ("abs_neg", oti.abs, -1.3),
]

MATH_PARAMS = [pytest.param(*entry, id=entry[0]) for entry in MATH_FUNCTIONS]


# ********************************************************************************************************
def _math_input(x0):
    """
    Builds a 2x3 OTI array with entries near ``x0`` and mixed sparsity in both bases.

    Parameters
    ----------
    x0 : float
        Base value; entries have real parts in ``[0.8 x0, 1.1 x0]``.

    Returns
    -------
    matso
        OTI array truncated at ``ORDER``.

    Examples
    --------
    >>> _math_input(1.0).shape
    (2, 3)
    """
    x = oti.e(1, order=ORDER)
    y = oti.e(2, order=ORDER)
    base = x0 * np.array([[1.0, 0.9, 1.05], [0.8, 1.1, 0.95]])
    dx = [[0.1, 0.0, 0.05], [0.05, 0.0, 0.0]]
    dy = [[0.0, 0.1, 0.05], [0.0, 0.05, 0.0]]
    dxy = [[0.02, 0.0, 0.0], [0.0, 0.0, 0.02]]

    return oti.array(base) + x * oti.array(dx) + y * oti.array(dy) + (x * y) * oti.array(dxy)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name, func, x0", MATH_PARAMS)
def test_math_function_on_array(name, func, x0):
    """
    Test that each math function on an array equals the scalar function on every entry.

    Parameters
    ----------
    name : str
        Case id, also used in assertion messages.
    func : callable
        Function under test (accepts ``out=``).
    x0 : float
        Base value of the array entries (inside the function domain).
    """
    arr = _math_input(x0)

    _assert_oti_equal(func(arr), _map_entries(func, arr), name)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name, func, x0", MATH_PARAMS)
def test_math_function_on_array_out(name, func, x0):
    """
    Test the ``out=`` path of each math function on an array.

    Parameters
    ----------
    name : str
        Case id, also used in assertion messages.
    func : callable
        Function under test (accepts ``out=``).
    x0 : float
        Base value of the array entries (inside the function domain).
    """
    arr = _math_input(x0)
    out = _stale_holder(arr.shape)
    ret = func(arr, out=out)

    assert ret is None
    _assert_oti_equal(out, func(arr), name)

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------
# Construction, attributes and indexing.
# ------------------------------------------------------------------------------------------------

# ********************************************************************************************************
def test_array_constructors():
    """
    Test array, zeros, ones and eye shapes and real values.
    """
    data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]]

    np.testing.assert_array_equal(oti.array(data).real, np.array(data))
    np.testing.assert_array_equal(oti.array(np.array(data)).real, np.array(data))
    assert oti.array([1.0, 2.0, 3.0]).shape == (3, 1)
    np.testing.assert_array_equal(oti.zeros((2, 3)).real, np.zeros((2, 3)))
    assert oti.zeros(3).shape == (3, 1)
    np.testing.assert_array_equal(oti.ones((2, 3)).real, np.ones((2, 3)))
    np.testing.assert_array_equal(oti.eye(3).real, np.eye(3))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_attributes():
    """
    Test shape, nrows, ncols, size, order and real of an OTI array.
    """
    arr = _oti_matrix("C")

    assert arr.shape == (2, 3)
    assert arr.nrows == 2
    assert arr.ncols == 3
    assert arr.size == 6
    assert arr.order == ORDER
    np.testing.assert_array_equal(arr.real, np.array(MATRICES["C"][0]))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_getitem():
    """
    Test element access and row/column slicing, including imaginary parts.
    """
    arr = _oti_matrix("C")
    ref = _sym_derivs(_sym_matrix("C"))

    for i in range(2):

        for j in range(3):

            item = arr[i, j]
            assert isinstance(item, oti.sotinum)

            for (a, b), values in ref.items():

                assert float(_oti_value(item, a, b)) == pytest.approx(values[i, j])

            # end for

        # end for

    # end for

    row = arr[1, :]
    col = arr[:, 2]

    assert row.shape == (1, 3)
    assert col.shape == (2, 1)
    _assert_oti_equal(row, _entries(arr)[1:2, :], "row slice")
    _assert_oti_equal(col, _entries(arr)[:, 2:3], "column slice")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_setitem():
    """
    Test assigning real and OTI values to single entries and to a row slice.
    """
    arr = oti.zeros((2, 2))
    value = 5.0 + oti.e(2, order=ORDER)

    arr[0, 0] = 3.0
    arr[0, 1] = value
    arr[1, :] = 7.0

    np.testing.assert_array_equal(arr.real, np.array([[3.0, 5.0], [7.0, 7.0]]))
    np.testing.assert_array_equal(arr.get_im([2]), np.array([[0.0, 1.0], [0.0, 0.0]]))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_from_oti_entries():
    """
    Test building an array from a nested list mixing OTI numbers and reals.
    """
    s = _oti_scalar()
    arr = oti.array([[s, 1.0], [2.0, s * s]])
    expected = np.array([[s, oti.number(1.0)], [oti.number(2.0), s * s]], dtype=object)

    _assert_oti_equal(arr, expected, "array from OTI entries")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_2d_slicing_and_slice_assignment():
    """
    Test stepped 2-D slicing and assigning an OTI array into a sub-block.
    """
    arr = _oti_matrix("M3")
    entries = _entries(arr)
    block = _oti_matrix("A")

    sub = arr[0:3:2, 1:3]
    assert sub.shape == (2, 2)
    _assert_oti_equal(sub, entries[0:3:2, 1:3], "stepped slice")

    arr[1:3, 0:2] = block
    entries[1:3, 0:2] = _entries(block)
    _assert_oti_equal(arr, entries, "slice assignment")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_set():
    """
    Test matso.set from another array, an OTI scalar and a real.
    """
    arr = oti.ones((2, 2))
    s = _oti_scalar()

    arr.set(_oti_matrix("A"))
    _assert_oti_equal(arr, _entries(_oti_matrix("A")), "set matso")

    arr.set(s)
    _assert_oti_equal(arr, np.full((2, 2), s, dtype=object), "set sotinum")

    arr.set(2.5)
    _assert_oti_equal(arr, np.full((2, 2), oti.number(2.5), dtype=object), "set real")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_copy_is_independent():
    """
    Test that copy() duplicates every coefficient and that mutating the copy in place leaves the
    original intact.
    """
    arr = _oti_matrix("A")
    original = _entries(arr)

    dup = arr.copy()
    _assert_oti_equal(dup, original, "copy")

    dup[0, 0] = 100.0
    dup[1, :] = -1.0

    assert dup[0, 0].real == 100.0
    _assert_oti_equal(arr, original, "original after copy mutation")

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------
# Imaginary-part utilities: array result vs scalar method on every entry.
# ------------------------------------------------------------------------------------------------

UTILITIES = [
    ("truncate_e1", lambda v: v.truncate([1])),
    ("truncate_e1e2", lambda v: v.truncate([1, 2])),
    ("truncate_order_1", lambda v: v.truncate_order(1)),
    ("truncate_order_2", lambda v: v.truncate_order(2)),
    ("get_order_im_1", lambda v: v.get_order_im(1)),
    ("get_order_im_2", lambda v: v.get_order_im(2)),
    ("extract_im_e1", lambda v: v.extract_im([1])),
    ("extract_deriv_e1e2", lambda v: v.extract_deriv([[1, 1], [2, 1]])),
]

UTILITY_FUNCTIONS = {
    "truncate_e1": lambda v, out=None: oti.truncate([1], v, out=out),
    "truncate_e1e2": lambda v, out=None: oti.truncate([1, 2], v, out=out),
    "get_order_im_1": lambda v, out=None: oti.get_order_im(1, v, out=out),
    "get_order_im_2": lambda v, out=None: oti.get_order_im(2, v, out=out),
    "extract_im_e1": lambda v, out=None: oti.extract_im([1], v, out=out),
    "extract_deriv_e1e2": lambda v, out=None: oti.extract_deriv([[1, 1], [2, 1]], v, out=out),
}


# ********************************************************************************************************
@pytest.mark.parametrize(
    "name, method", [pytest.param(name, method, id=name) for name, method in UTILITIES],
)
def test_array_utility_methods(name, method):
    """
    Test matso truncation/extraction methods against the scalar method on every entry.

    Parameters
    ----------
    name : str
        Case id, also used in assertion messages.
    method : callable
        matso method under test, applied through a lambda.
    """
    arr = oti.exp(_oti_matrix("A"))

    _assert_oti_equal(method(arr), _map_entries(method, arr), name)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "name, func", [pytest.param(name, func, id=name) for name, func in UTILITY_FUNCTIONS.items()],
)
def test_array_utility_functions(name, func):
    """
    Test the module-level truncation/extraction functions agree with the matso methods.

    Parameters
    ----------
    name : str
        Case id, also used in assertion messages.
    func : callable
        Function under test (accepts ``out=``).
    """
    arr = oti.exp(_oti_matrix("A"))
    method = dict(UTILITIES)[name]

    _assert_oti_equal(func(arr), _entries(method(arr)), name)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "name, func", [pytest.param(name, func, id=name) for name, func in UTILITY_FUNCTIONS.items()],
)
def test_array_utility_functions_out(name, func):
    """
    Test the ``out=`` path of the module-level truncation/extraction functions.

    Parameters
    ----------
    name : str
        Case id, also used in assertion messages.
    func : callable
        Function under test (accepts ``out=``).
    """
    arr = oti.exp(_oti_matrix("A"))
    out = _stale_holder(arr.shape)
    ret = func(arr, out=out)

    assert ret is None
    _assert_oti_equal(out, _entries(func(arr)), name)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@functools.lru_cache(maxsize=None)
def _exp_a_reference():
    """
    Computes (and caches) the sympy derivatives of ``exp(A)`` applied elementwise.

    Returns
    -------
    dict
        Output of ``_sym_derivs`` for ``exp`` of every entry of ``MATRICES["A"]``.

    Examples
    --------
    >>> _exp_a_reference()[(0, 0)].shape
    (2, 2)
    """
    return _sym_derivs(_sym_elementwise(sympy.exp, _sym_matrix("A")))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("ma, mb", [(1, 0), (2, 0), (1, 1), (0, 2)])
def test_array_extract_explicit(ma, mb):
    """
    Test extract_im / extract_deriv against explicit sympy references.

    For the direction ``m = e1^ma e2^mb``, ``extract_deriv`` is the OTI expansion of
    d^(ma+mb) f / dx^ma dy^mb, and ``extract_im`` shifts the Taylor coefficients, so its
    derivatives are scaled by ``a! b! / ((a + ma)! (b + mb)!)``.

    Parameters
    ----------
    ma : int
        Exponent of e1 in the extracted direction.
    mb : int
        Exponent of e2 in the extracted direction.
    """
    ref = _exp_a_reference()
    arr = oti.exp(_oti_matrix("A"))
    im_res = arr.extract_im([1] * ma + [2] * mb)
    deriv_res = arr.extract_deriv(_humdir(ma, mb))

    for a, b in _directions(ORDER - ma - mb):

        target = ref[(a + ma, b + mb)]
        scale = (math.factorial(a) * math.factorial(b)
                 / (math.factorial(a + ma) * math.factorial(b + mb)))

        np.testing.assert_allclose(_oti_value(deriv_res, a, b), target, rtol=REL_TOL,
                                   atol=ABS_TOL, err_msg=f"extract_deriv d^{a},{b}")
        np.testing.assert_allclose(_oti_value(im_res, a, b), scale * target, rtol=REL_TOL,
                                   atol=ABS_TOL, err_msg=f"extract_im d^{a},{b}")

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_get_all_derivs_and_ims():
    """
    Test get_all_derivs / get_all_ims ordering and factorial scaling for two bases up to order 2.

    ``exp(A)`` is used so that the repeated-base directions (x^2, y^2) are nonzero.
    """
    ref = _exp_a_reference()
    arr = oti.exp(_oti_matrix("A"))
    dirs = [(0, 0), (1, 0), (0, 1), (2, 0), (1, 1), (0, 2)]
    derivs = arr.get_all_derivs(2, 2)
    ims = arr.get_all_ims(2, 2)

    assert derivs.shape == (len(dirs), 2, 2)
    assert ims.shape == (len(dirs), 2, 2)

    for k, (a, b) in enumerate(dirs):

        scale = 1.0 / (math.factorial(a) * math.factorial(b))

        np.testing.assert_allclose(derivs[k], ref[(a, b)], rtol=REL_TOL, atol=ABS_TOL)
        np.testing.assert_allclose(ims[k], scale * ref[(a, b)], rtol=REL_TOL, atol=ABS_TOL)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", range(ORDER + 1))
def test_trunc_sub(order):
    """
    Test trunc_sub(k, A, B, out) writes the order-k part of ``A - B`` into a stale holder.

    Parameters
    ----------
    order : int
        Order of the imaginary part kept by ``trunc_sub``.
    """
    lhs = _oti_matrix("A")
    rhs = _oti_matrix("B")
    out = _stale_holder(lhs.shape)

    oti.trunc_sub(order, lhs, rhs, out=out)

    _assert_oti_equal(out, (lhs - rhs).get_order_im(order), f"trunc_sub order {order}")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_get_im_and_deriv():
    """
    Test get_im / get_deriv (method, module function and ``out=``) in every direction up to ORDER.

    The module functions return OTI arrays; they must hold only the real coefficient, so every
    imaginary direction (including stale ones in the ``out=`` holder) is checked to be zero.
    """
    arr = oti.exp(_oti_matrix("A"))
    entries = _entries(arr)

    for a, b in _directions():

        if a + b == 0:

            continue

        # end if

        deriv_dir = _humdir(a, b)
        im_dir = [1] * a + [2] * b
        deriv_ref = np.vectorize(lambda num: num.get_deriv(deriv_dir))(entries)
        im_ref = np.vectorize(lambda num: num.get_im(im_dir))(entries)

        deriv_out = _stale_holder(arr.shape)
        im_out = _stale_holder(arr.shape)
        oti.get_deriv(deriv_dir, arr, out=deriv_out)
        oti.get_im(im_dir, arr, out=im_out)

        np.testing.assert_allclose(arr.get_deriv(deriv_dir), deriv_ref, rtol=REL_TOL)
        np.testing.assert_allclose(arr.get_im(im_dir), im_ref, rtol=REL_TOL)

        for label, res, ref in [("get_deriv", oti.get_deriv(deriv_dir, arr), deriv_ref),
                                ("get_deriv out", deriv_out, deriv_ref),
                                ("get_im", oti.get_im(im_dir, arr), im_ref),
                                ("get_im out", im_out, im_ref)]:

            _assert_oti_equal(res, np.vectorize(oti.number, otypes=[object])(ref),
                              f"{label} {deriv_dir}")

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_get_active_bases():
    """
    Test get_active_bases on arrays with two, one and no imaginary bases.
    """
    single = oti.array([[1.0, 2.0]]) + oti.e(2, order=ORDER) * oti.array([[0.0, 1.0]])

    assert list(_oti_matrix("A").get_active_bases()) == [1, 2]
    assert list(single.get_active_bases()) == [2]
    assert list(oti.array([[1.0, 2.0]]).get_active_bases()) == []

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_rom_eval():
    """
    Test Taylor evaluation of an array against the exact polynomial and per-entry rom_eval.
    """
    dx, dy = 0.1, -0.2
    q = float(_sym_q().subs({X_SYM: dx, Y_SYM: dy}))
    a0, a1, a2, a3 = (np.array(part) for part in MATRICES["A"])
    arr = _oti_matrix("A")
    inv_arr = oti.inv(arr)

    np.testing.assert_allclose(
        arr.rom_eval([1, 2], [dx, dy]).real, a0 + dx * a1 + dy * a2 + q * a3, rtol=REL_TOL,
    )

    rom_ref = np.vectorize(lambda num: num.rom_eval([1, 2], [dx, dy]).real)(_entries(inv_arr))
    np.testing.assert_allclose(inv_arr.rom_eval([1, 2], [dx, dy]).real, rom_ref, rtol=REL_TOL)

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------
# Interpolation and filtering.
# ------------------------------------------------------------------------------------------------

# ********************************************************************************************************
def _interp_ref(x, xvals, yvals):
    """
    Reference linear interpolation built from OTI arithmetic on the bracketing segment.

    Parameters
    ----------
    x : sotinum
        Query point (its real part selects the segment).
    xvals : list of float
        Ascending interpolation abscissae.
    yvals : matso
        Column array of ordinates.

    Returns
    -------
    sotinum
        ``y_k + (x - x_k) (y_(k+1) - y_k) / (x_(k+1) - x_k)``.

    Examples
    --------
    >>> _interp_ref(oti.number(0.5), [0.0, 1.0], oti.array([0.0, 2.0])).real
    1.0
    """
    k = int(np.searchsorted(xvals, x.real)) - 1
    slope = (yvals[k + 1, 0] - yvals[k, 0]) / (xvals[k + 1] - xvals[k])

    return yvals[k, 0] + (x - xvals[k]) * slope

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_interp1d():
    """
    Test interp1d for OTI scalar and OTI array query points with OTI ordinates.
    """
    xvals = [0.0, 1.0, 2.0, 4.0]
    yvals = oti.array([0.0, 10.0, 40.0, 50.0]) + oti.e(2, order=ORDER) * oti.array(
        [0.0, 1.0, 3.0, 0.5]
    )
    xq = 1.5 + oti.e(1, order=ORDER)
    xarr = oti.array([0.5, 1.5, 3.0]) + oti.e(1, order=ORDER) * oti.array([1.0, 2.0, 0.5])

    _assert_oti_equal(oti.interp1d(xq, oti.array(xvals), yvals), _interp_ref(xq, xvals, yvals),
                      "interp1d scalar")

    expected = np.array([[_interp_ref(xarr[i, 0], xvals, yvals)] for i in range(3)], dtype=object)
    _assert_oti_equal(oti.interp1d(xarr, oti.array(xvals), yvals), expected, "interp1d array")

    scalar_out = _stale_holder(None)
    array_out = _stale_holder((3, 1))
    oti.interp1d(xq, oti.array(xvals), yvals, out=scalar_out)
    oti.interp1d(xarr, oti.array(xvals), yvals, out=array_out)

    _assert_oti_equal(scalar_out, _interp_ref(xq, xvals, yvals), "interp1d scalar out")
    _assert_oti_equal(array_out, expected, "interp1d array out")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("size", [3, 4])
def test_moving_average(size):
    """
    Test moving_average against a NumPy window mean with endpoint padding (it is linear, so the
    same filter applies to the real part and to every derivative).

    Parameters
    ----------
    size : int
        Moving-average window size.
    """
    npts = 6
    lefti = size - size // 2 - 1
    righti = size - lefti
    data = oti.array(np.arange(1.0, npts + 1.0) ** 2) + oti.e(1, order=ORDER) * oti.array(
        np.linspace(0.5, 3.0, npts)
    )
    res = oti.moving_average(data, size)

    for a, b in [(0, 0), (1, 0)]:

        vals = _oti_value(data, a, b)[:, 0]
        padded = np.concatenate([np.repeat(vals[0], lefti), vals, np.repeat(vals[-1], righti - 1)])
        ref = np.array([padded[k:k + size].mean() for k in range(npts)])

        np.testing.assert_allclose(_oti_value(res, a, b)[:, 0], ref, rtol=REL_TOL)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------
# Solves and inverses beyond the sympy table.
# ------------------------------------------------------------------------------------------------

# Real 4x4 matrix (the n >= 4 path used to fail on it: bugs C and G).
DATA_4X4 = np.array([[4.0, 1.0, 0.0, 0.5], [1.0, 3.0, 1.0, 0.0], [0.0, 1.0, 2.0, 0.3],
                     [0.5, 0.2, 0.3, 5.0]])


# ********************************************************************************************************
@pytest.mark.parametrize("use_out", [False, True], ids=["alloc", "out"])
def test_solve_multiple_rhs(use_out):
    """
    Test solve() with a nonsymmetric OTI matrix and a two-column OTI right-hand side.

    Every derivative up to ORDER is checked through the residual ``K u - b = 0``.

    Parameters
    ----------
    use_out : bool
        Whether to solve into a stale ``out=`` holder.
    """
    x = oti.e(1, order=ORDER)
    y = oti.e(2, order=ORDER)
    rhs_real = np.array([[1.0, 2.0], [3.0, 4.0], [5.0, 6.0]])
    kmat = oti.array([[4.0, 1.0, 0.0], [2.0, 3.0, 1.0], [0.0, 1.0, 2.0]]) + x * oti.eye(3)
    kmat = kmat + (x * y + y**3) * oti.array(np.triu(np.ones((3, 3))))
    rhs = oti.array(rhs_real) + y * oti.ones((3, 2)) + x**2 * oti.array(np.arange(6.0).reshape(3, 2))

    if use_out:

        res = _with_out(oti.solve, (3, 2))(kmat, rhs)

    else:

        res = oti.solve(kmat, rhs)

    # end if

    np.testing.assert_allclose(res.real, np.linalg.solve(kmat.real, rhs_real), rtol=REL_TOL)
    _assert_oti_equal(oti.dot(kmat, res) - rhs, _entries(oti.zeros((3, 2))), "K u - b")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_inv_block_4x4():
    """
    Test inv_block on a 4x4 nonsymmetric OTI array through the identity K inv(K) = I.
    """
    data = [[4.0, 1.0, 0.0, 0.5], [1.0, 3.0, 1.0, 0.0], [0.0, 1.0, 2.0, 0.3], [0.5, 0.2, 0.3, 5.0]]
    x = oti.e(1, order=ORDER)
    y = oti.e(2, order=ORDER)
    kmat = oti.array(data) + x * oti.eye(4) + (x * y + y**3) * oti.array(np.triu(np.ones((4, 4))))

    _assert_oti_equal(oti.dot(kmat, oti.inv_block(kmat)), _entries(oti.eye(4)), "K inv(K)")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_inv_block_out():
    """
    Test the ``out=`` path of inv_block against its allocating path.
    """
    arr = _oti_matrix("M3")
    out = _stale_holder(arr.shape)
    ret = oti.inv_block(arr, out=out)

    assert ret is None
    _assert_oti_equal(out, oti.inv_block(arr), "inv_block out")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _oti_square(n):
    """
    Builds a nonsymmetric n x n OTI array with every derivative up to ``ORDER`` populated and a zero
    leading real entry (so the LU path has to pivot).

    Parameters
    ----------
    n : int
        Array size.

    Returns
    -------
    matso
        ``A0 + x A1 + y A2 + q(x, y) A3`` with deterministic, well-conditioned ``A0``.

    Examples
    --------
    >>> float(_oti_square(4).real[0, 0])
    0.0
    """
    i, j = np.indices((n, n))
    a0 = np.sin(1.0 + 3.0 * i + 7.0 * j) + 3.0 * np.eye(n)
    a0[0, 0] = 0.0
    x = oti.e(1, order=ORDER)
    y = oti.e(2, order=ORDER)
    q = x * y + x**3 + (x * y)**2 + y**4

    return (oti.array(a0) + x * oti.array(np.cos(2.0 * i + j))
            + y * oti.array(0.5 * np.sin(i + 5.0 * j)) + q * oti.array(0.25 * np.cos(3.0 * i - j)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _oti_rhs(n, ncols):
    """
    Builds an n x ncols OTI right-hand side with derivatives in both bases.

    Parameters
    ----------
    n : int
        Number of rows.
    ncols : int
        Number of right-hand sides.

    Returns
    -------
    matso
        ``B0 + y B1 + x^2 B2``.

    Examples
    --------
    >>> _oti_rhs(3, 2).shape
    (3, 2)
    """
    i, j = np.indices((n, ncols))
    x = oti.e(1, order=ORDER)
    y = oti.e(2, order=ORDER)

    return (oti.array(1.0 + i + 0.5 * j) + y * oti.array(np.cos(i - j))
            + x**2 * oti.array(0.3 * np.sin(i + 2.0 * j)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _lu_parts(lu, piv):
    """
    Splits the packed output of ``lu_factor`` into L, U and the row permutation.

    Parameters
    ----------
    lu : matso
        Packed factors (strictly lower part L, upper part with the diagonal U).
    piv : numpy.ndarray
        0-based LAPACK row interchanges.

    Returns
    -------
    tuple
        ``(L, U, perm)``: unit lower and upper triangular ``matso`` arrays, and ``perm`` such that
        row k of ``P^T A`` is row ``perm[k]`` of A.

    Examples
    --------
    >>> _lu_parts(oti.eye(2), np.array([1, 1]))[2]
    array([1, 0])
    """
    n = lu.shape[0]
    lmat = oti.eye(n)
    umat = oti.zeros((n, n))

    for i in range(n):

        for j in range(n):

            if i > j:

                lmat[i, j] = lu[i, j]

            else:

                umat[i, j] = lu[i, j]

            # end if

        # end for

    # end for

    perm = np.arange(n)

    for k, p in enumerate(piv):

        perm[[k, p]] = perm[[p, k]]

    # end for

    return lmat, umat, perm

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _permute_rows(arr, perm):
    """
    Returns ``arr`` with its rows reordered: row k of the result is row ``perm[k]`` of ``arr``.

    Parameters
    ----------
    arr : matso
        OTI array.
    perm : numpy.ndarray
        Row order.

    Returns
    -------
    matso
        ``P^T arr`` for the permutation matrix ``P`` of ``perm``.

    Examples
    --------
    >>> _permute_rows(oti.array([[1.0], [2.0]]), np.array([1, 0])).real
    array([[2.],
           [1.]])
    """
    n = len(perm)
    pmat = np.zeros((n, n))
    pmat[np.arange(n), perm] = 1.0

    return oti.dot(oti.array(pmat), arr)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_inv_4x4():
    """
    Test inversion of a 4x4 real-valued OTI array against NumPy (formerly bug C: all zeros).
    """
    res = oti.inv(oti.array(DATA_4X4)).real

    np.testing.assert_allclose(res, np.linalg.inv(DATA_4X4), rtol=REL_TOL)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_det_4x4():
    """
    Test the determinant of a 4x4 real-valued OTI array against NumPy (formerly bug G: generalized
    Sarrus rule).
    """
    res = oti.det(oti.array(DATA_4X4)).real

    assert res == pytest.approx(np.linalg.det(DATA_4X4), rel=REL_TOL)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("n", [3, 4, 5, 8])
@pytest.mark.parametrize("use_out", [False, True], ids=["alloc", "out"])
def test_inv_identity(n, use_out):
    """
    Test inv() on both sides of the closed-form limit (n <= 3) through ``K inv(K) = I`` in every
    direction, with pivoting (zero leading real entry).

    Parameters
    ----------
    n : int
        Array size.
    use_out : bool
        Whether to invert into a stale ``out=`` holder.
    """
    kmat = _oti_square(n)
    res = _with_out(oti.inv, (n, n))(kmat) if use_out else oti.inv(kmat)

    np.testing.assert_allclose(res.real, np.linalg.inv(kmat.real), rtol=REL_TOL)
    _assert_product_residual(kmat, res, oti.eye(n), f"K inv(K), n={n}")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("n", [3, 4, 6])
def test_det_matches_lu_diagonal(n):
    """
    Test det() against the product of the diagonal of U from lu_factor and the pivot sign, on both
    sides of the closed-form limit.

    Parameters
    ----------
    n : int
        Array size.
    """
    kmat = _oti_square(n)
    lu, piv = oti.lu_factor(kmat)
    ref = oti.number(-1.0 if np.count_nonzero(piv != np.arange(n)) % 2 else 1.0)

    for k in range(n):

        ref = ref * lu[k, k]

    # end for

    np.testing.assert_allclose(oti.det(kmat).real, np.linalg.det(kmat.real), rtol=REL_TOL)
    _assert_oti_equal(oti.det(kmat), ref, f"det, n={n}")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_solve_5x5_matches_inv_block():
    """
    Test the C block solver against the Python block inverse on a 5x5 array at 4th order.
    """
    kmat = _oti_square(5)
    rhs = _oti_rhs(5, 2)

    _assert_oti_equal(oti.solve(kmat, rhs), oti.dot(oti.inv_block(kmat), rhs), "solve 5x5")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_solve_rhs_is_out():
    """
    Test solve() writing its result into the right-hand-side array itself.
    """
    kmat = _oti_square(4)
    rhs = _oti_rhs(4, 2)
    ref = oti.solve(kmat, rhs)
    ret = oti.solve(kmat, rhs, out=rhs)

    assert ret is None
    _assert_oti_equal(rhs, ref, "solve out=b")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("n", [2, 4, 6])
def test_lu_factor_real_part_matches_scipy(n):
    """
    Test that the real part and the pivots of lu_factor equal scipy.linalg.lu_factor.

    Parameters
    ----------
    n : int
        Array size.
    """
    kmat = _oti_square(n)
    lu, piv = oti.lu_factor(kmat)
    lu_ref, piv_ref = scipy.linalg.lu_factor(kmat.real)

    assert piv.dtype == np.int32
    np.testing.assert_array_equal(piv, piv_ref)
    np.testing.assert_allclose(lu.real, lu_ref, rtol=REL_TOL, atol=ABS_TOL)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("n", [2, 4, 6])
def test_lu_factor_reconstruction(n):
    """
    Test ``P^T A = L U`` in every direction for the OTI factors of lu_factor.

    Parameters
    ----------
    n : int
        Array size.
    """
    kmat = _oti_square(n)
    lmat, umat, perm = _lu_parts(*oti.lu_factor(kmat))

    _assert_oti_equal(oti.dot(lmat, umat), _permute_rows(kmat, perm), f"L U, n={n}")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_lu_factor_out():
    """
    Test the ``out=`` path of lu_factor, into a stale holder and into the input array itself.
    """
    kmat = _oti_square(5)
    lu_ref, piv_ref = oti.lu_factor(kmat)

    out = _stale_holder((5, 5))
    lu, piv = oti.lu_factor(kmat, out=out)
    assert lu is out
    np.testing.assert_array_equal(piv, piv_ref)
    _assert_oti_equal(out, lu_ref, "lu_factor out")

    lu, piv = oti.lu_factor(kmat, out=kmat)
    assert lu is kmat
    np.testing.assert_array_equal(piv, piv_ref)
    _assert_oti_equal(kmat, lu_ref, "lu_factor out=A")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("ncols", [1, 3])
@pytest.mark.parametrize("use_out", [False, True], ids=["alloc", "out"])
def test_lu_solve_matches_solve(ncols, use_out):
    """
    Test that lu_solve with the factors of lu_factor equals solve, for one and several right-hand
    sides.

    Parameters
    ----------
    ncols : int
        Number of right-hand sides.
    use_out : bool
        Whether to solve into a stale ``out=`` holder.
    """
    kmat = _oti_square(5)
    rhs = _oti_rhs(5, ncols)
    lu_piv = oti.lu_factor(kmat)

    if use_out:

        res = _with_out(lambda b, out: oti.lu_solve(lu_piv, b, out=out), (5, ncols))(rhs)

    else:

        res = oti.lu_solve(lu_piv, rhs)

    # end if

    _assert_oti_equal(res, oti.solve(kmat, rhs), "lu_solve")
    _assert_oti_equal(oti.dot(kmat, res) - rhs, _entries(oti.zeros((5, ncols))), "K u - b")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_lu_solve_accepts_scipy_style_pivots():
    """
    Test that lu_solve accepts pivots as a list or as another integer dtype.
    """
    kmat = _oti_square(4)
    rhs = _oti_rhs(4, 1)
    lu, piv = oti.lu_factor(kmat)
    ref = oti.lu_solve((lu, piv), rhs)

    _assert_oti_equal(oti.lu_solve((lu, piv.tolist()), rhs), ref, "list pivots")
    _assert_oti_equal(oti.lu_solve((lu, piv.astype(np.int64)), rhs), ref, "int64 pivots")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_array(n, nip):
    """
    Builds an FE (Gauss) array whose integration points hold different OTI arrays.

    Parameters
    ----------
    n : int
        Array size.
    nip : int
        Number of integration points.

    Returns
    -------
    matsofe
        Integration point k holds ``(1 + 0.25 k) _oti_square(n)``.

    Examples
    --------
    >>> _fe_array(2, 3).nip
    3
    """
    base = _oti_square(n)
    fe_arr = oti.zeros((n, n), nip=nip)

    for k in range(nip):

        for i in range(n):

            for j in range(n):

                fe_arr.set_ijk(base[i, j] * (1.0 + 0.25 * k), i, j, k)

            # end for

        # end for

    # end for

    return fe_arr

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("n", [3, 4])
def test_fe_inv_det(n):
    """
    Test inv and det of FE arrays (allocating and stale ``out=`` paths) against the ``matso``
    result at every integration point.

    Parameters
    ----------
    n : int
        Array size.
    """
    nip = 3
    fe_arr = _fe_array(n, nip)
    stale = _stale_holder(None)

    # Stale out= holders: every integration point starts with coefficients in every direction.
    inv_out = oti.zeros((n, n), nip=nip) + _stale_holder((n, n))
    det_out = oti.zero(nip=nip) + stale
    assert oti.inv(fe_arr, out=inv_out) is None
    assert oti.det(fe_arr, out=det_out) is None

    for fe_inv, fe_det, kind in [(oti.inv(fe_arr), oti.det(fe_arr), "alloc"),
                                 (inv_out, det_out, "out")]:

        for k in range(nip):

            _assert_oti_equal(fe_inv.get_ip(k), oti.inv(fe_arr.get_ip(k)), f"FE inv {kind}, ip {k}")
            _assert_oti_equal(fe_det[k], oti.det(fe_arr.get_ip(k)), f"FE det {kind}, ip {k}")

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------
# Singular real part.
# ------------------------------------------------------------------------------------------------

# ********************************************************************************************************
def _singular_diag(n):
    """
    Builds ``diag(x, 1, ..., 1)``: its real part is singular, its determinant is ``x``.

    Parameters
    ----------
    n : int
        Array size.

    Returns
    -------
    matso
        OTI array truncated at ``ORDER``.

    Examples
    --------
    >>> _singular_diag(2).real
    array([[0., 0.],
           [0., 1.]])
    """
    arr = oti.eye(n)
    arr[0, 0] = oti.e(1, order=ORDER)

    return arr

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "call",
    [
        pytest.param(lambda: oti.inv(_singular_diag(4)), id="inv_4x4"),
        pytest.param(lambda: oti.inv(_singular_diag(3)), id="inv_3x3"),
        pytest.param(lambda: oti.inv(_singular_diag(1)), id="inv_1x1"),
        pytest.param(lambda: oti.matso.inv(_singular_diag(4)), id="matso_inv"),
        pytest.param(lambda: oti.inv(oti.zeros((4, 4), nip=2) + _singular_diag(4)), id="fe_inv"),
        pytest.param(lambda: oti.solve(_singular_diag(4), oti.ones((4, 1))), id="solve"),
        pytest.param(lambda: oti.lu_factor(_singular_diag(4)), id="lu_factor"),
        pytest.param(lambda: oti.lu_solve((oti.zeros((2, 2)), np.array([0, 1])), oti.ones((2, 1))),
                     id="lu_solve_zero_pivot"),
    ],
)
def test_singular_real_part_raises(call):
    """
    Test that inverses and solves of an array with a singular real part raise LinAlgError.

    Parameters
    ----------
    call : callable
        Call to evaluate.
    """

    with pytest.raises(np.linalg.LinAlgError, match="singular"):

        call()

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("n", [1, 2, 3])
def test_det_singular_real_part_closed_form(n):
    """
    Test det of ``diag(x, 1, ..., 1)`` up to 3x3, where the closed forms need no division.

    Parameters
    ----------
    n : int
        Array size.
    """
    _assert_oti_equal(oti.det(_singular_diag(n)), oti.e(1, order=ORDER), f"det, n={n}")

# end function
# --------------------------------------------------------------------------------------------------------


# Rank-3 real part plus x I: the determinant is a nonzero polynomial in x without a constant term.
RANK3_4X4 = [[1.0, 2.0, 3.0, 4.0], [2.0, 4.0, 6.0, 8.0], [1.0, 0.0, 1.0, 0.0], [0.0, 1.0, 0.0, 1.0]]


# ********************************************************************************************************
@pytest.mark.xfail(raises=np.linalg.LinAlgError, strict=True,
                   reason="Known limitation: det of an OTI array larger than 3x3 with a singular "
                          "real part (bug-report.md)")
@pytest.mark.parametrize("case", ["diag", "rank3"])
def test_det_singular_real_part_4x4(case):
    """
    Test det of 4x4 arrays whose real part is singular but whose determinant has nonzero
    derivatives.

    Parameters
    ----------
    case : str
        ``"diag"``: ``diag(x, 1, 1, 1)``, determinant ``x``. ``"rank3"``: ``R + x I`` with a rank-3
        real part ``R``, compared with sympy.
    """

    if case == "diag":

        _assert_oti_equal(oti.det(_singular_diag(4)), oti.e(1, order=ORDER), "det diag")

    else:

        arr = oti.array(RANK3_4X4) + oti.e(1, order=ORDER) * oti.eye(4)
        ref = (sympy.Matrix(RANK3_4X4) + X_SYM * sympy.eye(4)).det()
        _assert_matches_sympy(oti.det(arr), ref, "det rank3")

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------
# Shape validation: invalid shapes raise ValueError instead of reaching the C core's exit().
# ------------------------------------------------------------------------------------------------

# ********************************************************************************************************
def _shape_error_cases():
    """
    Builds the invalid-shape calls checked by ``test_shape_errors_raise``.

    Returns
    -------
    list
        ``pytest.param(call, match, id=...)`` entries; ``call`` takes no arguments and ``match``
        is a regular expression expected in the ``ValueError`` message.

    Examples
    --------
    >>> len(_shape_error_cases()) > 0
    True
    """
    a22 = oti.ones((2, 2))
    a33 = oti.ones((3, 3))
    a23 = oti.ones((2, 3))
    r33 = real.array(np.ones((3, 3)).tolist())
    x = 1.0 + oti.e(1, order=2)
    fe3 = oti.zeros((2, 2), nip=3)
    fe4 = oti.zeros((2, 2), nip=4)
    w3 = oti.zero(nip=3)

    cases = [
        ("add", lambda: a22 + a33, "different shapes"),
        ("sub", lambda: a22 - a33, "different shapes"),
        ("mul", lambda: a22 * a33, "different shapes"),
        ("div", lambda: a22 / a33, "different shapes"),
        ("pow", lambda: a22**a33, "different shapes"),
        ("add_dmat", lambda: a22 + r33, "different shapes"),
        ("sum_func", lambda: oti.sum(a22, a33), "different shapes"),
        ("sub_func", lambda: oti.sub(a22, a33), "different shapes"),
        ("mul_func", lambda: oti.mul(a22, a33), "different shapes"),
        ("div_func", lambda: oti.div(a22, a33), "different shapes"),
        ("matso_add", lambda: oti.matso.add(a22, a33), "different shapes"),
        ("trunc_sub", lambda: oti.trunc_sub(1, a22, a33, out=oti.zeros((2, 2))), "different shapes"),
        ("dot", lambda: oti.dot(a22, a33), "not aligned"),
        ("dot_dmat", lambda: oti.dot(a22, r33), "not aligned"),
        ("matmul", lambda: a22 @ a33, "not aligned"),
        ("matso_dot", lambda: oti.matso.dot(a22, a33), "not aligned"),
        ("dot_product", lambda: oti.dot_product(a22, a33), "different sizes"),
        ("pow_func", lambda: oti.pow(a22, a33), "different shapes"),
        ("pow_func_row_col", lambda: oti.pow(oti.ones((1, 3)), oti.ones((3, 1))),
         "different shapes"),
        ("set", lambda: a22.copy().set(a33), "different shapes"),
        ("slice_assign", lambda: a33.copy().__setitem__((slice(0, 2), slice(0, 2)), a33),
         "slice assignment"),
        ("row_assign", lambda: a33.copy().__setitem__(0, oti.ones((1, 2))), "slice assignment"),
        ("fe_sum_nip", lambda: oti.sum(fe3, fe4), "integration points"),
        ("fe_add_nip", lambda: fe3 + fe4, "integration points"),
        ("fe_sin_out_nip", lambda: oti.sin(fe3, out=fe4), "integration points"),
        ("gauss_integrate_nip", lambda: oti.gauss_integrate(fe3, oti.zero(nip=4)),
         "integration points"),
        ("gauss_integrate_out", lambda: oti.gauss_integrate(fe3, w3, out=a33), "out has shape"),
        ("fe_dot_nip", lambda: oti.dot(oti.eye(2, nip=3), oti.eye(2, nip=4)), "integration points"),
        ("fe_dot_out_nip", lambda: oti.dot(fe3, fe3, out=fe4), "integration points"),
        ("fe_dot_product_out_nip",
         lambda: oti.dot_product(oti.ones((1, 2), nip=3), oti.ones((2, 1)), out=oti.zero(nip=4)),
         "integration points"),
        ("fe_transpose_out_nip", lambda: oti.transpose(fe3, out=fe4), "integration points"),
        ("fe_det_out_nip", lambda: oti.det(fe3, out=oti.zero(nip=4)), "integration points"),
        ("fe_norm_out_nip", lambda: oti.norm(fe3, out=oti.zero(nip=4)), "integration points"),
        ("fe_inv_out_nip", lambda: oti.inv(fe3, out=fe4), "integration points"),
        ("det", lambda: oti.det(a23), "must be square"),
        ("inv", lambda: oti.inv(a23), "must be square"),
        ("matso_inv", lambda: oti.matso.inv(a23), "must be square"),
        ("inv_block", lambda: oti.inv_block(a23), "must be square"),
        ("solve_square", lambda: oti.solve(a23, oti.ones((2, 1))), "must be square"),
        ("solve_rhs", lambda: oti.solve(a22, oti.ones((3, 1))), "not aligned"),
        ("lu_factor", lambda: oti.lu_factor(a23), "must be square"),
        ("lu_solve_square", lambda: oti.lu_solve((a23, np.array([0, 1])), oti.ones((2, 1))),
         "must be square"),
        ("lu_solve_rhs", lambda: oti.lu_solve((a22, np.array([0, 1])), oti.ones((3, 1))),
         "not aligned"),
        ("lu_solve_piv_shape", lambda: oti.lu_solve((a22, np.array([0])), oti.ones((2, 1))),
         "piv has shape"),
        ("lu_solve_piv_range", lambda: oti.lu_solve((a22, np.array([0, 2])), oti.ones((2, 1))),
         "out of range"),
        ("lu_solve_piv_negative", lambda: oti.lu_solve((a22, np.array([-1, 1])), oti.ones((2, 1))),
         "out of range"),
        ("lu_solve_piv_float", lambda: oti.lu_solve((a22, np.array([0.0, 1.0])), oti.ones((2, 1))),
         "must hold integers"),
        ("lu_solve_piv_wrap", lambda: oti.lu_solve((a22, np.array([2**32, 1])), oti.ones((2, 1))),
         "out of range"),
        ("interp1d_data", lambda: oti.interp1d(x, oti.ones((3, 1)), oti.ones((4, 1))),
         "different shapes"),
        # out= holders of the wrong shape or kind.
        ("sum_out", lambda: oti.sum(a22, a22, out=a33), "out has shape"),
        ("dot_out", lambda: oti.dot(a23, a33, out=a22), "out has shape"),
        ("transpose_out", lambda: oti.transpose(a23, out=a23), "out has shape"),
        ("matso_transpose_out", lambda: oti.matso.transpose(a23, a23), "out has shape"),
        ("inv_out", lambda: oti.inv(a22, out=a33), "out has shape"),
        ("inv_block_out", lambda: oti.inv_block(a22, out=a33), "out has shape"),
        ("solve_out", lambda: oti.solve(a22, oti.ones((2, 1)), out=oti.zeros((3, 1))),
         "out has shape"),
        ("lu_factor_out", lambda: oti.lu_factor(a22, out=a33), "out has shape"),
        ("lu_solve_out", lambda: oti.lu_solve((a22, np.array([0, 1])), oti.ones((2, 1)),
                                              out=oti.zeros((3, 1))), "out has shape"),
        ("det_out", lambda: oti.det(a22, out=a22), "scalar holder"),
        ("norm_out", lambda: oti.norm(a22, out=a22), "scalar holder"),
        ("dot_product_out", lambda: oti.dot_product(a22, a22, out=a22), "scalar holder"),
        ("sin_out", lambda: oti.sin(a22, out=a33), "out has shape"),
        ("logb_out", lambda: oti.logb(a22, 3.0, out=a33), "out has shape"),
        ("pow_out", lambda: oti.pow(a22, 2.0, out=a33), "out has shape"),
        ("pow_sotinum_out", lambda: oti.pow(a22, x, out=a33), "out has shape"),
        ("pow_matso_out", lambda: oti.pow(a22, a22, out=a33), "out has shape"),
        ("sin_out_scalar_holder", lambda: oti.sin(a22, out=oti.zero()), "must be an array"),
        ("truncate_out", lambda: oti.truncate([1], a22, out=a33), "out has shape"),
        ("get_deriv_out", lambda: oti.get_deriv([[1, 1]], a22, out=a33), "out has shape"),
        ("interp1d_out", lambda: oti.interp1d(oti.ones((2, 1)), oti.ones((3, 1)),
                                              oti.ones((3, 1)), out=a33), "out has shape"),
    ]

    return [pytest.param(call, match, id=name) for name, call, match in cases]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("call, match", _shape_error_cases())
def test_shape_errors_raise(call, match):
    """
    Test that invalid shapes raise ValueError instead of aborting the interpreter.

    Parameters
    ----------
    call : callable
        Invalid call to evaluate.
    match : str
        Regular expression expected in the error message.
    """

    with pytest.raises(ValueError, match=match):

        call()

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "func", [pytest.param(oti.det, id="det"), pytest.param(oti.norm, id="norm")],
)
def test_real_array_out_raises(func):
    """
    Test that det / norm of a real array reject out= (their result is a float).

    Parameters
    ----------
    func : callable
        ``oti.det`` or ``oti.norm``.
    """
    rmat = real.array(REAL_MATRIX)

    assert func(rmat) == pytest.approx(
        np.linalg.det(np.array(REAL_MATRIX)) if func is oti.det else 30.0**0.5
    )

    with pytest.raises(TypeError, match="out= is not supported"):

        func(rmat, out=oti.zero())

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "call",
    [
        pytest.param(lambda out: oti.sin(0.5, out=out), id="sin"),
        pytest.param(lambda out: oti.pow(2.0, 3.0, out=out), id="pow"),
        pytest.param(lambda out: oti.truncate([1], 0.5, out=out), id="truncate"),
        pytest.param(lambda out: oti.sum(1.0, 2.0, out=out), id="sum"),
        pytest.param(lambda out: oti.mul(1.0, 2.0, out=out), id="mul"),
    ],
)
def test_real_input_out_raises(call):
    """
    Test that functions of real inputs reject out= (their result is a float, so the holder could
    never be written).

    Parameters
    ----------
    call : callable
        Function call taking the ``out`` holder.
    """

    with pytest.raises(TypeError, match="out= is not supported"):

        call(oti.zero())

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_fe_broadcasting():
    """
    Test that the shape checks keep FE (Gauss) arrays broadcasting against non-FE operands.
    """
    fe_arr = oti.zeros((2, 2), nip=3) + 1.0
    res = fe_arr + oti.ones((2, 2))

    assert res.nip == 3
    assert oti.gauss_integrate(res, oti.zero(nip=3) + 0.5).shape == (2, 2)

# end function
# --------------------------------------------------------------------------------------------------------


if __name__ == "__main__":

    pytest.main([__file__])

# end if
