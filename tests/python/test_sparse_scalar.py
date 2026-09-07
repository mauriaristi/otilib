"""
Tests scalar OTI arithmetic, elementary functions, and high-order derivative extraction.
"""

import numpy as np
import pytest
import pyoti.sparse as oti


def test_scalar_creation():
    """
    Test creating scalar OTI numbers and perturbations.
    """
    x = 3.5 + oti.e(1)
    assert float(x.real) == pytest.approx(3.5)
    assert float(x.get_im(1)) == pytest.approx(1.0)

# end function


def test_arithmetic_operations():
    """
    Test basic arithmetic: addition, subtraction, multiplication, division.
    """
    x = 3.0 + oti.e(1, order=2)
    y = 2.0 + oti.e(2, order=2)

    # Addition: (x + y) -> real: 5, dx: 1, dy: 1
    res_add = x + y
    assert float(res_add.real) == pytest.approx(5.0)
    assert float(res_add.get_deriv([1])) == pytest.approx(1.0)
    assert float(res_add.get_deriv([2])) == pytest.approx(1.0)

    # Subtraction: (x - y) -> real: 1, dx: 1, dy: -1
    res_sub = x - y
    assert float(res_sub.real) == pytest.approx(1.0)
    assert float(res_sub.get_deriv([1])) == pytest.approx(1.0)
    assert float(res_sub.get_deriv([2])) == pytest.approx(-1.0)

    # Multiplication: (x * y) -> real: 6, dx: 2, dy: 3, dxdy: 1
    res_mul = x * y
    assert float(res_mul.real) == pytest.approx(6.0)
    assert float(res_mul.get_deriv([1])) == pytest.approx(2.0)
    assert float(res_mul.get_deriv([2])) == pytest.approx(3.0)
    assert float(res_mul.get_deriv([1, 2])) == pytest.approx(1.0)

    # Division: (x / y) -> real: 1.5, dx: 0.5, dy: -0.75
    res_div = x / y
    assert float(res_div.real) == pytest.approx(1.5)
    assert float(res_div.get_deriv([1])) == pytest.approx(0.5)
    assert float(res_div.get_deriv([2])) == pytest.approx(-0.75)

# end function


def test_power():
    """
    Test power operation: f(x) = x^3 at x = 2.
    """
    x = 2.0 + oti.e(1, order=3)
    f = x**3
    assert float(f.real) == pytest.approx(8.0)
    assert float(f.get_deriv([1])) == pytest.approx(12.0)
    assert float(f.get_deriv([1, 1])) == pytest.approx(12.0)
    assert float(f.get_deriv([1, 1, 1])) == pytest.approx(6.0)

# end function


def test_trigonometric_functions():
    """
    Test trigonometric functions: sin, cos, tan.
    """
    x = (np.pi / 4.0) + oti.e(1, order=2)
    f_sin = oti.sin(x)
    expected_val = np.sin(np.pi / 4.0)
    expected_d1 = np.cos(np.pi / 4.0)
    expected_d2 = -np.sin(np.pi / 4.0)

    assert float(f_sin.real) == pytest.approx(expected_val, abs=1e-7)
    assert float(f_sin.get_deriv([1])) == pytest.approx(expected_d1, abs=1e-7)
    assert float(f_sin.get_deriv([1, 1])) == pytest.approx(expected_d2, abs=1e-7)

    f_cos = oti.cos(x)
    assert float(f_cos.real) == pytest.approx(np.cos(np.pi / 4.0), abs=1e-7)
    assert float(f_cos.get_deriv([1])) == pytest.approx(-np.sin(np.pi / 4.0), abs=1e-7)

# end function


def test_exponential_and_log():
    """
    Test exp and log: f(x, y) = exp(x*y) at (1, 2).
    """
    x = 1.0 + oti.e(1, order=2)
    y = 2.0 + oti.e(2, order=2)
    f = oti.exp(x * y)

    expected_val = np.exp(2.0)
    expected_dx = 2.0 * np.exp(2.0)
    expected_dy = 1.0 * np.exp(2.0)
    expected_dxdy = 3.0 * np.exp(2.0)
    expected_dx2 = 4.0 * np.exp(2.0)

    assert float(f.real) == pytest.approx(expected_val, abs=1e-7)
    assert float(f.get_deriv([1])) == pytest.approx(expected_dx, abs=1e-7)
    assert float(f.get_deriv([2])) == pytest.approx(expected_dy, abs=1e-7)
    assert float(f.get_deriv([1, 2])) == pytest.approx(expected_dxdy, abs=1e-7)
    assert float(f.get_deriv([1, 1])) == pytest.approx(expected_dx2, abs=1e-7)

    f_log = oti.log(x)
    assert float(f_log.real) == pytest.approx(0.0, abs=1e-7)
    assert float(f_log.get_deriv([1])) == pytest.approx(1.0, abs=1e-7)
    assert float(f_log.get_deriv([1, 1])) == pytest.approx(-1.0, abs=1e-7)

# end function


def test_sqrt():
    """
    Test square root function.
    """
    x = 4.0 + oti.e(1, order=2)
    f = oti.sqrt(x)
    assert float(f.real) == pytest.approx(2.0)
    assert float(f.get_deriv([1])) == pytest.approx(0.25)
    assert float(f.get_deriv([1, 1])) == pytest.approx(-1.0 / 32.0)

# end function


if __name__ == "__main__":

    pytest.main([__file__])

# end if
