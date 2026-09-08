"""
Tests static compile-time fixed-order/basis OTI modules.
"""

import numpy as np
import pytest
import pyoti.static.onumm1n1 as st11
import pyoti.static.onumm2n2 as st22
import pyoti.static.onumm3n2 as st32


def test_static_onumm1n1_exp():
    """
    Test onumm1n1 (1 basis, order 1) exponential.
    """
    x = st11.onumm1n1(1.5)
    x += st11.e(1)
    f = st11.exp(x)

    assert float(f.real) == pytest.approx(np.exp(1.5), abs=1e-7)
    assert float(f.get_deriv([1])) == pytest.approx(np.exp(1.5), abs=1e-7)

# end function


def test_static_onumm2n2_multivariate():
    """
    Test onumm2n2 (2 bases, order 2) multivariate sine.
    """
    x = st22.onumm2n2(2.0)
    x += st22.e(1)
    y = st22.onumm2n2(3.0)
    y += st22.e(2)

    f = st22.sin(x * y)

    expected_val = np.sin(6.0)
    expected_dx = 3.0 * np.cos(6.0)
    expected_dy = 2.0 * np.cos(6.0)
    expected_dxdy = np.cos(6.0) - 6.0 * np.sin(6.0)

    assert float(f.real) == pytest.approx(expected_val, abs=1e-7)
    assert float(f.get_deriv([1])) == pytest.approx(expected_dx, abs=1e-7)
    assert float(f.get_deriv([2])) == pytest.approx(expected_dy, abs=1e-7)
    assert float(f.get_deriv([1, 2])) == pytest.approx(expected_dxdy, abs=1e-7)

# end function


def test_static_onumm3n2_product():
    """
    Test onumm3n2 (3 bases, order 2) three-variable product: f(x,y,z) = x*y*z.
    """
    x = st32.onumm3n2(1.0)
    x += st32.e(1)
    y = st32.onumm3n2(2.0)
    y += st32.e(2)
    z = st32.onumm3n2(3.0)
    z += st32.e(3)

    f = x * y * z

    assert float(f.real) == pytest.approx(6.0)
    assert float(f.get_deriv([1])) == pytest.approx(6.0)
    assert float(f.get_deriv([2])) == pytest.approx(3.0)
    assert float(f.get_deriv([3])) == pytest.approx(2.0)
    assert float(f.get_deriv([1, 2])) == pytest.approx(3.0)
    assert float(f.get_deriv([1, 3])) == pytest.approx(2.0)
    assert float(f.get_deriv([2, 3])) == pytest.approx(1.0)

# end function


if __name__ == "__main__":

    pytest.main([__file__])

# end if
