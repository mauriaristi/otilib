"""
Tests array and matrix operations with sparse OTI numbers.
"""

import numpy as np
import pytest
import pyoti.sparse as oti


def test_array_creation_and_indexing():
    """
    Test creating 2D OTI arrays and indexing.
    """
    data = [[1.0, 2.0], [3.0, 4.0]]
    x = oti.array(data)
    re = np.array(x.real)
    np.testing.assert_allclose(re, np.array(data))

# end function


def test_elementwise_functions():
    """
    Test applying elemental functions (sin, exp) over OTI arrays.
    """
    data = np.array([[0.0, np.pi / 6.0], [np.pi / 4.0, np.pi / 2.0]])
    x = oti.array(data)
    x += oti.e(1)

    f = oti.sin(x)
    re = np.array(f.real)
    im1 = np.array(f.get_im(1))

    np.testing.assert_allclose(re, np.sin(data), rtol=1e-6)
    np.testing.assert_allclose(im1, np.cos(data), rtol=1e-6)

# end function


def test_matrix_inversion():
    """
    Test matrix inversion and derivative propagation through inv().
    """
    A = oti.array([[2.0, 0.0], [0.0, 4.0]])
    A[0, 0] += oti.e(1)

    Ainv = oti.inv(A)
    re_inv = np.array(Ainv.real)
    im_inv = np.array(Ainv.get_im(1))

    # (2 + e1)^(-1) = 0.5 - 0.25*e1
    assert re_inv[0, 0] == pytest.approx(0.5)
    assert im_inv[0, 0] == pytest.approx(-0.25)
    assert re_inv[1, 1] == pytest.approx(0.25)
    assert im_inv[1, 1] == pytest.approx(0.0)

# end function


if __name__ == "__main__":

    pytest.main([__file__])

# end if
