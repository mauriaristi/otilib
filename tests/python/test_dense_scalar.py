"""
Check dense scalar operations and conversions against the sparse oracle.
"""

import math
import re

import pytest

import pyoti.core as core
import pyoti.dense as dense
import pyoti.semisparse as semi
import pyoti.sparse as sparse


FUNCTIONS = ("sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh", "tanh",
             "asinh", "acosh", "atanh", "exp", "log", "log10", "sqrt", "cbrt", "erf")
ORDERS = (1, 2, 3, 4, 5)


# ********************************************************************************************************
def _plain(text):
    """
    Replace NumPy integer reprs (``np.uint16(3)``) in sparse text by plain integers.

    Parameters
    ----------
    text : str
        Text printed by a sparse number.

    Returns
    -------
    str
        Text with plain integers.
    """

    return re.sub(r"np\.\w+\((\d+)\)", r"\1", text)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _same(actual, expected, order=3):
    """
    Compare the real and all directions through the given order.

    Parameters
    ----------
    actual : otinum
        Dense result.
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
def _same_tight(actual, expected, directions, order):
    """
    Compare the real part and the listed directions at 1e-13 relative tolerance.

    Parameters
    ----------
    actual : otinum
        Dense result.
    expected : sotinum
        Sparse reference.
    directions : list
        Directions to compare.
    order : int
        Highest checked order.
    """

    assert actual.real == pytest.approx(expected.real, rel=1e-13, abs=1e-13)

    for direction in directions:

        if core.imdir(direction)[1] <= order:

            assert actual.get_im(direction) == pytest.approx(
                expected.get_im(direction), rel=1e-13, abs=1e-13)

        # end if

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_scalar_construction_access_and_compaction():
    """
    Check scalar conversion, direction formats, derivatives, and trailing-base trimming.
    """

    original = 1.5 + sparse.e(1, order=3) + 0.25 * sparse.e(3, order=3)
    value = dense.otinum(original)
    _same(value, original)
    assert value.active_bases == (1, 2, 3)
    assert value.nact == 3
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
    assert "otinum" in repr(value)
    assert str(value)
    _same(dense.otinum(value.to_sparse()), original)
    value.set_im(0.0, [[2, 2]])
    assert value.compact().active_bases == (1, 2, 3)

    trailing = dense.e(1, order=3) + dense.e(3, order=3)
    trailing.set_im(0.0, 3)
    assert trailing.nact == 3
    assert trailing.compact().active_bases == (1,)
    assert trailing.compact().order == 3
    assert dense.e(2, order=2).compact().active_bases == (1, 2)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("direction, top", [
    (1, 1), (3, 3), ([1, 2], 2), ([2, 1], 2), ([[1, 2]], 1),
    ([[2, 3]], 2), ([1, 2, 3], 3), ([[1, 2], 3], 3), ([[3, 2], 1], 3),
    ((4, 2), 4), ((3, [2, 2]), 3)])
@pytest.mark.parametrize("order", [0, 1, 3, 5])
def test_e_matches_sparse(direction, top, order):
    """
    Check that dense.e gives the same number and truncation order as sparse.e, over bases 1..top.

    Parameters
    ----------
    direction : object
        Direction in any pyoti.sparse format.
    top : int
        Largest base of the direction.
    order : int
        Requested truncation order.
    """

    expected = sparse.e(direction, order=order)
    value = dense.e(direction, order=order)
    dir_order = core.imdir(direction)[1]

    assert value.order == max(order, dir_order) == expected.order
    assert value.active_bases == tuple(range(1, top + 1))
    assert value.nact == top
    assert value.real == 0.0
    assert value.get_im(direction) == 1.0
    _same(value, expected, order=min(value.order, 3))
    _same(dense.otinum(value.to_sparse()), expected, order=min(value.order, 3))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_e_arguments_and_arithmetic():
    """
    Check the compatibility arguments of e, its errors, and an expression built from it.
    """

    assert dense.e(2, 5).order == 1
    assert dense.e(2, nbases=5, order=2).active_bases == (1, 2)
    assert dense.e([], order=2).real == 1.0
    assert dense.e([], order=2).active_bases == ()

    with pytest.raises(ValueError):

        dense.e(1, order=256)

    # end with

    with pytest.raises(ValueError):

        dense.e(1, order=-1)

    # end with

    with pytest.raises(TypeError):

        dense.e(1, order=1.5)

    # end with

    value = 2.0 + dense.e(1, order=3) * dense.e(4, order=3) - 0.5 * dense.e([[4, 2]], order=3)
    expected = 2.0 + sparse.e(1, order=3) * sparse.e(4, order=3) - 0.5 * sparse.e([[4, 2]], order=3)
    assert value.active_bases == (1, 2, 3, 4)
    _same(value, expected)

    assert dense.e(65535, order=1).active_bases[-1] == 65535
    assert dense.e(65535, order=1).get_im(65535) == 1.0
    assert (dense.e(40, order=2) ** 2).get_im([[40, 2]]) == pytest.approx(1.0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_e_gauss_points():
    """
    Check the Gauss-point scalar created by e(nip=...) once the Gauss types exist.
    """

    try:

        points = dense.e(1, order=2, nip=4)

    except NotImplementedError:

        pytest.skip("Gauss-point types are not implemented yet for pyoti.dense")

    # end try

    assert points.nip == 4
    assert points.order == 2

    for point in range(4):

        assert points[point].get_im(1) == 1.0
        assert points[point].active_bases == (1,)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("direction", [1, 3, [1, 2], [[2, 3]], [[1, 2], 3], (4, 2)])
def test_rawdir_matches_human_direction(direction):
    """
    Check that rawdir(index, order) addresses the same direction as the human form everywhere.

    Parameters
    ----------
    direction : object
        Direction in any pyoti.sparse format.
    """

    index, order = core.imdir(direction)
    raw = dense.rawdir(index, order)

    assert raw == dense.rawdir.from_direction(direction)
    assert raw.bases == tuple(core.expand_imdir(direction))
    assert hash(raw) == hash((index, order))
    assert repr(raw) == f"rawdir({index}, {order})"

    value = dense.e(raw, order=4)
    assert value.active_bases == tuple(range(1, max(raw.bases) + 1))
    assert value.get_im(raw) == value.get_im(direction) == 1.0
    value.set_im(0.25, raw)
    assert value.get_im(direction) == 0.25
    assert value.get_deriv(raw) == pytest.approx(value.get_deriv(direction))
    assert value.truncate(raw).get_im(direction) == 0.0
    assert dense.imdir(raw) == [index, order]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_rawdir_errors_and_tuple_meaning():
    """
    Check rawdir validation and that a plain tuple still means a list of bases.
    """

    with pytest.raises(ValueError):

        dense.rawdir(65535, 1)

    # end with

    with pytest.raises(ValueError):

        dense.rawdir(1, 0)

    # end with

    with pytest.raises(ValueError):

        dense.rawdir(0, 151)

    # end with

    with pytest.raises(TypeError):

        dense.rawdir(1.5, 1)

    # end with

    assert dense.rawdir(0, 150).bases == (1,) * 150
    assert dense.rawdir(0, 0).bases == ()
    assert dense.e((4, 2)).active_bases == (1, 2, 3, 4)
    assert dense.e(dense.rawdir(4, 2)).active_bases == (1, 2, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("relation", ("same", "leading", "wider", "interleaved"))
def test_scalar_algebra(relation, order):
    """
    Compare scalar operations over identical, leading, wider and interleaved base sets.

    Parameters
    ----------
    relation : str
        Base-set relationship between the operands (bases up to 6 in the interleaved case).
    order : int
        Truncation order.
    """

    left = 1.4 + sparse.e(1, order=order)
    right = 2.0 + sparse.e(2 if relation == "wider" else 1, order=order)

    if relation == "same":

        left += sparse.e(2, order=order)
        right += sparse.e(2, order=order)

    elif relation == "leading":

        right += sparse.e(2, order=order)

    elif relation == "interleaved":

        left += sparse.e(3, order=order) + sparse.e(5, order=order)
        right += sparse.e(2, order=order) + sparse.e(4, order=order) + sparse.e(6, order=order)

    # end if

    a = dense.otinum(left)
    b = dense.otinum(right)
    directions = [1, 2, 3, [1, 2], [1, 3], [2, 4], [3, 5], [2, 6], [[1, 2]], [[2, 2]], [1, 2, 3],
                  [[1, 2], 2], [4, 5, 6]]

    for actual, expected in ((a + b, left + right), (a - b, left - right),
                             (a * b, left * right), (a / b, left / right),
                             (a + 1.3, left + 1.3), (1.3 - a, 1.3 - left),
                             (a * 1.3, left * 1.3), (1.3 / a, 1.3 / left),
                             (a ** 1.5, left ** 1.5), (-a, -left),
                             (a + right, left + right), (right * a, right * left),
                             (2 + a, 2 + left), (a - 2, left - 2), (2 * a, 2 * left)):

        assert actual.order == expected.order
        _same_tight(actual, expected, directions, order)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_scalar_mixed_orders_and_active_orders():
    """
    Check the result truncation order (max), nact (max) and the act_order upper bounds.
    """

    low = dense.e(1, order=2) * 2.0 + 1.0
    high = dense.e(2, order=5) + dense.e(1, order=5) * dense.e(2, order=5)
    sparse_low = sparse.e(1, order=2) * 2.0 + 1.0
    sparse_high = sparse.e(2, order=5) + sparse.e(1, order=5) * sparse.e(2, order=5)

    assert low.actual_order == 1
    assert high.actual_order == 2

    for total, expected in ((low + high, sparse_low + sparse_high),
                            (high + low, sparse_high + sparse_low),
                            (low - high, sparse_low - sparse_high),
                            (low * high, sparse_low * sparse_high),
                            (high * low, sparse_high * sparse_low),
                            (high / low, sparse_high / sparse_low)):

        assert total.order == 5
        assert total.nact == 2
        _same_tight(total, expected, [1, 2, [1, 2], [[2, 2]], [[1, 2], 2]], 5)

    # end for

    assert (low + high).actual_order <= 2
    assert (low * high).actual_order <= 3
    assert (high * high).actual_order <= 4
    assert dense.exp(low).actual_order <= 5

    reduced = high.truncate_order(2)
    assert reduced.order == 5
    assert reduced.actual_order <= 1
    assert reduced.nact == high.nact
    assert reduced.get_im([1, 2]) == 0.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_nact_growth():
    """
    Check that products, sums and assignments grow the number of active bases.
    """

    product = dense.e(3, order=2) * dense.e(1, order=2)

    assert product.nact == 3
    assert product.active_bases == (1, 2, 3)
    assert product.get_im([1, 3]) == 1.0
    assert (dense.e(1, order=2) + dense.e(4, order=2)).nact == 4
    assert (dense.e(4, order=2) - 1.0).nact == 4

    value = dense.number(1.0, order=3)
    assert value.nact == 0
    value.set_im(2.0, 2)
    assert value.nact == 2
    value.set_im(3.0, [[5, 2]])
    assert value.nact == 5
    assert value.get_im(2) == 2.0
    assert value.get_im([[5, 2]]) == 3.0
    value.set_im(4.0, 9)
    assert value.nact == 9
    assert value.get_im(2) == 2.0
    assert value.get_im([[5, 2]]) == 3.0
    value.set_im(0.0, 20)
    assert value.nact == 9
    value[core.imdir([1, 7])] = 0.5
    assert value.get_im([1, 7]) == 0.5

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", FUNCTIONS)
@pytest.mark.parametrize("order", (1, 3, 5))
def test_scalar_functions(name, order):
    """
    Compare every scalar function against the sparse implementation.

    Parameters
    ----------
    name : str
        Function name.
    order : int
        Truncation order.
    """

    center = 0.25 if name in ("asin", "acos", "atanh") else 1.5
    original = center + 0.02 * sparse.e(1, order=order) + 0.03 * sparse.e(2, order=order)
    actual = getattr(dense, name)(dense.otinum(original))
    expected = getattr(sparse, name)(original)
    assert actual.order == expected.order
    _same(actual, expected, order=3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_scalar_power_logb_and_truncation():
    """
    Match sparse power, logarithm, order extraction, and direction truncation.
    """

    original = 1.5 + sparse.e(1, order=3) + sparse.e(2, order=3)
    original = original * original
    value = dense.otinum(original)
    _same(dense.pow(value, 2.3), sparse.pow(original, 2.3))
    _same(dense.logb(value, math.e), sparse.logb(original, math.e))
    _same(value.truncate([1, 2]), sparse.truncate([1, 2], original))
    _same(value.truncate_order(2), original.truncate_order(2), order=1)
    _same(value.get_order_im(2), original.get_order_im(2))
    _same(value ** dense.otinum(1.5 + 0.1 * sparse.e(1, order=3)),
          original ** (1.5 + 0.1 * sparse.e(1, order=3)))
    _same(2.0 ** value, 2.0 ** original)
    _same(value.extract_im(1), original.extract_im(1), order=2)
    _same(value.extract_deriv([[2, 1]]), original.extract_deriv([[2, 1]]), order=2)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_scalar_copy_set_and_items():
    """
    Check copies, in-place replacement, raw-direction items and in-place operators.
    """

    original = 0.5 + sparse.e(1, order=3) + 2.0 * sparse.e(2, order=3)
    value = dense.otinum(original)
    twin = value.copy()

    twin.set_im(7.0, 1)
    assert value.get_im(1) == 1.0
    assert twin.get_im(1) == 7.0

    twin.set(2.5)
    assert twin.real == 2.5
    assert twin.order == 3
    assert twin.nnz == 1

    twin.set(value)
    assert twin.get_im(2) == 2.0
    twin.set(original)
    assert twin.get_im(2) == 2.0

    twin.real = 4.0
    assert twin.real == 4.0
    assert value[core.imdir(2)] == 2.0
    assert value[dense.rawdir(*core.imdir(2))] == 2.0
    value[[0, 1]] = 9.0
    assert value.get_im(1) == 9.0

    with pytest.raises(TypeError):

        value["x"]

    # end with

    with pytest.raises(TypeError):

        dense.otinum("x")

    # end with

    alias = value
    value += 1.0
    assert value is not alias
    assert value.real == alias.real + 1.0
    value -= 1.0
    value *= 2.0
    value /= 2.0
    assert value.real == pytest.approx(alias.real)
    assert dense.otinum(value).get_im(1) == 9.0
    assert dense.otinum(value) is not value

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_scalar_text_and_counts():
    """
    Check the printed form against sparse and the counting helpers.
    """

    original = 2.0 + sparse.e(1, order=3) + 3.0 * sparse.e([[1, 2], 3], order=3)
    value = dense.otinum(original)

    assert str(value) == _plain(str(original))
    assert value.nnz == 3
    assert value.actual_order == 3
    assert value.short_repr().startswith("otinum(")
    assert "truncation order: 3" in value.long_repr()

    info = value.get_nnz_full()
    assert info[0] == 3
    assert list(info[2]) == [1, 0, 1]
    assert info[3][0] == 3

    dense.set_printoptions(terms_print=1)

    try:

        assert str(value) == _plain(str(original))

    finally:

        dense.set_printoptions()

    # end try

    assert dense.otinum(1.5).real == 1.5
    assert dense.otinum(2, order=4).order == 4
    assert dense.otinum(2, order=4).get_active_bases() == []

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_high_order_global_direction():
    """
    Address higher basis labels with the colex rank beyond sparse helper table coverage.
    """

    value = dense.otinum(2.0, order=6)
    value.set_im(0.125, [[20, 6]])
    assert value.active_bases == tuple(range(1, 21))
    assert value.get_im([[20, 6]]) == pytest.approx(0.125)
    assert value.get_deriv([[20, 6]]) == pytest.approx(0.125 * math.factorial(6))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_maximum_order_and_oversized_requests():
    """
    Check that trc 150 works, 151 is refused, and oversized requests raise instead of exiting.
    """

    top = dense.otinum(1.5, order=150)
    assert top.order == 150
    assert (top + 1.0).order == 150
    assert (dense.e(1, order=150) * 2.0).get_im(dense.rawdir(0, 150)) == 0.0
    assert dense.e(1, order=150).get_im(dense.rawdir(0, 150)) == 0.0
    assert dense.e(dense.rawdir(0, 150), order=0).order == 150
    half = dense.e(dense.rawdir(0, 75), order=150)
    squared = half * half
    assert squared.get_im(dense.rawdir(0, 150)) == 1.0
    assert (dense.e(1, order=150) ** 2).order == 150

    with pytest.raises(ValueError):

        dense.otinum(1.5, order=151)

    # end with

    with pytest.raises(ValueError):

        dense.e(1, order=151)

    # end with

    with pytest.raises(ValueError):

        dense.number(1.0, order=151)

    # end with

    with pytest.raises(ValueError):

        dense.e(70000)

    # end with

    with pytest.raises(MemoryError):

        dense.e(65535, order=150)

    # end with

    with pytest.raises(MemoryError):

        dense.zeros((2, 2), order=150, bases=(65535,))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_product_beyond_global_table_matches_semisparse():
    """
    Check products whose active bases exceed the global multiplication table (11 bases at order 5).
    """

    directions = [1, 5, 11, [1, 5], [1, 11], [[11, 2]], [5, 11], [[11, 3]], [1, 5, 11],
                  [[11, 2], 5], [[11, 4], 1], [[11, 5]], [1, 5, 11, 11]]

    for order in (2, 3, 5):

        left = dense.number(1.5, order=order) + dense.e(11, order=order) + dense.e(1, order=order)
        right = dense.number(0.5, order=order) + dense.e(5, order=order) * 2.0 + dense.e(11, order=order)
        semi_left = semi.number(1.5, order=order) + semi.e(11, order=order) + semi.e(1, order=order)
        semi_right = (semi.number(0.5, order=order) + semi.e(5, order=order) * 2.0
                      + semi.e(11, order=order))

        assert left.nact == 11

        for actual, expected in ((left * right, semi_left * semi_right),
                                 (left / right, semi_left / semi_right),
                                 (left ** 1.5, semi_left ** 1.5),
                                 (dense.exp(left), semi.exp(semi_left))):

            assert actual.real == pytest.approx(expected.real, rel=1e-14)

            for direction in directions:

                if dense.imdir(direction)[1] <= order:

                    assert actual.get_im(direction) == pytest.approx(
                        expected.get_im(direction), rel=1e-13, abs=1e-14)

                # end if

            # end for

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_high_order_global_direction_without_sparse_helper_table():
    """
    Address a high basis label at order 6: the dense number grows to nact 20 (beyond the sparse
    helper tables) and keeps the coefficient.
    """

    value = dense.otinum(2.0, order=6)
    value.set_im(0.125, [[20, 6]])

    assert value.nact == 20
    assert value.active_bases == tuple(range(1, 21))
    assert value.order == 6
    assert value.get_im([[20, 6]]) == pytest.approx(0.125)
    assert value.get_deriv([[20, 6]]) == pytest.approx(0.125 * math.factorial(6))
    assert value.real == pytest.approx(2.0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_request_above_the_memory_budget_raises_memory_error():
    """
    A representable request far above the memory budget (e(1000, order=4) needs 314 GiB) raises
    MemoryError instead of letting an overcommitted allocation kill the process.
    """

    with pytest.raises(MemoryError):

        dense.e(1000, order=4)

    # end with

    with pytest.raises(MemoryError):

        dense.zeros((1000, 1000), bases=(1000,), order=2)

    # end with

    small = dense.e(3, order=2)
    assert small.nact == 3

# end function
# --------------------------------------------------------------------------------------------------------
