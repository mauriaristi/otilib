"""
Tests every supported sparse scalar function and operator up to 6th order derivatives.

Reference derivatives are computed exactly with sympy and evaluated at the same point used to seed
the OTI number. Each entry of ``FUNCTIONS`` is checked for the univariate derivatives
d^k f / dx^k (k = 0..6) and for all mixed derivatives of f(x*y) with total order up to 6.
"""

import functools

import pytest
import sympy
import pyoti.sparse as oti


# sympy's evalf goes through an mpmath helper that emits a DeprecationWarning per call.
pytestmark = pytest.mark.filterwarnings("ignore:bitcount function is deprecated")

MAX_ORDER = 6
REL_TOL = 1e-9
ABS_TOL = 1e-10

# Constant operand used in the real-OTI operator tests.
CONST = 1.7

X_SYM, Y_SYM = sympy.symbols("x y", real=True)

# (name, oti function, sympy function, evaluation point x0)
FUNCTIONS = [
    # Trigonometric.
    ("sin", oti.sin, sympy.sin, 0.7),
    ("cos", oti.cos, sympy.cos, 0.7),
    ("tan", oti.tan, sympy.tan, 0.7),
    ("asin", oti.asin, sympy.asin, 0.3),
    ("acos", oti.acos, sympy.acos, 0.3),
    ("atan", oti.atan, sympy.atan, 0.3),
    # Hyperbolic.
    ("sinh", oti.sinh, sympy.sinh, 0.7),
    ("cosh", oti.cosh, sympy.cosh, 0.7),
    ("tanh", oti.tanh, sympy.tanh, 0.7),
    ("asinh", oti.asinh, sympy.asinh, 0.7),
    ("acosh", oti.acosh, sympy.acosh, 1.7),
    ("atanh", oti.atanh, sympy.atanh, 0.3),
    # Exponential and logarithms.
    ("exp", oti.exp, sympy.exp, 0.7),
    ("log", oti.log, sympy.log, 1.3),
    ("log10", oti.log10, lambda v: sympy.log(v, 10), 1.3),
    ("logb3", lambda v: oti.logb(v, 3.0), lambda v: sympy.log(v, 3), 1.3),
    # Roots and powers.
    ("sqrt", oti.sqrt, sympy.sqrt, 1.3),
    ("cbrt", oti.cbrt, sympy.cbrt, 1.3),
    ("pow_2.5", lambda v: oti.pow(v, 2.5), lambda v: v**sympy.Rational(5, 2), 1.3),
    ("pow_-1.5", lambda v: oti.pow(v, -1.5), lambda v: v**sympy.Rational(-3, 2), 1.3),
    ("pow_op_int", lambda v: v**3, lambda v: v**3, 1.3),
    ("pow_op_real", lambda v: v**2.5, lambda v: v**sympy.Rational(5, 2), 1.3),
    ("pow_real_base", lambda v: 2.0**v, lambda v: 2**v, 1.3),
    ("pow_oti_oti", lambda v: v**v, lambda v: v**v, 1.3),
    # Miscellaneous.
    ("erf", oti.erf, sympy.erf, 0.7),
    ("neg", oti.neg, lambda v: -v, 0.7),
    ("abs_pos", oti.abs, sympy.Abs, 1.3),
    ("abs_neg", oti.abs, sympy.Abs, -1.3),
    # Arithmetic operators.
    ("add_oti_real", lambda v: v + CONST, lambda v: v + CONST, 0.7),
    ("add_real_oti", lambda v: CONST + v, lambda v: CONST + v, 0.7),
    ("sub_oti_real", lambda v: v - CONST, lambda v: v - CONST, 0.7),
    ("sub_real_oti", lambda v: CONST - v, lambda v: CONST - v, 0.7),
    ("mul_oti_real", lambda v: v * CONST, lambda v: v * CONST, 0.7),
    ("mul_real_oti", lambda v: CONST * v, lambda v: CONST * v, 0.7),
    ("div_oti_real", lambda v: v / CONST, lambda v: v / CONST, 0.7),
    ("div_real_oti", lambda v: CONST / v, lambda v: CONST / v, 0.7),
    ("mul_oti_oti", lambda v: v * v, lambda v: v * v, 0.7),
    ("div_oti_oti", lambda v: v / (v + 1.0), lambda v: v / (v + 1), 0.7),
]

