"""
Check dense Gauss-point scalars and arrays against the sparse Gauss oracle.

Port of test_semisparse_gauss.py. A dense value is dense over the bases 1..nact, so the semi-sparse
"interleaved" sets ({1, 3, 5} and {2, 4, 6}) give a larger nact, the active bases are [1, ..., nact],
and every comparison runs over every direction of the bases 1..max(bases).
"""

from itertools import combinations_with_replacement

import numpy as np
import pytest

import pyoti.sparse as sp
import pyoti.dense as dn


ORDERS = (1, 2, 3, 4, 5)
NIPS = (1, 4, 9)
ACTIVE_PAIRS = (
    ("same", (1, 2, 3), (1, 2, 3)),
    ("leading", (1, 2), (1, 2, 3, 4)),
    ("interleaved", (1, 3, 5), (2, 4, 6)),
)
SHAPES = ((1, 1), (1, 4), (4, 1), (2, 2), (3, 3), (4, 4), (2, 3))
RTOL = 1e-13
ATOL = 1e-13
SCENARIOS = [
    (order, label, left, right, NIPS[index % len(NIPS)],
     SHAPES[index % len(SHAPES)])
    for index, (order, (label, left, right)) in enumerate(
        (item for order in ORDERS for item in [(order, pair) for pair in ACTIVE_PAIRS])
    )
]
LINALG_SCENARIOS = [
    (order, label, left, right, nip, (index % 4 + 1, index % 4 + 1))
    for index, (order, label, left, right, nip, _) in enumerate(SCENARIOS)
]
DOT_SHAPE_PAIRS = (
    ((1, 1), (1, 1)),
    ((1, 4), (4, 1)),
    ((4, 1), (1, 4)),
    ((2, 2), (2, 3)),
    ((3, 3), (3, 1)),
    ((4, 4), (4, 3)),
    ((2, 3), (3, 2)),
)
DOT_SCENARIOS = [
    (order, label, left, right, nip, DOT_SHAPE_PAIRS[index % len(DOT_SHAPE_PAIRS)])
    for index, (order, label, left, right, nip, _) in enumerate(SCENARIOS)
]
UNARY_FUNCTIONS = (
    "sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh", "tanh", "asinh", "acosh",
    "atanh", "exp", "log", "log10", "sqrt", "cbrt", "erf",
)
UNARY_DOMAINS = {
    "asin": (0.1, 0.4),
    "acos": (0.1, 0.4),
    "atanh": (0.1, 0.4),
    "acosh": (1.2, 1.8),
}


