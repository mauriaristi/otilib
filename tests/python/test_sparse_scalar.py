"""
Tests scalar OTI creation and basic arithmetic between OTI numbers and real numbers.

Elementary functions and operators up to 6th order are covered in test_sparse_scalar_functions.py.
"""

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


def test_arithmetic_oti_oti():
    """
    Test addition, subtraction, multiplication and division between two OTI numbers.
    """
    x = 3.0 + oti.e(1, order=2)
    y = 2.0 + oti.e(2, order=2)

    # Addition: x + y -> real: 5, dx: 1, dy: 1
    res_add = x + y
    assert float(res_add.real) == pytest.approx(5.0)
    assert float(res_add.get_deriv([1])) == pytest.approx(1.0)
    assert float(res_add.get_deriv([2])) == pytest.approx(1.0)

    # Subtraction: x - y -> real: 1, dx: 1, dy: -1
    res_sub = x - y
    assert float(res_sub.real) == pytest.approx(1.0)
    assert float(res_sub.get_deriv([1])) == pytest.approx(1.0)
    assert float(res_sub.get_deriv([2])) == pytest.approx(-1.0)

    # Multiplication: x * y -> real: 6, dx: 2, dy: 3, dxdy: 1
    res_mul = x * y
    assert float(res_mul.real) == pytest.approx(6.0)
    assert float(res_mul.get_deriv([1])) == pytest.approx(2.0)
    assert float(res_mul.get_deriv([2])) == pytest.approx(3.0)
    assert float(res_mul.get_deriv([1, 2])) == pytest.approx(1.0)

    # Division: x / y -> real: 1.5, dx: 0.5, dy: -0.75
    res_div = x / y
    assert float(res_div.real) == pytest.approx(1.5)
    assert float(res_div.get_deriv([1])) == pytest.approx(0.5)
    assert float(res_div.get_deriv([2])) == pytest.approx(-0.75)

# end function


def test_arithmetic_real_oti():
    """
    Test addition, subtraction, multiplication and division between real and OTI numbers.
    """
    y = 2.0 + oti.e(2, order=2)
    x_r = 4.0

    # Addition: x_r + y -> real: 6, dx: 0, dy: 1
    res_add = x_r + y
    assert float(res_add.real) == pytest.approx(6.0)
    assert float(res_add.get_deriv([1])) == pytest.approx(0.0)
    assert float(res_add.get_deriv([2])) == pytest.approx(1.0)

    # Addition: y + x_r -> real: 6, dx: 0, dy: 1
    res_add = y + x_r
    assert float(res_add.real) == pytest.approx(6.0)
    assert float(res_add.get_deriv([1])) == pytest.approx(0.0)
    assert float(res_add.get_deriv([2])) == pytest.approx(1.0)

    # Subtraction: x_r - y -> real: 2, dx: 0, dy: -1
    res_sub = x_r - y
    assert float(res_sub.real) == pytest.approx(2.0)
    assert float(res_sub.get_deriv([1])) == pytest.approx(0.0)
    assert float(res_sub.get_deriv([2])) == pytest.approx(-1.0)

    # Subtraction: y - x_r -> real: -2, dx: 0, dy: 1
    res_sub = y - x_r
    assert float(res_sub.real) == pytest.approx(-2.0)
    assert float(res_sub.get_deriv([1])) == pytest.approx(0.0)
    assert float(res_sub.get_deriv([2])) == pytest.approx(1.0)

    # Multiplication: x_r * y -> real: 8, dx: 0, dy: 4
    res_mul = x_r * y
    assert float(res_mul.real) == pytest.approx(8.0)
    assert float(res_mul.get_deriv([1])) == pytest.approx(0.0)
    assert float(res_mul.get_deriv([2])) == pytest.approx(4.0)

    # Multiplication: y * x_r -> real: 8, dx: 0, dy: 4
    res_mul = y * x_r
    assert float(res_mul.real) == pytest.approx(8.0)
    assert float(res_mul.get_deriv([1])) == pytest.approx(0.0)
    assert float(res_mul.get_deriv([2])) == pytest.approx(4.0)

    # Division: x_r / y -> real: 2, dx: 0, dy: -1
    res_div = x_r / y
    assert float(res_div.real) == pytest.approx(2.0)
    assert float(res_div.get_deriv([1])) == pytest.approx(0.0)
    assert float(res_div.get_deriv([2])) == pytest.approx(-1.0)

    # Division: y / x_r -> real: 0.5, dx: 0, dy: 0.25
    res_div = y / x_r
    assert float(res_div.real) == pytest.approx(0.5)
    assert float(res_div.get_deriv([1])) == pytest.approx(0.0)
    assert float(res_div.get_deriv([2])) == pytest.approx(0.25)

# end function


if __name__ == "__main__":

    pytest.main([__file__])

# end if