FUNCTION_PARAMS = [pytest.param(*entry, id=entry[0]) for entry in FUNCTIONS]
SYMPY_FUNCTIONS = {entry[0]: entry[2] for entry in FUNCTIONS}


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
    >>> _humdir(2, 0)
    [[1, 2]]
    >>> _humdir(1, 3)
    [[1, 1], [2, 3]]
    """
    return [[basis, exp] for basis, exp in ((1, a), (2, b)) if exp > 0]

# end function


@functools.lru_cache(maxsize=None)
def _sympy_mixed_derivs(name, x0, y0, max_order):
    """
    Computes exact mixed derivatives of f(x*y) with sympy.

    Parameters
    ----------
    name : str
        Key of the function in ``SYMPY_FUNCTIONS``.
    x0 : float
        Evaluation point for x.
    y0 : float
        Evaluation point for y.
    max_order : int
        Maximum total derivative order.

    Returns
    -------
    dict
        Maps ``(a, b)`` to the float value of d^(a+b) f(x*y) / dx^a dy^b at ``(x0, y0)``, for all
        ``a + b <= max_order``.

    Examples
    --------
    >>> derivs = _sympy_mixed_derivs("exp", 0.0, 1.0, 1)
    >>> derivs[(1, 0)]
    1.0
    """
    expr = SYMPY_FUNCTIONS[name](X_SYM * Y_SYM)
    point = {X_SYM: sympy.Float(x0, 30), Y_SYM: sympy.Float(y0, 30)}
    derivs = {}

    for a in range(max_order + 1):

        d_x = sympy.diff(expr, X_SYM, a)

        for b in range(max_order + 1 - a):

            d_xy = sympy.diff(d_x, Y_SYM, b)
            derivs[(a, b)] = float(d_xy.evalf(30, subs=point))

        # end for

    # end for

    return derivs

# end function


@pytest.mark.parametrize("name, oti_fn, sym_fn, x0", FUNCTION_PARAMS)
def test_univariate_derivatives(name, oti_fn, sym_fn, x0):
    """
    Checks the value and derivatives 1..6 of f(x) against sympy.

    Parameters
    ----------
    name : str
        Function identifier.
    oti_fn : callable
        Function applied to the OTI number.
    sym_fn : callable
        Equivalent sympy function (reference).
    x0 : float
        Evaluation point.
    """
    x = x0 + oti.e(1, order=MAX_ORDER)
    f = oti_fn(x)

    # With y0 = 1, the derivatives of f(x*y) along x alone are the derivatives of f(x).
    ref = _sympy_mixed_derivs(name, x0, 1.0, MAX_ORDER)

    assert float(f.real) == pytest.approx(ref[(0, 0)], rel=REL_TOL, abs=ABS_TOL), (
        f"{name}: value mismatch"
    )

    for k in range(1, MAX_ORDER + 1):

        value = float(f.get_deriv(_humdir(k, 0)))
        expected = ref[(k, 0)]
        assert value == pytest.approx(expected, rel=REL_TOL, abs=ABS_TOL), (
            f"{name}: derivative order {k}: got {value}, expected {expected}"
        )

    # end for

# end function


@pytest.mark.parametrize("name, oti_fn, sym_fn, x0", FUNCTION_PARAMS)
def test_bivariate_mixed_derivatives(name, oti_fn, sym_fn, x0):
    """
    Checks every mixed derivative of f(x*y) with total order up to 6 against sympy.

    Parameters
    ----------
    name : str
        Function identifier.
    oti_fn : callable
        Function applied to the OTI number.
    sym_fn : callable
        Equivalent sympy function (reference).
    x0 : float
        Evaluation point for x (y is evaluated at 1.0, so x*y stays in the function's domain).
    """
    y0 = 1.0
    x = x0 + oti.e(1, order=MAX_ORDER)
    y = y0 + oti.e(2, order=MAX_ORDER)
    f = oti_fn(x * y)

    ref = _sympy_mixed_derivs(name, x0, y0, MAX_ORDER)

    for (a, b), expected in ref.items():

        if a + b == 0:

            continue

        # end if

        value = float(f.get_deriv(_humdir(a, b)))
        assert value == pytest.approx(expected, rel=REL_TOL, abs=ABS_TOL), (
            f"{name}: d^{a + b}/dx^{a} dy^{b}: got {value}, expected {expected}"
        )

    # end for

# end function


OUT_FUNCTIONS = [
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
    ("erf", oti.erf, 0.7),
    ("neg", oti.neg, 0.7),
    ("abs", oti.abs, -1.3),
]


@pytest.mark.parametrize(
    "name, fn, x0", [pytest.param(*entry, id=entry[0]) for entry in OUT_FUNCTIONS]
)
def test_function_out_argument(name, fn, x0):
    """
    Checks that writing into a populated ``out`` number matches the allocating call.

    The destination starts with stale coefficients, including a basis (e3) that the result does not
    contain, to check that they are all overwritten.

    Parameters
    ----------
    name : str
        Function identifier.
    fn : callable
        Sparse math function supporting the ``out`` keyword.
    x0 : float
        Evaluation point inside the function's domain.
    """
    x = x0 + oti.e(1, order=MAX_ORDER)
    y = 1.0 + oti.e(2, order=MAX_ORDER)
    expected = fn(x * y)

    out = 9.0 + 5.0 * oti.e(3, order=MAX_ORDER) + oti.e(1, order=MAX_ORDER) ** 2
    result = fn(x * y, out=out)

    assert result is None, f"{name}: out= call should return None"
    assert float(out.real) == pytest.approx(float(expected.real), rel=REL_TOL)
    assert float(out.get_deriv([3])) == 0.0, f"{name}: stale e3 coefficient kept"

    for a in range(MAX_ORDER + 1):

        for b in range(MAX_ORDER + 1 - a):

            if a + b == 0:

                continue

            # end if

            direction = _humdir(a, b)
            assert float(out.get_deriv(direction)) == pytest.approx(
                float(expected.get_deriv(direction)), rel=REL_TOL, abs=ABS_TOL
            ), f"{name}: direction (a={a}, b={b})"

        # end for

    # end for

# end function


if __name__ == "__main__":

    pytest.main([__file__])

# end if
