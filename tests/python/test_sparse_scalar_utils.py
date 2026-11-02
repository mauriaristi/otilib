"""
Tests sparse scalar utilities: Taylor series evaluation (rom_eval), truncate and truncate_order.
"""

import math

import numpy as np
import pytest
import sympy
import pyoti.sparse as oti


# sympy's evalf goes through an mpmath helper that emits a DeprecationWarning per call.
pytestmark = pytest.mark.filterwarnings("ignore:bitcount function is deprecated")

MAX_ORDER = 6
X0 = 0.3
Y0 = 0.2


# ********************************************************************************************************
def _directions(max_order):
    """
    Lists every bivariate derivative direction up to a total order.

    Parameters
    ----------
    max_order : int
        Maximum total order ``a + b``.

    Returns
    -------
    list of tuple
        Pairs ``(a, b)`` with ``1 <= a + b <= max_order``.

    Examples
    --------
    >>> _directions(1)
    [(0, 1), (1, 0)]
    """
    return [
        (a, b)
        for a in range(max_order + 1)
        for b in range(max_order + 1 - a)
        if a + b > 0
    ]

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
    >>> _humdir(0, 2)
    [[2, 2]]
    """
    return [[basis, exp] for basis, exp in ((1, a), (2, b)) if exp > 0]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _bivariate_number():
    """
    Creates f(x, y) = exp(x + 2y) at (X0, Y0) truncated at MAX_ORDER.

    Every derivative is nonzero and known in closed form:
    d^(a+b) f / dx^a dy^b = 2^b exp(X0 + 2 Y0).

    Returns
    -------
    sotinum
        OTI number with all bivariate directions up to MAX_ORDER populated.

    Examples
    --------
    >>> f = _bivariate_number()
    >>> f.order
    6
    """
    x = X0 + oti.e(1, order=MAX_ORDER)
    y = Y0 + oti.e(2, order=MAX_ORDER)

    return oti.exp(x + 2.0 * y)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _bivariate_deriv(a, b):
    """
    Exact derivative d^(a+b) / dx^a dy^b of exp(x + 2y) at (X0, Y0).

    Parameters
    ----------
    a : int
        Derivative order along x.
    b : int
        Derivative order along y.

    Returns
    -------
    float
        Value of the derivative.

    Examples
    --------
    >>> _bivariate_deriv(0, 1) == 2.0 * math.exp(X0 + 2.0 * Y0)
    True
    """
    return 2.0**b * math.exp(X0 + 2.0 * Y0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_truncated(res, removed):
    """
    Asserts that ``res`` equals exp(x + 2y) except on directions where ``removed`` is True.

    Parameters
    ----------
    res : sotinum
        Truncated number to check.
    removed : callable
        ``removed(a, b)`` returns True when direction (a, b) must be zero.

    Examples
    --------
    >>> _assert_truncated(_bivariate_number(), lambda a, b: False)
    """
    assert float(res.real) == pytest.approx(_bivariate_deriv(0, 0))

    for a, b in _directions(MAX_ORDER):

        expected = 0.0 if removed(a, b) else _bivariate_deriv(a, b)
        assert float(res.get_deriv(_humdir(a, b))) == pytest.approx(expected), (
            f"direction (a={a}, b={b})"
        )

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "humdir, removed",
    [
        pytest.param([1], lambda a, b: a >= 1, id="e1"),
        pytest.param([2], lambda a, b: b >= 1, id="e2"),
        pytest.param([[1, 2]], lambda a, b: a >= 2, id="e1^2"),
        pytest.param([1, 2], lambda a, b: a >= 1 and b >= 1, id="e1*e2"),
        pytest.param([[1, 2], 2], lambda a, b: a >= 2 and b >= 1, id="e1^2*e2"),
        pytest.param([[2, 6]], lambda a, b: b >= 6, id="e2^6"),
    ],
)
def test_truncate_method(humdir, removed):
    """
    Checks that truncate zeroes exactly the directions that are multiples of ``humdir``.

    Parameters
    ----------
    humdir : list
        Imaginary direction to truncate.
    removed : callable
        Predicate on (a, b) telling which directions must become zero.
    """
    f = _bivariate_number()
    res = f.truncate(humdir)

    _assert_truncated(res, removed)

    # The original number must not be modified.
    _assert_truncated(f, lambda a, b: False)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_truncate_module_function():
    """
    Checks that oti.truncate matches the method, with and without a preallocated output.
    """
    f = _bivariate_number()
    removed = lambda a, b: a >= 1

    _assert_truncated(oti.truncate([1], f), removed)

    out = oti.zero(order=MAX_ORDER)
    result = oti.truncate([1], f, out=out)

    assert result is None
    _assert_truncated(out, removed)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_truncate_unsupported_type():
    """
    Checks that oti.truncate rejects unsupported types.
    """

    with pytest.raises(TypeError):

        oti.truncate([1], 2.0)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", range(1, MAX_ORDER + 2))
def test_truncate_order(order):
    """
    Checks that truncate_order removes every direction with order equal to or above ``order``.

    Parameters
    ----------
    order : int
        Order from which directions are removed.
    """
    f = _bivariate_number()
    res = f.truncate_order(order)

    _assert_truncated(res, lambda a, b: a + b >= order)
    assert res.actual_order == min(order - 1, MAX_ORDER)
    assert res.order == f.order

    # The original number must not be modified.
    _assert_truncated(f, lambda a, b: False)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_truncate_order_zero_removes_real_part():
    """
    Checks that truncate_order(0) also removes the real part, which is the term of order zero.
    """
    f = _bivariate_number()
    res = f.truncate_order(0)

    assert float(res.real) == 0.0
    assert res.order == 0

    for a, b in _directions(MAX_ORDER):

        assert float(res.get_deriv(_humdir(a, b))) == 0.0

    # end for

    # The original number must not be modified.
    _assert_truncated(f, lambda a, b: False)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("h", [0.1, 0.05, -0.2])
def test_rom_eval_univariate_taylor_polynomial(h):
    """
    Checks rom_eval against the 6th order Taylor polynomial of exp and its truncation error.

    Parameters
    ----------
    h : float
        Step from the expansion point.
    """
    f = oti.exp(X0 + oti.e(1, order=MAX_ORDER))
    value = float(f.rom_eval([1], [h]).real)

    expected = sum(math.exp(X0) * h**k / math.factorial(k) for k in range(MAX_ORDER + 1))
    assert value == pytest.approx(expected, rel=1e-13)

    # Lagrange remainder bound for the truncated Taylor series.
    bound = math.exp(X0 + max(h, 0.0)) * abs(h) ** (MAX_ORDER + 1) / math.factorial(MAX_ORDER + 1)
    assert abs(value - math.exp(X0 + h)) <= bound

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_rom_eval_polynomial_is_exact():
    """
    Checks that rom_eval reproduces a polynomial of total degree <= MAX_ORDER exactly.
    """

    # ****************************************************************************************************
    def poly(x, y):
        """
        Evaluates the reference polynomial.

        Parameters
        ----------
        x : float or sotinum
            First variable.
        y : float or sotinum
            Second variable.

        Returns
        -------
        float or sotinum
            Polynomial value.

        Examples
        --------
        >>> poly(0.0, 0.0)
        0.5
        """
        return x**3 * y**2 + 2.0 * x * y - y**4 + 3.0 * x**6 + 0.5

    # end function
    # ----------------------------------------------------------------------------------------------------

    dx, dy = 0.4, -0.7
    x = X0 + oti.e(1, order=MAX_ORDER)
    y = Y0 + oti.e(2, order=MAX_ORDER)
    f = poly(x, y)

    value = float(f.rom_eval([1, 2], [dx, dy]).real)
    assert value == pytest.approx(poly(X0 + dx, Y0 + dy), rel=1e-12)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_rom_eval_bivariate_matches_sympy():
    """
    Checks rom_eval of sin(x*y) against the sympy total-degree-6 Taylor polynomial.
    """
    dx, dy = 0.15, -0.1
    x_sym, y_sym = sympy.symbols("x y", real=True)
    expr = sympy.sin(x_sym * y_sym)
    point = {x_sym: sympy.Float(X0, 30), y_sym: sympy.Float(Y0, 30)}

    expected = 0.0

    for a in range(MAX_ORDER + 1):

        for b in range(MAX_ORDER + 1 - a):

            deriv = float(sympy.diff(expr, x_sym, a, y_sym, b).evalf(30, subs=point))
            expected += deriv * dx**a * dy**b / (math.factorial(a) * math.factorial(b))

        # end for

    # end for

    x = X0 + oti.e(1, order=MAX_ORDER)
    y = Y0 + oti.e(2, order=MAX_ORDER)
    f = oti.sin(x * y)

    assert float(f.rom_eval([1, 2], [dx, dy]).real) == pytest.approx(expected, rel=1e-12)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_rom_eval_basis_order_and_omitted_basis():
    """
    Checks that basis order does not matter and that omitted bases use a zero step.
    """
    dx, dy = 0.15, -0.1
    f = _bivariate_number()

    ordered = float(f.rom_eval([1, 2], [dx, dy]).real)
    swapped = float(f.rom_eval([2, 1], [dy, dx]).real)
    assert swapped == pytest.approx(ordered, rel=1e-14)

    only_x = float(f.rom_eval([1], [dx]).real)
    only_x_explicit = float(f.rom_eval([1, 2], [dx, 0.0]).real)
    assert only_x == pytest.approx(only_x_explicit, rel=1e-14)

    array_deltas = float(f.rom_eval([1, 2], np.array([dx, dy])).real)
    assert array_deltas == pytest.approx(ordered, rel=1e-14)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_rom_eval_length_mismatch():
    """
    Checks that rom_eval raises ValueError when bases and deltas have different lengths.
    """
    f = _bivariate_number()

    with pytest.raises(ValueError):

        f.rom_eval([1, 2], [0.1])

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


if __name__ == "__main__":

    pytest.main([__file__])

# end if
