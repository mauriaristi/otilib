"""
Tests dense dynamic OTI implementation.
"""

import pytest
import pyoti.dense as d


def test_dense_otinum_creation():
    """
    Test creating dense otinum instances with specified order and basis.
    """
    x = d.otinum(4.0, 2, 2)
    assert x.order == 2
    assert x.nbases == 2

# end function


def test_dense_arithmetic():
    """
    Test arithmetic on dense OTI numbers.
    """
    x = d.otinum(4.0, 2, 2)
    y = d.otinum(2.0, 2, 2)

    # Addition retains order
    res_add = x + y
    assert res_add.order == 2

    # Dynamic dense multiplication expands maximum order (2 + 2 = 4)
    res_mul = x * y
    assert res_mul.order == 4

# end function


def test_dense_functions():
    """
    Test mathematical functions on dense numbers.
    """
    x = d.otinum(0.0, 2, 2)
    f_sin = d.sin(x)
    assert f_sin.order == 2

# end function


if __name__ == "__main__":

    pytest.main([__file__])

# end if