# ********************************************************************************************************
def _directions(bases, order):
    """
    Enumerate all nonconstant directions through an order over the bases 1..max(bases).

    A dense value is dense over 1..nact, so every direction below the largest label is checked, not
    only those over the labels themselves.

    Parameters
    ----------
    bases : tuple of int
        Sorted, one-based global basis labels.
    order : int
        Highest order to enumerate.

    Returns
    -------
    list of tuple
        Directions in nondecreasing basis order.
    """

    result = []
    dense_bases = tuple(range(1, max(bases) + 1)) if len(bases) > 0 else ()

    for degree in range(1, order + 1):

        result.extend(combinations_with_replacement(dense_bases, degree))

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _random_scalar(bases, order, seed, real=1.0):
    """
    Build a reproducible sparse scalar with active terms over the requested bases.

    Parameters
    ----------
    bases : tuple of int
        Bases used by the scalar.
    order : int
        Truncation order.
    seed : int
        Random generator seed.
    real : float
        Real coefficient.

    Returns
    -------
    sotinum
        Sparse scalar oracle value.
    """

    rng = np.random.default_rng(seed)
    result = sp.number(real, order=order)

    for direction in bases:

        result.set_im(float(rng.uniform(-0.01, 0.01)), [direction])

    # end for

    for degree in range(2, order + 1):

        for direction in combinations_with_replacement(bases, degree):

            if rng.uniform() < 0.35:

                result.set_im(float(rng.uniform(-0.01, 0.01)), list(direction))

            # end if

        # end for

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _random_matrix(shape, bases, order, seed, real_range=None, positive_definite=False):
    """
    Build a reproducible sparse matrix with a safe real part.

    Parameters
    ----------
    shape : tuple of int
        Matrix dimensions.
    bases : tuple of int
        Bases used by every entry.
    order : int
        Truncation order.
    seed : int
        Random generator seed.
    real_range : tuple of float, optional
        Uniform range for the entry real parts.
    positive_definite : bool
        Build a symmetric positive-definite real part for inverse and determinant tests.

    Returns
    -------
    matso
        Sparse matrix oracle value.
    """

    rng = np.random.default_rng(seed)
    nrows, ncols = shape

    if real_range is not None:

        real = rng.uniform(real_range[0], real_range[1], size=shape)

    elif positive_definite and nrows == ncols:

        factor = rng.normal(scale=0.08, size=(nrows, ncols))
        real = factor.T @ factor + np.eye(nrows) * (1.5 + 0.2 * nrows)

    else:

        real = rng.uniform(0.7, 1.4, size=shape)

    # end if

    result = sp.zeros(shape, nbases=6, order=order)

    for i in range(nrows):

        for j in range(ncols):

            value = _random_scalar(
                bases,
                order,
                seed + 17 * i + 31 * j,
                real=float(real[i, j]),
            )
            result[i, j] = value

        # end for

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sparse_fe_scalar(points, order):
    """
    Pack pointwise sparse scalars into a sparse Gauss scalar.

    Parameters
    ----------
    points : list of sotinum
        Scalar at each integration point.
    order : int
        Minimum truncation order.

    Returns
    -------
    sotife
        Sparse Gauss scalar.
    """

    result = sp.zero(nbases=6, order=order, nip=len(points))

    for ip, value in enumerate(points):

        result[ip] = value

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sparse_fe_array(points, order):
    """
    Pack pointwise sparse matrices into a sparse Gauss array.

    Parameters
    ----------
    points : list of matso
        Matrix at each integration point.
    order : int
        Minimum truncation order.

    Returns
    -------
    matsofe
        Sparse Gauss matrix.
    """

    shape = points[0].shape
    result = sp.zeros(shape, nbases=6, order=order, nip=len(points))

    for ip, matrix in enumerate(points):

        for i in range(shape[0]):

            for j in range(shape[1]):

                result.set_ijk(matrix[i, j], i, j, ip)

            # end for

        # end for

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sparse_fe_slice(value, key):
    """
    Build a sparse Gauss slice by indexing each plain point independently.

    The sparse Gauss slice implementation exits on some singleton-axis inputs, so the oracle is
    deliberately assembled from its supported pointwise matrices.

    Parameters
    ----------
    value : matsofe
        Sparse Gauss matrix.
    key : int or slice or tuple
        Matrix key to select.

    Returns
    -------
    matsofe
        Pointwise sparse slice result.
    """

    if isinstance(key, tuple):

        row_key, col_key = key

    else:

        row_key, col_key = key, slice(None)

    # end if

    if isinstance(row_key, slice):

        rows = list(range(*row_key.indices(value.shape[0])))

    else:

        rows = [row_key % value.shape[0]]

    # end if

    if isinstance(col_key, slice):

        cols = list(range(*col_key.indices(value.shape[1])))

    else:

        cols = [col_key % value.shape[1]]

    # end if

    points = []

    for ip in range(value.nip):

        source = value.get_ip(ip)
        target = sp.zeros((len(rows), len(cols)), nbases=6, order=value.order)

        for i, source_i in enumerate(rows):

            for j, source_j in enumerate(cols):

                target[i, j] = source[source_i, source_j]

            # end for

        # end for

        points.append(target)

    # end for

    return _sparse_fe_array(points, value.order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_numeric(actual, expected, rtol=RTOL, atol=ATOL):
    """
    Compare numeric arrays with the Gauss test tolerances.

    Parameters
    ----------
    actual : array_like
        Computed values.
    expected : array_like
        Sparse oracle values.
    rtol : float
        Relative tolerance.
    atol : float
        Absolute tolerance.
    """

    np.testing.assert_allclose(
        np.asarray(actual, dtype=np.float64),
        np.asarray(expected, dtype=np.float64),
        rtol=rtol,
        atol=atol,
    )

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_scalar_matches(actual, expected, bases, order, rtol=RTOL, atol=ATOL):
    """
    Compare a dense scalar with a sparse scalar, coefficient by coefficient.

    Parameters
    ----------
    actual : otinum
        Dense result.
    expected : sotinum
        Sparse oracle.
    bases : tuple of int
        Union of operand bases.
    order : int
        Highest order to compare.
    rtol : float
        Relative tolerance.
    atol : float
        Absolute tolerance.
    """

    _assert_numeric(actual.real, expected.real, rtol, atol)

    for direction in _directions(bases, order):

        _assert_numeric(actual.get_im(direction), expected.get_im(direction), rtol, atol)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_array_matches(actual, expected, bases, order, rtol=RTOL, atol=ATOL):
    """
    Compare a dense matrix with a sparse matrix, coefficient by coefficient.

    Parameters
    ----------
    actual : omat
        Dense result.
    expected : matso
        Sparse oracle.
    bases : tuple of int
        Union of operand bases.
    order : int
        Highest order to compare.
    rtol : float
        Relative tolerance.
    atol : float
        Absolute tolerance.
    """

    assert actual.shape == expected.shape
    _assert_numeric(actual.real, expected.real, rtol, atol)

    for direction in _directions(bases, order):

        _assert_numeric(actual.get_im(direction), expected.get_im(direction), rtol, atol)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_scalar_fe_matches(
    actual, expected, bases, order, rtol=RTOL, atol=ATOL, check_order=True
):
    """
    Compare a dense Gauss scalar with a sparse Gauss scalar.

    Parameters
    ----------
    actual : otife
        Dense Gauss result.
    expected : sotife
        Sparse Gauss oracle.
    bases : tuple of int
        Union of operand bases.
    order : int
        Highest order to compare.
    rtol : float
        Relative tolerance.
    atol : float
        Absolute tolerance.
    check_order : bool
        Whether the sparse oracle is expected to retain the same declared order.
    """
    assert actual.nip == expected.nip

    if check_order:

        assert actual.order == expected.order

    # end if

    _assert_numeric(actual.real, expected.real_numpy, rtol, atol)

    for direction in _directions(bases, order):

        _assert_numeric(
            actual.get_im(direction),
            expected.get_im(direction).real_numpy,
            rtol,
            atol,
        )

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_array_fe_matches(
    actual, expected, bases, order, rtol=RTOL, atol=ATOL, check_order=True
):
    """
    Compare a dense Gauss matrix with a sparse Gauss matrix.

    Parameters
    ----------
    actual : omatfe
        Dense Gauss result.
    expected : matsofe
        Sparse Gauss oracle.
    bases : tuple of int
        Union of operand bases.
    order : int
        Highest order to compare.
    rtol : float
        Relative tolerance.
    atol : float
        Absolute tolerance.
    check_order : bool
        Whether the sparse oracle is expected to retain the same declared order.
    """
    assert actual.nip == expected.nip
    assert actual.shape == expected.shape

    if check_order:

        assert actual.order == expected.order

    # end if

    _assert_numeric(actual.real, expected.real_numpy.transpose(2, 0, 1), rtol, atol)

    for direction in _directions(bases, order):

        expected_block = expected.get_im(direction).real_numpy.transpose(2, 0, 1)
        _assert_numeric(actual.get_im(direction), expected_block, rtol, atol)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _points_from_fe(value):
    """
    Extract independent sparse point values from a sparse Gauss object.

    Parameters
    ----------
    value : sotife or matsofe
        Sparse Gauss value.

    Returns
    -------
    list
        Sparse scalar or matrix at every integration point.
    """

    if isinstance(value, sp.sotife):

        return [value[ip] for ip in range(value.nip)]

    # end if

    return [value.get_ip(ip) for ip in range(value.nip)]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _union(left, right):
    """
    Return the sorted union of two active base sets.

    Parameters
    ----------
    left : tuple of int
        First base set.
    right : tuple of int
        Second base set.

    Returns
    -------
    tuple of int
        Sorted union.
    """

    return tuple(sorted(set(left).union(right)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make_scalar_fe(bases, order, nip, seed, real_start=0.8):
    """
    Create point-varying sparse and dense Gauss scalar values.

    Parameters
    ----------
    bases : tuple of int
        Active bases of the pointwise values.
    order : int
        Truncation order.
    nip : int
        Number of integration points.
    seed : int
        Random generator seed.
    real_start : float
        Positive starting real coefficient.

    Returns
    -------
    tuple
        Sparse Gauss scalar and its dense conversion.
    """

    points = [
        _random_scalar(bases, order, seed + ip, real=real_start + 0.1 * ip)
        for ip in range(nip)
    ]
    sparse = _sparse_fe_scalar(points, order)
    return sparse, dn.otife.from_sparse(sparse)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make_array_fe(shape, bases, order, nip, seed, real_range=None, positive_definite=False):
    """
    Create point-varying sparse and dense Gauss matrices.

    Parameters
    ----------
    shape : tuple of int
        Matrix dimensions.
    bases : tuple of int
        Active bases of the pointwise values.
    order : int
        Truncation order.
    nip : int
        Number of integration points.
    seed : int
        Random generator seed.
    real_range : tuple of float, optional
        Uniform range for the entry real parts.
    positive_definite : bool
        Build a symmetric positive-definite real part for square matrices.

    Returns
    -------
    tuple
        Sparse Gauss matrix and its dense conversion.
    """

    points = [
        _random_matrix(
            shape,
            bases,
            order,
            seed + ip,
            real_range=real_range,
            positive_definite=positive_definite,
        )
        for ip in range(nip)
    ]
    sparse = _sparse_fe_array(points, order)
    return sparse, dn.omatfe.from_sparse(sparse)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _apply(op, left, right):
    """
    Apply one elementwise Python arithmetic operation.

    Parameters
    ----------
    op : str
        One of add, sub, mul or div.
    left : object
        Left operand.
    right : object
        Right operand.

    Returns
    -------
    object
        Arithmetic result.
    """

    if op == "add":

        return left + right

    elif op == "sub":

        return left - right

    elif op == "mul":

        return left * right

    else:

        return left / right

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "order, label, bases_left, bases_right, nip, shape",
    SCENARIOS,
    ids=["{}-o{}-n{}".format(label, order, nip) for order, label, _, _, nip, _ in SCENARIOS],
)
def test_gauss_creators_and_sparse_roundtrips(order, label, bases_left, bases_right, nip, shape):
    """
    Check Gauss creators, hooks, sparse conversions and varying point active sets.

    Parameters
    ----------
    order : int
        Truncation order.
    label : str
        Same, leading or interleaved active-set relation.
    bases_left : tuple of int
        First active set.
    bases_right : tuple of int
        Second active set.
    nip : int
        Integration-point count.
    shape : tuple of int
        Matrix shape used for array conversion checks.
    """

    del label
    bases = _union(bases_left, bases_right)
    scalar_values = [
        _random_scalar(bases_left if ip % 2 == 0 else bases_right, order, 300 + ip)
        for ip in range(nip)
    ]
    sparse_scalar = _sparse_fe_scalar(scalar_values, order)
    scalar = dn.otife.from_sparse(sparse_scalar)
    scalar_again = scalar.to_sparse()

    _assert_scalar_fe_matches(scalar, sparse_scalar, bases, order)
    _assert_scalar_fe_matches(dn.otife.from_sparse(scalar_again), sparse_scalar, bases, order)
    assert scalar.get_active_bases() == list(range(1, max(bases) + 1))
    assert scalar.nip == nip
    assert scalar.shape == (1, 1)
    assert scalar.nbases == max(bases) and scalar.nact == max(bases)
    assert scalar.actual_order <= order

    direct = dn.otife(scalar_values[0], nip=nip, bases=bases, order=order)
    expected_direct = _sparse_fe_scalar([scalar_values[0]] * nip, order)
    _assert_scalar_fe_matches(direct, expected_direct, bases, order)

    hook_scalar = dn._fe_scalar(scalar_values[0], list(bases), order, nip)
    _assert_scalar_fe_matches(hook_scalar, expected_direct, bases, order)
    zero = dn.zero(order=order, nip=nip)
    one = dn.one(order=order, nip=nip)
    number = dn.number(2.25, order=order, nip=nip)
    _assert_scalar_fe_matches(zero, _sparse_fe_scalar([sp.zero(order=order)] * nip, order),
                              bases, order)
    _assert_scalar_fe_matches(one, _sparse_fe_scalar([sp.one(order=order)] * nip, order),
                              bases, order)
    _assert_scalar_fe_matches(
        number, _sparse_fe_scalar([sp.number(2.25, order=order)] * nip, order), bases, order
    )
    points = [
        _random_matrix(shape, bases_left if ip % 2 == 0 else bases_right, order, 400 + ip)
        for ip in range(nip)
    ]
    sparse_array = _sparse_fe_array(points, order)
    array = dn.omatfe.from_sparse(sparse_array)
    array_again = array.to_sparse()
    points_as_soa = [dn.omat.from_sparse(point) for point in points]
    from_points = dn.omatfe.from_points(points_as_soa)
    hook_zeros = dn._fe_zeros(shape, list(bases), order, nip)
    public_zeros = dn.zeros(shape, bases=bases, order=order, nip=nip)

    _assert_array_fe_matches(array, sparse_array, bases, order)
    _assert_array_fe_matches(dn.omatfe.from_sparse(array_again), sparse_array, bases, order)
    _assert_array_fe_matches(from_points, sparse_array, bases, order)
    _assert_array_fe_matches(hook_zeros, sp.zeros(shape, nbases=6, order=order, nip=nip),
                              bases, order)
    _assert_array_fe_matches(public_zeros, sp.zeros(shape, nbases=6, order=order, nip=nip),
                              bases, order)
    assert array.nip == nip
    assert array.shape == shape
    assert array.nrows == shape[0]
    assert array.ncols == shape[1]
    assert array.size == shape[0] * shape[1]
    assert array.nbases == max(bases) and array.nact == max(bases)
    assert array.get_active_bases() == list(range(1, max(bases) + 1))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("direction", [[1], [1, 3]])
def test_public_gauss_e_creator_matches_sparse(direction):
    """
    Compare the dense Gauss ``e`` creator with the sparse Gauss creator.

    Parameters
    ----------
    direction : list of int
        Imaginary direction.
    """

    order = max(5, len(direction))
    nip = 4
    bases = tuple(sorted(set(direction)))
    actual = dn.e(direction, order=order, nip=nip)
    expected = sp.e(direction, order=order, nip=nip)
    _assert_scalar_fe_matches(actual, expected, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "order, label, bases_left, bases_right, nip, shape",
    SCENARIOS,
    ids=["{}-o{}-n{}".format(label, order, nip) for order, label, _, _, nip, _ in SCENARIOS],
)
def test_gauss_scalar_arithmetic_directions_and_inplace(
    order, label, bases_left, bases_right, nip, shape
):
    """
    Check Gauss scalar arithmetic, point access, derivative views and in-place operators.

    Parameters
    ----------
    order : int
        Truncation order.
    label : str
        Active-set relation.
    bases_left : tuple of int
        First active set.
    bases_right : tuple of int
        Second active set.
    nip : int
        Integration-point count.
    shape : tuple of int
        Unused associated shape scenario.
    """
    del label, shape
    bases = _union(bases_left, bases_right)
    sparse_left, left = _make_scalar_fe(bases_left, order, nip, 500)
    sparse_right, right = _make_scalar_fe(bases_right, order, nip, 600, real_start=1.8)
    left_points = _points_from_fe(sparse_left)
    right_points = _points_from_fe(sparse_right)
    scalar_sparse = _random_scalar(bases_right, order, 700, real=1.7)
    scalar = dn.otinum(scalar_sparse)
    real = 2.5

    for op in ("add", "sub", "mul", "div"):

        expected = _sparse_fe_scalar(
            [_apply(op, left_points[ip], right_points[ip]) for ip in range(nip)], order
        )
        actual = dn._fe_arith(op, left, right)
        _assert_scalar_fe_matches(actual, expected, bases, order)

        expected = _sparse_fe_scalar(
            [_apply(op, left_points[ip], scalar_sparse) for ip in range(nip)], order
        )
        _assert_scalar_fe_matches(dn._fe_arith(op, left, scalar), expected, bases, order)

        expected = _sparse_fe_scalar(
            [_apply(op, scalar_sparse, left_points[ip]) for ip in range(nip)], order
        )
        _assert_scalar_fe_matches(dn._fe_arith(op, scalar, left), expected, bases, order)

        expected = _sparse_fe_scalar(
            [_apply(op, left_points[ip], real) for ip in range(nip)], order
        )
        _assert_scalar_fe_matches(dn._fe_arith(op, left, real), expected, bases, order)

        expected = _sparse_fe_scalar(
            [_apply(op, real, left_points[ip]) for ip in range(nip)], order
        )
        _assert_scalar_fe_matches(dn._fe_arith(op, real, left), expected, bases, order)

        out = dn.otife(0.0, nip=nip, bases=bases, order=order)
        assert dn._fe_arith(op, left, right, out=out) is out
        _assert_scalar_fe_matches(out, _sparse_fe_scalar(
            [_apply(op, left_points[ip], right_points[ip]) for ip in range(nip)], order
        ), bases, order)

    # end for

    assert isinstance(left[0], dn.otinum)
    _assert_scalar_matches(left.get_ip(-1), left_points[-1], bases_left, order)
    _assert_numeric(left.real_numpy, sparse_left.real_numpy)

    replacement = _random_scalar(bases_right, order, 705, real=2.1)
    replaced = left.copy()
    replaced[0] = dn.otinum(replacement)
    replaced_points = [replacement] + left_points[1:]
    _assert_scalar_fe_matches(
        replaced, _sparse_fe_scalar(replaced_points, order), bases, order
    )

    replaced = left.copy()
    replaced.set(scalar)
    _assert_scalar_fe_matches(
        replaced, _sparse_fe_scalar([scalar_sparse] * nip, order), bases, order
    )

    for direction in _directions(bases, order):

        _assert_numeric(
            left.get_deriv(direction),
            sparse_left.get_deriv(direction).real_numpy,
        )

    # end for

    for direction in ([bases_left[0]], [bases_left[0], bases_left[-1]]):

        if len(direction) <= order:

            _assert_scalar_fe_matches(
                left.get_order_im(len(direction)),
                sparse_left.get_order_im(len(direction)),
                bases_left,
                order,
                check_order=False,
            )
            _assert_numeric(left.get_im(direction), sparse_left.get_im(direction).real_numpy)
            _assert_numeric(left.get_deriv(direction),
                            sparse_left.get_deriv(direction).real_numpy)
            _assert_scalar_fe_matches(
                left.truncate(direction),
                _sparse_fe_scalar([value.truncate(direction) for value in left_points], order),
                bases_left,
                order,
            )

        # end if

    # end for

    trunc_order = min(order, 2)
    _assert_scalar_fe_matches(
        left.truncate_order(trunc_order),
        sparse_left.truncate_order(trunc_order),
        bases_left,
        order,
    )

    assert left.get_active_bases() == list(range(1, max(bases_left) + 1))
    assert left[0].get_active_bases() == list(range(1, max(bases_left) + 1))
    powered = left ** 2.0
    expected_power = _sparse_fe_scalar([value ** 2.0 for value in left_points], order)
    _assert_scalar_fe_matches(powered, expected_power, bases_left, order)

    target = left.copy()
    target += right
    _assert_scalar_fe_matches(
        target,
        _sparse_fe_scalar([left_points[ip] + right_points[ip] for ip in range(nip)], order),
        bases,
        order,
    )
    target = left.copy()
    target -= right
    _assert_scalar_fe_matches(
        target,
        _sparse_fe_scalar([left_points[ip] - right_points[ip] for ip in range(nip)], order),
        bases,
        order,
    )
    target = left.copy()
    target *= right
    _assert_scalar_fe_matches(
        target,
        _sparse_fe_scalar([left_points[ip] * right_points[ip] for ip in range(nip)], order),
        bases,
        order,
    )
    target = left.copy()
    target /= right
    _assert_scalar_fe_matches(
        target,
        _sparse_fe_scalar([left_points[ip] / right_points[ip] for ip in range(nip)], order),
        bases,
        order,
    )

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "order, label, bases_left, bases_right, nip, shape",
    SCENARIOS,
    ids=["{}-o{}-n{}-{}x{}".format(label, order, nip, *shape)
         for order, label, _, _, nip, shape in SCENARIOS],
)
def test_gauss_array_arithmetic_indexing_and_set(
    order, label, bases_left, bases_right, nip, shape
):
    """
    Check Gauss array arithmetic, broadcasting, indexing, assignment and item methods.

    Parameters
    ----------
    order : int
        Truncation order.
    label : str
        Active-set relation.
    bases_left : tuple of int
        First active set.
    bases_right : tuple of int
        Second active set.
    nip : int
        Integration-point count.
    shape : tuple of int
        Matrix shape.
    """
    del label
    bases = _union(bases_left, bases_right)
    sparse_left, left = _make_array_fe(shape, bases_left, order, nip, 800)
    sparse_right, right = _make_array_fe(shape, bases_right, order, nip, 900)
    left_points = _points_from_fe(sparse_left)
    right_points = _points_from_fe(sparse_right)
    scalar_sparse = _random_scalar(bases_right, order, 1000, real=1.7)
    scalar = dn.otinum(scalar_sparse)
    gauss_scalar_sparse, gauss_scalar = _make_scalar_fe(bases_right, order, nip, 1100,
                                                        real_start=1.8)
    plain_matrix = _random_matrix(shape, bases_right, order, 1200)
    plain_dense = dn.omat.from_sparse(plain_matrix)

    for op in ("add", "sub", "mul", "div"):

        expected = _sparse_fe_array(
            [_apply(op, left_points[ip], right_points[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(dn._fe_arith(op, left, right), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, left_points[ip], scalar_sparse) for ip in range(nip)], order
        )
        _assert_array_fe_matches(dn._fe_arith(op, left, scalar), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, scalar_sparse, left_points[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(dn._fe_arith(op, scalar, left), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, left_points[ip], plain_matrix) for ip in range(nip)], order
        )
        _assert_array_fe_matches(dn._fe_arith(op, left, plain_dense), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, plain_matrix, left_points[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(dn._fe_arith(op, plain_matrix, left), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, left_points[ip], gauss_scalar_sparse[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(dn._fe_arith(op, left, gauss_scalar), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, gauss_scalar_sparse[ip], left_points[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(dn._fe_arith(op, gauss_scalar, left), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, left_points[ip], 1.25) for ip in range(nip)], order
        )
        _assert_array_fe_matches(dn._fe_arith(op, left, 1.25), expected, bases_left, order)

        expected = _sparse_fe_array(
            [_apply(op, 1.25, left_points[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(dn._fe_arith(op, 1.25, left), expected, bases_left, order)

        out = dn.omatfe(shape=(1, 1), nip=nip, bases=bases, order=0)
        assert dn._fe_arith(op, left, right, out=out) is out
        _assert_array_fe_matches(out, _sparse_fe_array(
            [_apply(op, left_points[ip], right_points[ip]) for ip in range(nip)], order
        ), bases, order)

    # end for

    assert left.shape == shape
    assert left.get_active_bases() == list(range(1, max(bases_left) + 1))
    _assert_array_fe_matches(dn.omatfe.from_sparse(sparse_left), sparse_left, bases_left, order)
    _assert_array_matches(left.get_ip(0), left_points[0], bases_left, order)
    _assert_scalar_fe_matches(left.get_item_ij(0, 0), sparse_left[0, 0], bases_left, order)
    _assert_scalar_fe_matches(left[0, 0], sparse_left[0, 0], bases_left, order)

    if shape[0] > 1:

        _assert_array_fe_matches(
            left[-1], _sparse_fe_slice(sparse_left, -1), bases_left, order
        )

    # end if

    if shape[1] > 1:

        _assert_array_fe_matches(
            left[:, -1], _sparse_fe_slice(sparse_left, (slice(None), -1)), bases_left, order
        )

    # end if

    copy = left.copy()
    new_point = _random_matrix(shape, bases_right, order, 1300)
    copy.set_ip(-1, dn.omat.from_sparse(new_point))
    changed_points = left_points[:-1] + [new_point]
    _assert_array_fe_matches(copy, _sparse_fe_array(changed_points, order), bases, order)

    copy = left.copy()
    inserted = _random_scalar(bases_right, order, 1400, real=2.0)
    copy.set_ijk(dn.otinum(inserted), 0, 0, 0)
    changed_points = [point.copy() for point in left_points]
    changed_points[0][0, 0] = inserted
    _assert_array_fe_matches(copy, _sparse_fe_array(changed_points, order), bases, order)

    copy = left.copy()
    copy[0, 0] = gauss_scalar
    changed_points = [point.copy() for point in left_points]

    for ip in range(nip):

        changed_points[ip][0, 0] = gauss_scalar_sparse[ip]

    # end for

    _assert_array_fe_matches(copy, _sparse_fe_array(changed_points, order), bases, order)

    copy = left.copy()
    copy.set(scalar)
    _assert_array_fe_matches(
        copy,
        _sparse_fe_array([sp.array([[scalar_sparse] * shape[1]] * shape[0]) for _ in range(nip)],
                         order),
        bases,
        order,
    )

    copy = left.copy()
    copy.set(plain_dense)
    _assert_array_fe_matches(copy, _sparse_fe_array([plain_matrix] * nip, order), bases, order)

    copy = left.copy()
    copy.set(gauss_scalar)
    _assert_array_fe_matches(
        copy,
        _sparse_fe_array(
            [sp.array([[gauss_scalar_sparse[ip]] * shape[1]] * shape[0]) for ip in range(nip)],
            order,
        ),
        bases,
        order,
    )

    for direction in _directions(bases_left, order):

        expected_deriv = sparse_left.get_deriv(direction).real_numpy.transpose(2, 0, 1)
        _assert_numeric(left.get_deriv(direction), expected_deriv)

    # end for

    _assert_array_fe_matches(
        left.get_order_im(min(2, order)),
        sparse_left.get_order_im(min(2, order)),
        bases_left,
        order,
        check_order=False,
    )
    _assert_array_fe_matches(
        left.truncate([bases_left[0]]),
        sparse_left.truncate([bases_left[0]]),
        bases_left,
        order,
    )
    _assert_array_fe_matches(
        left.truncate_order(min(order, 2)),
        sparse_left.truncate_order(min(order, 2)),
        bases_left,
        order,
    )
    np.testing.assert_allclose(
        left.real_numpy,
        sparse_left.real_numpy.transpose(2, 0, 1),
        rtol=RTOL,
        atol=ATOL,
    )

    target = left.copy()
    target += right
    _assert_array_fe_matches(target, _sparse_fe_array(
        [left_points[ip] + right_points[ip] for ip in range(nip)], order
    ), bases, order)
    target = left.copy()
    target -= right
    _assert_array_fe_matches(target, _sparse_fe_array(
        [left_points[ip] - right_points[ip] for ip in range(nip)], order
    ), bases, order)
    target = left.copy()
    target *= right
    _assert_array_fe_matches(target, _sparse_fe_array(
        [left_points[ip] * right_points[ip] for ip in range(nip)], order
    ), bases, order)
    target = left.copy()
    target /= right
    _assert_array_fe_matches(target, _sparse_fe_array(
        [left_points[ip] / right_points[ip] for ip in range(nip)], order
    ), bases, order)

    _assert_array_fe_matches(
        -left, _sparse_fe_array([-point for point in left_points], order), bases_left, order
    )
    _assert_array_fe_matches(
        left ** 2.0,
        _sparse_fe_array([point ** 2.0 for point in left_points], order),
        bases_left,
        order,
    )

    for name in ("sum", "sub", "mul", "div"):

        function = getattr(dn, name)
        oracle = getattr(sp, name)
        actual = function(left, right)
        expected = _sparse_fe_array(
            [oracle(left_points[ip], right_points[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(actual, expected, bases, order)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "order, label, bases_left, bases_right, nip, shapes",
    DOT_SCENARIOS,
    ids=["{}-o{}-n{}".format(label, order, nip)
         for order, label, _, _, nip, _ in DOT_SCENARIOS],
)
def test_gauss_matrix_products_and_dot_products(order, label, bases_left, bases_right, nip, shapes):
    """
    Compare Gauss matrix and vector products with pointwise sparse products.

    Parameters
    ----------
    order : int
        Truncation order.
    label : str
        Active-set relation.
    bases_left : tuple of int
        Left active set.
    bases_right : tuple of int
        Right active set.
    nip : int
        Integration-point count.
    shapes : tuple
        Left and right point matrix shapes.
    """

    del label
    bases = _union(bases_left, bases_right)
    left_shape, right_shape = shapes
    sparse_left, left = _make_array_fe(left_shape, bases_left, order, nip, 1500)
    sparse_right, right = _make_array_fe(right_shape, bases_right, order, nip, 1600)
    left_points = _points_from_fe(sparse_left)
    right_points = _points_from_fe(sparse_right)
    expected_dot = _sparse_fe_array(
        [sp.dot(left_points[ip], right_points[ip]) for ip in range(nip)], order
    )
    actual_dot = dn._fe_dot(left, right)
    _assert_array_fe_matches(actual_dot, expected_dot, bases, order)
    _assert_array_fe_matches(left.dot(right), expected_dot, bases, order)
    _assert_array_fe_matches(left @ right, expected_dot, bases, order)
    _assert_array_fe_matches(dn.dot(left, right), expected_dot, bases, order)

    plain_left = _random_matrix(left_shape, bases_left, order, 1700)
    plain_right = _random_matrix(right_shape, bases_right, order, 1800)
    dense_left = dn.omat.from_sparse(plain_left)
    dense_right = dn.omat.from_sparse(plain_right)

    expected_right = _sparse_fe_array(
        [sp.dot(left_points[ip], plain_right) for ip in range(nip)], order
    )
    expected_left = _sparse_fe_array(
        [sp.dot(plain_left, right_points[ip]) for ip in range(nip)], order
    )
    _assert_array_fe_matches(dn._fe_dot(left, dense_right), expected_right, bases, order)
    _assert_array_fe_matches(dn._fe_dot(dense_left, right), expected_left, bases, order)
    _assert_array_fe_matches(dn._fe_dot(plain_left, right), expected_left, bases, order)
    _assert_array_fe_matches(right.__rmatmul__(plain_left), expected_left, bases, order)

    out = dn.omatfe((1, 1), nip=nip, bases=bases, order=0)
    assert dn._fe_dot(left, right, out=out) is out
    _assert_array_fe_matches(out, expected_dot, bases, order)

    if left_shape == right_shape:

        dot_product_sparse = sparse_right
        dot_product_semi = right
        dot_product_points = right_points
        dot_product_plain = plain_right

    else:

        dot_product_sparse, dot_product_semi = _make_array_fe(
            left_shape, bases_right, order, nip, 1850
        )
        dot_product_points = _points_from_fe(dot_product_sparse)
        dot_product_plain = _random_matrix(left_shape, bases_right, order, 1860)

    # end if

    expected_dot_product = _sparse_fe_scalar(
        [sp.dot_product(left_points[ip], dot_product_points[ip]) for ip in range(nip)], order
    )
    actual_dot_product = dn._fe_dot_product(left, dot_product_semi)
    _assert_scalar_fe_matches(actual_dot_product, expected_dot_product, bases, order)

    expected_dot_plain = _sparse_fe_scalar(
        [sp.dot_product(left_points[ip], dot_product_plain) for ip in range(nip)], order
    )
    _assert_scalar_fe_matches(
        dn._fe_dot_product(left, dn.omat.from_sparse(dot_product_plain)), expected_dot_plain,
        bases, order
    )
    expected_plain_dot = _sparse_fe_scalar(
        [sp.dot_product(dot_product_plain, dot_product_points[ip]) for ip in range(nip)], order
    )
    _assert_scalar_fe_matches(
        dn._fe_dot_product(dn.omat.from_sparse(dot_product_plain), dot_product_semi),
        expected_plain_dot,
        bases,
        order,
    )

    out_scalar = dn.otife(0.0, nip=nip, bases=bases, order=0)
    assert dn._fe_dot_product(left, dot_product_semi, out=out_scalar) is out_scalar
    _assert_scalar_fe_matches(out_scalar, expected_dot_product, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_dot_product_equal_size_different_shapes_matches_sparse():
    """
    Compare flattened dot products for equal-size matrices with different shapes.
    """

    order = 3
    nip = 4
    bases = (1, 2, 3)
    sparse_left, left = _make_array_fe((2, 3), bases, order, nip, 2250)
    sparse_right, right = _make_array_fe((3, 2), bases, order, nip, 2260)
    points_left = _points_from_fe(sparse_left)
    points_right = _points_from_fe(sparse_right)
    expected = _sparse_fe_scalar(
        [sp.dot_product(a, b) for a, b in zip(points_left, points_right)], order
    )

    _assert_scalar_fe_matches(dn._fe_dot_product(left, right), expected, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "order, label, bases_left, bases_right, nip, shape",
    LINALG_SCENARIOS,
    ids=["{}-o{}-n{}-{}x{}".format(label, order, nip, *shape)
         for order, label, _, _, nip, shape in LINALG_SCENARIOS],
)
def test_gauss_inverse_determinant_and_transpose(order, label, bases_left, bases_right, nip,
                                                 shape):
    """
    Compare per-point Gauss inverse, determinant and transpose with sparse matrices.

    The 4x4 LU cases use a slightly relaxed tolerance of 1e-12.

    Parameters
    ----------
    order : int
        Truncation order.
    label : str
        Active-set relation.
    bases_left : tuple of int
        Active bases in the matrix.
    bases_right : tuple of int
        Additional bases reserved by the scenario.
    nip : int
        Integration-point count.
    shape : tuple of int
        Square point matrix shape.
    """
    del label, bases_right
    bases = bases_left
    n = shape[0]
    tolerance = 1e-12 if n == 4 else RTOL
    sparse_matrix, matrix = _make_array_fe(
        shape, bases, order, nip, 1900, positive_definite=True
    )
    points = _points_from_fe(sparse_matrix)
    expected_inverse = _sparse_fe_array([sp.inv(point) for point in points], order)
    expected_determinant = _sparse_fe_scalar([sp.det(point) for point in points], order)
    expected_transpose = _sparse_fe_array([point.T for point in points], order)

    inverse = dn._fe_inv(matrix)
    determinant = dn._fe_det(matrix)
    transposed = dn._fe_transpose(matrix)

    _assert_array_fe_matches(inverse, expected_inverse, bases, order, tolerance, tolerance)
    _assert_scalar_fe_matches(
        determinant, expected_determinant, bases, order, tolerance, tolerance
    )
    _assert_array_fe_matches(transposed, expected_transpose, bases, order)
    _assert_array_fe_matches(matrix.inv(), expected_inverse, bases, order, tolerance, tolerance)
    _assert_scalar_fe_matches(matrix.det(), expected_determinant, bases, order, tolerance,
                               tolerance)
    _assert_array_fe_matches(matrix.T, expected_transpose, bases, order)

    out_inverse = dn.omatfe((1, 1), nip=nip, bases=bases, order=0)
    out_determinant = dn.otife(0.0, nip=nip, bases=bases, order=0)
    out_transpose = dn.omatfe((1, 1), nip=nip, bases=bases, order=0)
    assert dn._fe_inv(matrix, out=out_inverse) is out_inverse
    assert dn._fe_det(matrix, out=out_determinant) is out_determinant
    assert dn._fe_transpose(matrix, out=out_transpose) is out_transpose
    _assert_array_fe_matches(out_inverse, expected_inverse, bases, order, tolerance, tolerance)
    _assert_scalar_fe_matches(out_determinant, expected_determinant, bases, order,
                              tolerance, tolerance)
    _assert_array_fe_matches(out_transpose, expected_transpose, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_unary_functions_match_sparse():
    """
    Compare every supported dense Gauss elementary function with sparse.
    """

    for name in UNARY_FUNCTIONS:

        function = getattr(dn, name)
        sparse_function = getattr(sp, name)

        for order in (1, 3, 5):

            for case_index, (_, bases_left, bases_right) in enumerate(ACTIVE_PAIRS):

                bases = bases_left if case_index != 2 else bases_right
                nip = NIPS[case_index]
                low, high = UNARY_DOMAINS.get(name, (0.7, 1.2))
                rng = np.random.default_rng(2300 + order * 11 + case_index)
                scalar_points = [
                    _random_scalar(
                        bases,
                        order,
                        2400 + order * 17 + case_index * 5 + ip,
                        real=float(rng.uniform(low, high)),
                    )
                    for ip in range(nip)
                ]
                sparse_scalar = _sparse_fe_scalar(scalar_points, order)
                dense_scalar = dn.otife.from_sparse(sparse_scalar)
                _assert_scalar_fe_matches(
                    function(dense_scalar), sparse_function(sparse_scalar), bases, order
                )

                matrix_points = [
                    _random_matrix(
                        (2, 2),
                        bases,
                        order,
                        2500 + order * 17 + case_index * 5 + ip,
                        real_range=(low, high),
                    )
                    for ip in range(nip)
                ]
                sparse_matrix = _sparse_fe_array(matrix_points, order)
                dense_matrix = dn.omatfe.from_sparse(sparse_matrix)
                _assert_array_fe_matches(
                    function(dense_matrix), sparse_function(sparse_matrix), bases, order
                )

            # end for

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_absolute_value_matches_sparse():
    """
    Check unary and module absolute value on scalar and matrix Gauss types.
    """

    for order in (1, 3, 5):

        for case_index, (_, bases_left, bases_right) in enumerate(ACTIVE_PAIRS):

            bases = bases_left if case_index != 2 else bases_right
            nip = NIPS[case_index]
            scalar_points = [
                _random_scalar(
                    bases,
                    order,
                    3000 + order * 13 + case_index * 5 + ip,
                    real=(-0.8 if ip % 2 else 0.8),
                )
                for ip in range(nip)
            ]
            sparse_scalar = _sparse_fe_scalar(scalar_points, order)
            dense_scalar = dn.otife.from_sparse(sparse_scalar)
            _assert_scalar_fe_matches(abs(dense_scalar), sp.abs(sparse_scalar), bases, order)
            _assert_scalar_fe_matches(dn.abs(dense_scalar), sp.abs(sparse_scalar), bases, order)

            matrix_points = []

            for ip in range(nip):

                point = sp.zeros((2, 2), nbases=6, order=order)
                real_values = ((-1.0, 0.7), (0.2, -0.4))

                for i in range(2):

                    for j in range(2):

                        point[i, j] = _random_scalar(
                            bases,
                            order,
                            3100 + order * 13 + case_index * 5 + ip * 4 + i * 2 + j,
                            real=real_values[i][j],
                        )

                    # end for

                # end for

                matrix_points.append(point)

            # end for

            sparse_matrix = _sparse_fe_array(matrix_points, order)
            dense_matrix = dn.omatfe.from_sparse(sparse_matrix)
            expected = sp.abs(sparse_matrix)
            _assert_array_fe_matches(abs(dense_matrix), expected, bases, order)
            _assert_array_fe_matches(dn.abs(dense_matrix), expected, bases, order)

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_integration_and_output_holders():
    """
    Compare scalar and matrix Gauss integration, including preallocated result holders.
    """

    for order, label, bases_left, bases_right, nip, shape in SCENARIOS:

        bases = _union(bases_left, bases_right)
        sparse_value, value = _make_scalar_fe(bases_left, order, nip, 2600 + order)
        sparse_weights, weights = _make_scalar_fe(
            bases_right, order, nip, 2700 + order, real_start=0.6
        )
        sparse_result = sp.gauss_integrate(sparse_value, sparse_weights)
        actual = dn.gauss_integrate(value, weights)
        _assert_scalar_matches(actual, sparse_result, bases, order)
        _assert_scalar_matches(value.gauss_integrate(weights), sparse_result, bases, order)

        scalar_out = dn.otinum(0.0, order=0)
        assert dn.gauss_integrate(value, weights, out=scalar_out) is scalar_out
        _assert_scalar_matches(scalar_out, sparse_result, bases, order)

        sparse_matrix, matrix = _make_array_fe(shape, bases_left, order, nip, 2800 + order)
        sparse_matrix_result = sp.gauss_integrate(sparse_matrix, sparse_weights)
        actual_matrix = dn.gauss_integrate(matrix, weights)
        _assert_array_matches(actual_matrix, sparse_matrix_result, bases, order)
        _assert_array_matches(matrix.gauss_integrate(weights), sparse_matrix_result, bases, order)

        matrix_out = dn.omat.zeros((1, 1), order=0)
        assert dn.gauss_integrate(matrix, weights, out=matrix_out) is matrix_out
        _assert_array_matches(matrix_out, sparse_matrix_result, bases, order)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_argument_errors():
    """
    Check explicit nip, shape and index errors on the Gauss-point hooks and classes.
    """

    order = 2
    scalar_four = dn.otife(1.0, nip=4, bases=(1, 2), order=order)
    scalar_one = dn.otife(1.0, nip=1, bases=(1, 2), order=order)
    array_four = dn.omatfe((2, 2), nip=4, bases=(1, 2), order=order)
    array_one = dn.omatfe((2, 2), nip=1, bases=(1, 2), order=order)
    array_rect = dn.omatfe((2, 3), nip=4, bases=(1, 2), order=order)

    with pytest.raises(ValueError, match="integration points"):

        dn._fe_arith("add", scalar_four, scalar_one)

    # end with

    with pytest.raises(ValueError, match="integration points"):

        dn._fe_dot(array_four, array_one)

    # end with

    with pytest.raises(ValueError, match="integration points"):

        dn._fe_dot_product(array_four, array_one)

    # end with

    with pytest.raises(ValueError, match="incompatible shapes"):

        dn._fe_arith("add", array_four, array_rect)

    # end with

    with pytest.raises(IndexError):

        scalar_four.get_ip(4)

    # end with

    with pytest.raises(IndexError):

        scalar_four[-5]

    # end with

    with pytest.raises(IndexError):

        array_four.get_ip(4)

    # end with

    with pytest.raises(IndexError):

        array_four[2, 0]

    # end with

    with pytest.raises(IndexError):

        array_four[(0, 0, 0)]

    # end with

    with pytest.raises(ValueError, match="shape mismatch"):

        array_four.set_ip(0, dn.omat.zeros((1, 1)))

    # end with

    with pytest.raises(ValueError, match="different numbers of integration points"):

        array_four[0, :] = dn.omatfe((1, 2), nip=1, bases=(1, 2), order=order)

    # end with

    with pytest.raises(ValueError, match="shape mismatch"):

        array_four[0, :] = dn.omatfe((2, 2), nip=4, bases=(1, 2), order=order)

    # end with

    with pytest.raises(ValueError, match="nip must be positive"):

        dn._fe_scalar(0.0, (), order, 0)

    # end with

    with pytest.raises(ValueError, match="shape must be"):

        dn._fe_zeros((2, 3, 4), (), order, 4)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", ("dot_product", "det", "inv", "transpose"))
def test_public_gauss_module_linalg_dispatch_when_available(name):
    """
    Exercise each public module linear-algebra spelling on Gauss inputs (the dispatch is part of WP10).

    Parameters
    ----------
    name : str
        Public module function to check.
    """

    order = 2
    nip = 4
    bases = (1, 2, 3)
    sparse_matrix, matrix = _make_array_fe(
        (2, 2), bases, order, nip, 2900, positive_definite=True
    )
    sparse_other, other = _make_array_fe(
        (2, 2), bases, order, nip, 2910, positive_definite=True
    )
    points = _points_from_fe(sparse_matrix)
    other_points = _points_from_fe(sparse_other)

    if name == "dot_product":

        call = lambda: dn.dot_product(matrix, other)
        expected = _sparse_fe_scalar(
            [sp.dot_product(a, b) for a, b in zip(points, other_points)], order
        )

    elif name == "det":

        call = lambda: dn.det(matrix)
        expected = _sparse_fe_scalar([sp.det(point) for point in points], order)

    elif name == "inv":

        call = lambda: dn.inv(matrix)
        expected = _sparse_fe_array([sp.inv(point) for point in points], order)

    else:

        call = lambda: dn.transpose(matrix)
        expected = _sparse_fe_array([point.T for point in points], order)

    # end if

    actual = call()

    if name in ("dot_product", "det"):

        _assert_scalar_fe_matches(actual, expected, bases, order)

    else:

        _assert_array_fe_matches(actual, expected, bases, order)

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", ("sin", "abs"))
def test_gauss_unary_out_holder(name):
    """
    Check public unary-function out= behavior for a dense Gauss scalar.

    Parameters
    ----------
    name : str
        Unary function name.
    """

    order = 2
    nip = 4
    bases = (1, 2)
    sparse_value, value = _make_scalar_fe(bases, order, nip, 2200)
    expected = getattr(sp, name)(sparse_value)
    out = dn.otife(0.0, nip=nip, bases=bases, order=order)

    assert getattr(dn, name)(value, out=out) is None
    _assert_scalar_fe_matches(out, expected, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_fem_probe_and_elm_help():
    """
    Check the calls pyoti.fem.set_global_algebra(pyoti.dense) probes, and the element helper fields.
    """

    import pyoti.fem as fem

    helper = dn.elm_help()
    matrix = dn.zeros((2, 2), nip=2)
    scalar = dn.zero(nip=2)

    assert isinstance(matrix, dn.omatfe) and matrix.shape == (2, 2) and matrix.nip == 2
    assert isinstance(scalar, dn.otife) and scalar.nip == 2
    assert not helper.is_allocated()

    helper.allocate(2, 4, 4, order=1)
    helper.allocate_spatial(2, compute_Jinv=True)

    assert helper.is_allocated()
    assert isinstance(helper.J, dn.omatfe) and helper.J.shape == (2, 2)
    assert isinstance(helper.detJ, dn.otife) and isinstance(helper.x, dn.omat)

    fem.set_global_algebra(dn)
    fem.set_global_algebra(sp)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_views_stay_inputs():
    """
    Check that functions evaluated through a view of the embedded array leave the operand intact.
    """

    order = 3
    nip = 4
    bases = (1, 2)
    sparse_value, value = _make_scalar_fe(bases, order, nip, 3100)
    before = value.copy()

    for name in ("sin", "exp", "abs"):

        result = getattr(dn, name)(value)
        _assert_scalar_fe_matches(result, getattr(sp, name)(sparse_value), bases, order)
        _assert_scalar_fe_matches(value, sparse_value, bases, order)

    # end for

    extracted = value.extract_im([1])
    _assert_scalar_fe_matches(extracted, sparse_value.extract_im([1]), bases, order - 1,
                              check_order=False)
    np.testing.assert_array_equal(value.real, before.real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_assignment_grows_nact_and_order():
    """
    Check that assigning a value over more bases or a higher order grows the whole Gauss value.
    """

    matrix = dn.zeros((2, 2), order=1, nip=3)
    matrix[0, 0] = dn.e(1, order=1)

    assert matrix.nact == 1 and matrix.order == 1

    matrix.set_ijk(dn.e([2, 5], order=3), 1, 1, 2)

    assert matrix.nact == 5 and matrix.order == 3
    np.testing.assert_array_equal(matrix.get_im([1])[:, 0, 0], [1.0, 1.0, 1.0])
    np.testing.assert_array_equal(matrix.get_im([2, 5])[:, 1, 1], [0.0, 0.0, 1.0])
    np.testing.assert_array_equal(matrix.get_im([5]), np.zeros((3, 2, 2)))

    scalar = dn.zero(nip=2)
    scalar[1] = dn.e(4, order=2) + 3.0

    assert scalar.nact == 4 and scalar.order == 2
    np.testing.assert_array_equal(scalar.real, [0.0, 3.0])
    np.testing.assert_array_equal(scalar.get_im([4]), [0.0, 1.0])
    assert scalar.get_active_bases() == [1, 2, 3, 4]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_out_holder_with_block_views():
    """
    Check that an omat out= holder with a live block view is refused, and accepted once it is gone.
    """

    helper = dn.elm_help()
    values = dn.zeros((6, 1), order=2)

    for i in range(6):

        values[i, 0] = i + dn.e(3, order=2)

    # end for

    out = dn.zeros((3, 1), order=1)
    out[0, 0] = 7.0 * dn.e(1, order=1)
    block = out.get_block(1)

    with pytest.raises(BufferError):

        helper.get(values, np.array([0, 2, 4]), out=out)

    # end with

    # The holder and its view are unchanged.
    assert block[0, 0] == 7.0 and out.order == 1 and out.nact == 1

    del block
    helper.get(values, np.array([0, 2, 4]), out=out)

    assert out.shape == (3, 1) and out.nact == 3 and out.order == 2
    np.testing.assert_array_equal(out.real[:, 0], [0.0, 2.0, 4.0])
    np.testing.assert_array_equal(out.get_im([3])[:, 0], [1.0, 1.0, 1.0])

    # Any previous shape is still accepted.
    other = dn.zeros((1, 1), order=0)
    helper.get_local(values, np.array([1, 3]), out=other)

    assert other.shape == (2, 1)
    np.testing.assert_array_equal(other.real[:, 0], [1.0, 3.0])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_out_holder_of_the_other_kind():
    """
    Check that out= refuses a Gauss holder of the other kind and keeps "any shape" for omatfe.
    """

    _, matrix = _make_array_fe((2, 2), (1, 2), 2, 3, 3200, positive_definite=True)
    _, scalar = _make_scalar_fe((1, 2), 2, 3, 3210)

    with pytest.raises(TypeError):

        dn.inv(matrix, out=dn.zero(nip=3))

    # end with

    with pytest.raises(TypeError):

        dn.sin(matrix, out=dn.zero(nip=3))

    # end with

    with pytest.raises(TypeError):

        dn.det(matrix, out=dn.zeros((3, 3), nip=3))

    # end with

    holder = dn.zeros((3, 3), nip=3)
    dn.inv(matrix, out=holder)
    assert holder.shape == (2, 2)
    np.testing.assert_allclose(holder.real, dn.inv(matrix).real, rtol=RTOL, atol=ATOL)

    scalar_holder = dn.zero(nip=3)
    assert dn.sin(scalar, out=scalar_holder) is None
    np.testing.assert_allclose(scalar_holder.real, dn.sin(scalar).real, rtol=RTOL, atol=ATOL)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("op", ["+=", "-=", "*=", "/="])
def test_dense_inplace_operators_rebind(op):
    """
    Check that in-place operators rebind the name (a op= b is a = a op b) and leave aliases alone.

    Parameters
    ----------
    op : str
        In-place operator.
    """

    matrix = dn.zeros((2, 2), nip=2) + 3.0
    alias = matrix
    scalar = dn.zero(nip=2) + 2.0
    scalar_alias = scalar
    namespace = {"x": matrix, "s": scalar}

    exec("x {} 2.0\ns {} 4.0".format(op, op), namespace)

    assert namespace["x"] is not alias and namespace["s"] is not scalar_alias
    np.testing.assert_array_equal(alias.real, np.full((2, 2, 2), 3.0))
    np.testing.assert_array_equal(scalar_alias.real, [2.0, 2.0])
    expected = {"+=": 5.0, "-=": 1.0, "*=": 6.0, "/=": 1.5}[op]
    np.testing.assert_array_equal(namespace["x"].real, np.full((2, 2, 2), expected))

    helper = dn.elm_help()
    helper.allocate(2, 4, 2, order=1)
    helper.allocate_spatial(2)
    differential = helper.dV
    differential += 1.0
    np.testing.assert_array_equal(helper.dV.real, [0.0, 0.0])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_set_keeps_nact_and_order():
    """
    Check that set() never lowers nact or the truncation order, like pyoti.sparse.
    """

    scalar = dn.zero(nip=2, order=3)
    scalar[0] = dn.e(3, order=3)
    scalar.set(dn.zero(nip=2))

    assert scalar.order == 3 and scalar.nact == 3
    np.testing.assert_array_equal(scalar.real, [0.0, 0.0])
    np.testing.assert_array_equal(scalar.get_im([3]), [0.0, 0.0])

    matrix = dn.zeros((2, 2), nip=2, order=2)
    matrix[0, 0] = dn.e(4, order=2)
    matrix.set(dn.omat.zeros((2, 2)) + 1.0)

    assert matrix.order == 2 and matrix.nact == 4
    np.testing.assert_array_equal(matrix.real, np.ones((2, 2, 2)))

    matrix.set(dn.zeros((2, 2), nip=2, order=5) + dn.e(1, order=5))

    assert matrix.order == 5 and matrix.nact == 4
    np.testing.assert_array_equal(matrix.get_im([1]), np.ones((2, 2, 2)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_negative_step_and_empty_slices():
    """
    Check slices whose negative-step start clamps below 0, and empty axes, against NumPy.
    """

    _, matrix = _make_array_fe((4, 3), (1, 2), 2, 3, 3300)
    reference = matrix.real

    for key in ((slice(-10, None, -1), 0), (slice(None, None, -1), slice(-10, None, -1)),
                (slice(2, None, -2), slice(None)), (slice(5, 5), 1)):

        rows, cols = key
        if isinstance(cols, slice):

            expected = reference[:, rows, cols]

        else:

            expected = reference[:, rows, cols:cols + 1]

        # end if

        block = matrix[key]
        assert block.real.shape == expected.shape
        np.testing.assert_array_equal(block.real, expected)

    # end for

    copy = matrix.copy()
    copy[-10::-1, 0] = 5.0
    np.testing.assert_array_equal(copy.real, reference)

    empty = dn.zeros((0, 3), nip=2)
    assert empty[::-1, ::-1].shape == (0, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_gauss_integrate_constant_integrand():
    """
    Check that a real or OTI constant integrand gives value * sum(w), as pyoti.sparse does.
    """

    order = 2
    nip = 3
    sparse_weights, weights = _make_scalar_fe((1, 2), order, nip, 3400, real_start=0.6)
    constant = 1.5 + 0.25 * dn.e(3, order=order)

    _assert_scalar_matches(dn.gauss_integrate(2.0, weights), sp.gauss_integrate(2.0, sparse_weights),
                           (1, 2, 3), order)
    _assert_scalar_matches(dn.gauss_integrate(constant, weights),
                           sp.gauss_integrate(constant.to_sparse(), sparse_weights), (1, 2, 3), order)
    _assert_scalar_matches(dn.gauss_integrate(constant.to_sparse(), weights),
                           sp.gauss_integrate(constant.to_sparse(), sparse_weights), (1, 2, 3), order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_gauss_index_types_and_messages():
    """
    Check integer-only indices, huge point indices, dot_product operand types and shape messages.
    """

    _, matrix = _make_array_fe((2, 2), (1, 2), 1, 3, 3500)
    _, scalar = _make_scalar_fe((1, 2), 1, 3, 3510)

    with pytest.raises(TypeError):

        matrix[1.5]

    # end with

    with pytest.raises(TypeError):

        matrix.set_ijk(1.0, 0.5, 0, 0)

    # end with

    with pytest.raises(IndexError):

        matrix.get_ip(2**70)

    # end with

    with pytest.raises(IndexError):

        scalar[2**70]

    # end with

    with pytest.raises(IndexError):

        matrix.set_ijk(1.0, 0, 2, 0)

    # end with

    with pytest.raises(TypeError):

        dn._fe_dot_product(1.0, matrix)

    # end with

    with pytest.raises(ValueError):

        dn._fe_dot_product(scalar, matrix)

    # end with

    with pytest.raises(ValueError, match=r"\(3, 3\)"):

        matrix + (dn.omat.zeros((3, 3)) + 1.0)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_scalar_inverse_keeps_kind():
    """
    Check that inv of a Gauss scalar is a Gauss scalar equal to its reciprocal.
    """

    sparse_scalar, scalar = _make_scalar_fe((1, 2), 3, 4, 3600, real_start=1.2)
    inverse = dn.inv(scalar)

    assert isinstance(inverse, dn.otife)
    _assert_scalar_fe_matches(inverse, 1.0 / sparse_scalar, (1, 2), 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_gauss_limits_and_errors():
    """
    Check order 150 / 151 through the Gauss creators, LinAlgError for a singular n > 3 point, and a
    MemoryError path.
    """

    assert dn.zeros((2, 2), nip=2, order=150).order == 150
    assert dn.otife(1.0, nip=2, order=150).order == 150

    for create in (lambda: dn.zeros((2, 2), nip=2, order=151), lambda: dn.zero(nip=2, order=151),
                   lambda: dn.otife(1.0, nip=2, order=151), lambda: dn.omatfe((2, 2), nip=2, order=151)):

        with pytest.raises(ValueError, match="order must be between 0 and 150"):

            create()

        # end with

    # end for

    _, matrix = _make_array_fe((4, 4), (1, 2), 2, 3, 3700, positive_definite=True)

    for j in range(4):

        matrix.set_ijk(0.0, 1, j, 2)

    # end for

    with pytest.raises(np.linalg.LinAlgError):

        dn.det(matrix)

    # end with

    with pytest.raises(np.linalg.LinAlgError):

        dn.inv(matrix)

    # end with

    with pytest.raises(MemoryError):

        dn.zeros((2**33, 2**33), nip=2, order=1)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_gauss_beyond_the_global_table_matches_semisparse():
    """
    Check nact 11 at order 5 (beyond Nbasis(5) = 10) against semi-sparse, built with the same values.
    """

    import pyoti.semisparse as ss

    order = 5
    nip = 3
    rng = np.random.default_rng(3800)
    dense = [dn.zeros((2, 2), nip=nip, order=order) for _ in range(2)]
    semi = [ss.zeros((2, 2), nip=nip, order=order) for _ in range(2)]

    for m in range(2):

        for i in range(2):

            for j in range(2):

                for ip in range(nip):

                    real = 2.0 + rng.random() if i == j else rng.random() - 0.5
                    value = real + 0.1 * dn.e(11, order=order) + 0.05 * dn.e([2, 7], order=order)
                    semi_value = (real + 0.1 * ss.e(11, order=order)
                                  + 0.05 * ss.e([2, 7], order=order))
                    dense[m].set_ijk(value, i, j, ip)
                    semi[m].set_ijk(semi_value, i, j, ip)

                # end for

            # end for

        # end for

    # end for

    pairs = [
        (dense[0] @ dense[1], semi[0] @ semi[1]),
        (dense[0] * dense[1], semi[0] * semi[1]),
        (dn.sin(dense[0]), ss.sin(semi[0])),
        (dn.inv(dense[1]), ss.inv(semi[1])),
    ]

    for actual, expected in pairs:

        assert actual.nact == 11

        for direction in ([11], [11, 11], [2, 7, 11], [11, 11, 11, 11, 11], [7]):

            np.testing.assert_allclose(actual.get_im(direction), expected.get_im(direction),
                                       rtol=1e-13, atol=1e-13)

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_elm_help_jacobian_matches_semisparse():
    """
    Check elm_help's Jacobian, determinant, differential, spatial derivatives and integration
    against the semi-sparse helper filled with the same values (a bilinear quad, OTI coordinates).
    """

    import pyoti.semisparse as ss

    order = 2
    nip = 4
    points = [(-0.577, -0.577), (0.577, -0.577), (0.577, 0.577), (-0.577, 0.577)]
    corners = [(-1, -1), (1, -1), (1, 1), (-1, 1)]
    helpers = []

    for module in (dn, ss):

        helper = module.elm_help()
        helper.allocate(2, 4, nip, order=order)
        helper.allocate_spatial(2, compute_Jinv=True)

        for ip, (xi, eta) in enumerate(points):

            helper.w[ip] = 1.0

            for a, (xa, ya) in enumerate(corners):

                helper.N.set_ijk(0.25 * (1 + xa * xi) * (1 + ya * eta), 0, a, ip)
                helper.Nxi.set_ijk(0.25 * xa * (1 + ya * eta), 0, a, ip)
                helper.Neta.set_ijk(0.25 * ya * (1 + xa * xi), 0, a, ip)

            # end for

        # end for

        x = module.zeros((4, 1), order=order)
        y = module.zeros((4, 1), order=order)

        for a, (xa, ya) in enumerate(corners):

            x[a, 0] = 2.0 * xa + 0.1 * module.e(1, order=order)
            y[a, 0] = 1.5 * ya + 0.2 * module.e(2, order=order) * xa

        # end for

        helper.set_coordinates(x, y, module.zeros((4, 1), order=order), np.arange(4))
        helper.compute_jacobian()
        helpers.append(helper)

    # end for

    dense_helper, semi_helper = helpers

    for name in ("detJ", "dV", "Nx", "Ny", "J", "Jinv"):

        for direction in (0, [1], [2], [1, 2], [2, 2]):

            np.testing.assert_allclose(getattr(dense_helper, name).get_im(direction),
                                       getattr(semi_helper, name).get_im(direction),
                                       rtol=1e-13, atol=1e-13)

        # end for

    # end for

    integral = dense_helper.integrate(dense_helper.Nx)
    semi_integral = semi_helper.integrate(semi_helper.Nx)

    for direction in (0, [1], [2], [1, 2]):

        np.testing.assert_allclose(integral.get_im(direction), semi_integral.get_im(direction),
                                   rtol=1e-13, atol=1e-13)

    # end for

    local = dense_helper.get_local(dn.zeros((6, 2), order=1) + 1.0, np.array([0, 2, 4]))
    assert local.shape == (3, 2)

# end function
# --------------------------------------------------------------------------------------------------------
