"""
Check semi-sparse scalar operations and conversions against the sparse oracle.
"""

import math

import pytest

import pyoti.core as core
import pyoti.semisparse as semi
import pyoti.sparse as sparse


FUNCTIONS = ("sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh", "tanh",
             "asinh", "acosh", "atanh", "exp", "log", "log10", "sqrt", "cbrt", "erf")


# ********************************************************************************************************
def _same(actual, expected, order=3):
    """
    Compare the real and all directions through the given order.

    Parameters
    ----------
    actual : ssotinum
        Semi-sparse result.
    expected : sotinum
        Sparse reference.
    order : int
        Highest checked order.
    """

    assert actual.real == pytest.approx(expected.real, rel=1e-9, abs=1e-10)

    for direction in (1, 2, 3, [1, 2], [1, 3], [2, 3], [[1, 2]], [[2, 2]],
                      [[3, 2]], [1, 2, 3], [[1, 2], 2], [[2, 2], 3]):

        if core.imdir(direction)[1] <= order:

            assert actual.get_im(direction) == pytest.approx(
                expected.get_im(direction), rel=1e-9, abs=1e-10)

        # end if

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_scalar_construction_access_and_compaction():
    """
    Check scalar conversion, direction formats, derivatives, and active-set pruning.
    """

    original = 1.5 + sparse.e(1, order=3) + 0.25 * sparse.e(3, order=3)
    value = semi.ssotinum(original)
    _same(value, original)
    assert value.active_bases == (1, 3)
    assert value.order == 3
    assert value.get_im((1,)) == pytest.approx(1.0)
    value.set_im(0.3, [1, 3])
    original.set_im(0.3, [1, 3])
    value.set_im(0.4, [[2, 2]])
    original.set_im(0.4, [[2, 2]])
    assert value.active_bases == (1, 2, 3)
    _same(value, original)
    assert value.get_deriv([[2, 2]]) == pytest.approx(0.8)
    assert value.density > 0.0
    assert "ssotinum" in repr(value)
    assert str(value)
    _same(semi.ssotinum(value.to_sparse()), original)
    value.set_im(0.0, [[2, 2]])
    assert value.compact().active_bases == (1, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("direction, labels", [
    (1, (1,)), (3, (3,)), ([1, 2], (1, 2)), ([2, 1], (1, 2)), ([[1, 2]], (1,)),
    ([[2, 3]], (2,)), ([1, 2, 3], (1, 2, 3)), ([[1, 2], 3], (1, 3)), ([[3, 2], 1], (1, 3)),
    ((4, 2), (2, 4)), ((3, [2, 2]), (2, 3))])
@pytest.mark.parametrize("order", [0, 1, 3, 5])
def test_e_matches_sparse(direction, labels, order):
    """
    Check that semi.e gives the same number, truncation order, and active set as sparse.e.
    """

    expected = sparse.e(direction, order=order)
    value = semi.e(direction, order=order)
    dir_order = core.imdir(direction)[1]

    assert value.order == max(order, dir_order) == expected.order
    assert value.active_bases == labels
    assert value.real == 0.0
    assert value.get_im(direction) == 1.0
    _same(value, expected, order=min(value.order, 3))
    _same(semi.ssotinum(value.to_sparse()), expected, order=min(value.order, 3))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_e_arguments_and_arithmetic():
    """
    Check the compatibility arguments of e, its errors, and an expression built from it.
    """

    assert semi.e(2, 5).order == 1
    assert semi.e(2, nbases=5, order=2).active_bases == (2,)
    assert semi.e([], order=2).real == 1.0
    assert semi.e([], order=2).active_bases == ()

    points = semi.e(1, order=2, nip=4)
    assert isinstance(points, semi.ssotife)
    assert points.nip == 4
    assert points.order == 2

    for point in range(4):

        assert points[point].get_im(1) == 1.0
        assert points[point].active_bases == (1,)

    # end for

    with pytest.raises(ValueError):

        semi.e(1, order=256)

    # end with

    value = 2.0 + semi.e(1, order=3) * semi.e(4, order=3) - 0.5 * semi.e([[4, 2]], order=3)
    expected = 2.0 + sparse.e(1, order=3) * sparse.e(4, order=3) - 0.5 * sparse.e([[4, 2]], order=3)
    assert value.active_bases == (1, 4)
    _same(value, expected)

    assert semi.e(65535, order=2).active_bases == (65535,)
    assert (semi.e(65535, order=2) ** 2).get_im([[65535, 2]]) == pytest.approx(1.0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("direction", [1, 3, [1, 2], [[2, 3]], [[1, 2], 3], (4, 2), [65535]])
def test_rawdir_matches_human_direction(direction):
    """
    Check that rawdir(index, order) addresses the same direction as the human form everywhere.
    """

    index, order = core.imdir(direction) if direction != [65535] else (65534, 1)
    raw = semi.rawdir(index, order)

    assert raw == semi.rawdir.from_direction(direction)
    assert raw.bases == tuple(core.expand_imdir(direction))
    assert hash(raw) == hash((index, order))
    assert repr(raw) == f"rawdir({index}, {order})"

    value = semi.e(raw, order=4)
    assert value.active_bases == tuple(sorted(set(raw.bases)))
    assert value.get_im(raw) == value.get_im(direction) == 1.0
    value.set_im(0.25, raw)
    assert value.get_im(direction) == 0.25
    assert value.get_deriv(raw) == pytest.approx(value.get_deriv(direction))
    assert value.truncate(raw).get_im(direction) == 0.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_rawdir_errors_and_tuple_meaning():
    """
    Check rawdir validation and that a plain tuple still means a list of bases.
    """

    with pytest.raises(ValueError):

        semi.rawdir(65535, 1)

    # end with

    with pytest.raises(ValueError):

        semi.rawdir(1, 0)

    # end with

    with pytest.raises(ValueError):

        semi.rawdir(0, 256)

    # end with

    with pytest.raises(TypeError):

        semi.rawdir(1.5, 1)

    # end with

    assert semi.rawdir(0, 0).bases == ()
    assert semi.e((4, 2)).active_bases == (2, 4)
    assert semi.e(semi.rawdir(4, 2)).active_bases == (2, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("relation", ("same", "leading", "interleaved"))
def test_scalar_algebra(relation):
    """
    Compare scalar operations over identical, leading, and interleaved sets.

    Parameters
    ----------
    relation : str
        Active-set relationship between operands.
    """

    left = 1.4 + sparse.e(1, order=3)
    right = 2.0 + sparse.e(2 if relation == "interleaved" else 1, order=3)

    if relation == "same":

        left += sparse.e(2, order=3)
        right += sparse.e(2, order=3)

    elif relation == "leading":

        right += sparse.e(2, order=3)

    # end if

    a = semi.ssotinum(left)
    b = semi.ssotinum(right)

    for actual, expected in ((a + b, left + right), (a - b, left - right),
                             (a * b, left * right), (a / b, left / right),
                             (a + 1.3, left + 1.3), (1.3 - a, 1.3 - left),
                             (a * 1.3, left * 1.3), (1.3 / a, 1.3 / left),
                             (a ** 1.5, left ** 1.5), (-a, -left),
                             (a + right, left + right)):

        _same(actual, expected)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", FUNCTIONS)
def test_scalar_functions(name):
    """
    Compare every scalar function against the sparse implementation.

    Parameters
    ----------
    name : str
        Function name.
    """

    center = 0.25 if name in ("asin", "acos", "atanh") else 1.5
    original = center + 0.02 * sparse.e(1, order=3) + 0.03 * sparse.e(2, order=3)
    actual = getattr(semi, name)(semi.ssotinum(original))
    expected = getattr(sparse, name)(original)
    _same(actual, expected)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_scalar_power_logb_and_truncation():
    """
    Match sparse power, logarithm, order extraction, and direction truncation.
    """

    original = 1.5 + sparse.e(1, order=3) + sparse.e(2, order=3)
    original = original * original
    value = semi.ssotinum(original)
    _same(semi.pow(value, 2.3), sparse.pow(original, 2.3))
    _same(semi.logb(value, math.e), sparse.logb(original, math.e))
    _same(value.truncate([1, 2]), sparse.truncate([1, 2], original))
    _same(value.truncate_order(2), original.truncate_order(2), order=1)
    _same(value.get_order_im(2), original.get_order_im(2))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_high_order_global_direction_without_sparse_helper_table():
    """
    Address higher basis labels with the colex rank beyond sparse helper table coverage.
    """

    value = semi.ssotinum(2.0, order=6)
    value.set_im(0.125, [[20, 6]])
    assert value.active_bases == (20,)
    assert value.get_im([[20, 6]]) == pytest.approx(0.125)
    assert value.get_deriv([[20, 6]]) == pytest.approx(0.125 * math.factorial(6))

# end function
# --------------------------------------------------------------------------------------------------------
