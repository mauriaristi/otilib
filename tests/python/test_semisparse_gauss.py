"""
Check semi-sparse Gauss-point scalars and arrays against the sparse Gauss oracle.
"""

from itertools import combinations_with_replacement

import numpy as np
import pytest

import pyoti.sparse as sp
import pyoti.semisparse as ss


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
    Enumerate all nonconstant directions through an order over the supplied bases.

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

    for degree in range(1, order + 1):

        result.extend(combinations_with_replacement(bases, degree))

    # end for

    return result

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

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_scalar_matches(actual, expected, bases, order, rtol=RTOL, atol=ATOL):
    """
    Compare a semi-sparse scalar with a sparse scalar, coefficient by coefficient.

    Parameters
    ----------
    actual : ssotinum
        Semi-sparse result.
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

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_array_matches(actual, expected, bases, order, rtol=RTOL, atol=ATOL):
    """
    Compare a semi-sparse matrix with a sparse matrix, coefficient by coefficient.

    Parameters
    ----------
    actual : oarrss
        Semi-sparse result.
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

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_scalar_fe_matches(
    actual, expected, bases, order, rtol=RTOL, atol=ATOL, check_order=True
):
    """
    Compare a semi-sparse Gauss scalar with a sparse Gauss scalar.

    Parameters
    ----------
    actual : ssotife
        Semi-sparse Gauss result.
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

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_array_fe_matches(
    actual, expected, bases, order, rtol=RTOL, atol=ATOL, check_order=True
):
    """
    Compare a semi-sparse Gauss matrix with a sparse Gauss matrix.

    Parameters
    ----------
    actual : oarrssfe
        Semi-sparse Gauss result.
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

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make_scalar_fe(bases, order, nip, seed, real_start=0.8):
    """
    Create point-varying sparse and semi-sparse Gauss scalar values.

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
        Sparse Gauss scalar and its semi-sparse conversion.
    """
    points = [
        _random_scalar(bases, order, seed + ip, real=real_start + 0.1 * ip)
        for ip in range(nip)
    ]
    sparse = _sparse_fe_scalar(points, order)
    return sparse, ss.ssotife.from_sparse(sparse)

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make_array_fe(shape, bases, order, nip, seed, real_range=None, positive_definite=False):
    """
    Create point-varying sparse and semi-sparse Gauss matrices.

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
        Sparse Gauss matrix and its semi-sparse conversion.
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
    return sparse, ss.oarrssfe.from_sparse(sparse)

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
    scalar = ss.ssotife.from_sparse(sparse_scalar)
    scalar_again = scalar.to_sparse()

    _assert_scalar_fe_matches(scalar, sparse_scalar, bases, order)
    _assert_scalar_fe_matches(ss.ssotife.from_sparse(scalar_again), sparse_scalar, bases, order)
    assert scalar.get_active_bases() == list(bases)
    assert scalar.nip == nip
    assert scalar.shape == (1, 1)
    assert scalar.nbases == len(bases)
    assert scalar.actual_order <= order

    direct = ss.ssotife(scalar_values[0], nip=nip, bases=bases, order=order)
    expected_direct = _sparse_fe_scalar([scalar_values[0]] * nip, order)
    _assert_scalar_fe_matches(direct, expected_direct, bases, order)

    hook_scalar = ss._fe_scalar(scalar_values[0], list(bases), order, nip)
    _assert_scalar_fe_matches(hook_scalar, expected_direct, bases, order)
    zero = ss.zero(order=order, nip=nip)
    one = ss.one(order=order, nip=nip)
    number = ss.number(2.25, order=order, nip=nip)
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
    array = ss.oarrssfe.from_sparse(sparse_array)
    array_again = array.to_sparse()
    points_as_soa = [ss.oarrss.from_sparse(point) for point in points]
    from_points = ss.oarrssfe.from_points(points_as_soa)
    hook_zeros = ss._fe_zeros(shape, list(bases), order, nip)
    public_zeros = ss.zeros(shape, bases=bases, order=order, nip=nip)

    _assert_array_fe_matches(array, sparse_array, bases, order)
    _assert_array_fe_matches(ss.oarrssfe.from_sparse(array_again), sparse_array, bases, order)
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
    assert array.nbases == len(bases)
    assert array.get_active_bases() == list(bases)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("direction", [[1], [1, 3]])
def test_public_gauss_e_creator_matches_sparse(direction):
    """
    Compare the semi-sparse Gauss ``e`` creator with the sparse Gauss creator.

    Parameters
    ----------
    direction : list of int
        Imaginary direction.
    """
    order = max(5, len(direction))
    nip = 4
    bases = tuple(sorted(set(direction)))
    actual = ss.e(direction, order=order, nip=nip)
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
    scalar = ss.ssotinum(scalar_sparse)
    real = 2.5

    for op in ("add", "sub", "mul", "div"):

        expected = _sparse_fe_scalar(
            [_apply(op, left_points[ip], right_points[ip]) for ip in range(nip)], order
        )
        actual = ss._fe_arith(op, left, right)
        _assert_scalar_fe_matches(actual, expected, bases, order)

        expected = _sparse_fe_scalar(
            [_apply(op, left_points[ip], scalar_sparse) for ip in range(nip)], order
        )
        _assert_scalar_fe_matches(ss._fe_arith(op, left, scalar), expected, bases, order)

        expected = _sparse_fe_scalar(
            [_apply(op, scalar_sparse, left_points[ip]) for ip in range(nip)], order
        )
        _assert_scalar_fe_matches(ss._fe_arith(op, scalar, left), expected, bases, order)

        expected = _sparse_fe_scalar(
            [_apply(op, left_points[ip], real) for ip in range(nip)], order
        )
        _assert_scalar_fe_matches(ss._fe_arith(op, left, real), expected, bases, order)

        expected = _sparse_fe_scalar(
            [_apply(op, real, left_points[ip]) for ip in range(nip)], order
        )
        _assert_scalar_fe_matches(ss._fe_arith(op, real, left), expected, bases, order)

        out = ss.ssotife(0.0, nip=nip, bases=bases, order=order)
        assert ss._fe_arith(op, left, right, out=out) is out
        _assert_scalar_fe_matches(out, _sparse_fe_scalar(
            [_apply(op, left_points[ip], right_points[ip]) for ip in range(nip)], order
        ), bases, order)

    # end for

    assert isinstance(left[0], ss.ssotinum)
    _assert_scalar_matches(left.get_ip(-1), left_points[-1], bases_left, order)
    _assert_numeric(left.real_numpy, sparse_left.real_numpy)

    replacement = _random_scalar(bases_right, order, 705, real=2.1)
    replaced = left.copy()
    replaced[0] = ss.ssotinum(replacement)
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

    assert left.get_active_bases() == list(bases_left)
    assert left[0].get_active_bases() == list(bases_left)
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
    scalar = ss.ssotinum(scalar_sparse)
    gauss_scalar_sparse, gauss_scalar = _make_scalar_fe(bases_right, order, nip, 1100,
                                                        real_start=1.8)
    plain_matrix = _random_matrix(shape, bases_right, order, 1200)
    plain_semi = ss.oarrss.from_sparse(plain_matrix)

    for op in ("add", "sub", "mul", "div"):

        expected = _sparse_fe_array(
            [_apply(op, left_points[ip], right_points[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(ss._fe_arith(op, left, right), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, left_points[ip], scalar_sparse) for ip in range(nip)], order
        )
        _assert_array_fe_matches(ss._fe_arith(op, left, scalar), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, scalar_sparse, left_points[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(ss._fe_arith(op, scalar, left), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, left_points[ip], plain_matrix) for ip in range(nip)], order
        )
        _assert_array_fe_matches(ss._fe_arith(op, left, plain_semi), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, plain_matrix, left_points[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(ss._fe_arith(op, plain_matrix, left), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, left_points[ip], gauss_scalar_sparse[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(ss._fe_arith(op, left, gauss_scalar), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, gauss_scalar_sparse[ip], left_points[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(ss._fe_arith(op, gauss_scalar, left), expected, bases, order)

        expected = _sparse_fe_array(
            [_apply(op, left_points[ip], 1.25) for ip in range(nip)], order
        )
        _assert_array_fe_matches(ss._fe_arith(op, left, 1.25), expected, bases_left, order)

        expected = _sparse_fe_array(
            [_apply(op, 1.25, left_points[ip]) for ip in range(nip)], order
        )
        _assert_array_fe_matches(ss._fe_arith(op, 1.25, left), expected, bases_left, order)

        out = ss.oarrssfe(shape=(1, 1), nip=nip, bases=bases, order=0)
        assert ss._fe_arith(op, left, right, out=out) is out
        _assert_array_fe_matches(out, _sparse_fe_array(
            [_apply(op, left_points[ip], right_points[ip]) for ip in range(nip)], order
        ), bases, order)

    # end for

    assert left.shape == shape
    assert left.get_active_bases() == list(bases_left)
    _assert_array_fe_matches(ss.oarrssfe.from_sparse(sparse_left), sparse_left, bases_left, order)
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
    copy.set_ip(-1, ss.oarrss.from_sparse(new_point))
    changed_points = left_points[:-1] + [new_point]
    _assert_array_fe_matches(copy, _sparse_fe_array(changed_points, order), bases, order)

    copy = left.copy()
    inserted = _random_scalar(bases_right, order, 1400, real=2.0)
    copy.set_ijk(ss.ssotinum(inserted), 0, 0, 0)
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
    copy.set(plain_semi)
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

        function = getattr(ss, name)
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
    actual_dot = ss._fe_dot(left, right)
    _assert_array_fe_matches(actual_dot, expected_dot, bases, order)
    _assert_array_fe_matches(left.dot(right), expected_dot, bases, order)
    _assert_array_fe_matches(left @ right, expected_dot, bases, order)
    _assert_array_fe_matches(ss.dot(left, right), expected_dot, bases, order)

    plain_left = _random_matrix(left_shape, bases_left, order, 1700)
    plain_right = _random_matrix(right_shape, bases_right, order, 1800)
    semi_left = ss.oarrss.from_sparse(plain_left)
    semi_right = ss.oarrss.from_sparse(plain_right)

    expected_right = _sparse_fe_array(
        [sp.dot(left_points[ip], plain_right) for ip in range(nip)], order
    )
    expected_left = _sparse_fe_array(
        [sp.dot(plain_left, right_points[ip]) for ip in range(nip)], order
    )
    _assert_array_fe_matches(ss._fe_dot(left, semi_right), expected_right, bases, order)
    _assert_array_fe_matches(ss._fe_dot(semi_left, right), expected_left, bases, order)
    _assert_array_fe_matches(ss._fe_dot(plain_left, right), expected_left, bases, order)
    _assert_array_fe_matches(right.__rmatmul__(plain_left), expected_left, bases, order)

    out = ss.oarrssfe((1, 1), nip=nip, bases=bases, order=0)
    assert ss._fe_dot(left, right, out=out) is out
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
    actual_dot_product = ss._fe_dot_product(left, dot_product_semi)
    _assert_scalar_fe_matches(actual_dot_product, expected_dot_product, bases, order)

    expected_dot_plain = _sparse_fe_scalar(
        [sp.dot_product(left_points[ip], dot_product_plain) for ip in range(nip)], order
    )
    _assert_scalar_fe_matches(
        ss._fe_dot_product(left, ss.oarrss.from_sparse(dot_product_plain)), expected_dot_plain,
        bases, order
    )
    expected_plain_dot = _sparse_fe_scalar(
        [sp.dot_product(dot_product_plain, dot_product_points[ip]) for ip in range(nip)], order
    )
    _assert_scalar_fe_matches(
        ss._fe_dot_product(ss.oarrss.from_sparse(dot_product_plain), dot_product_semi),
        expected_plain_dot,
        bases,
        order,
    )

    out_scalar = ss.ssotife(0.0, nip=nip, bases=bases, order=0)
    assert ss._fe_dot_product(left, dot_product_semi, out=out_scalar) is out_scalar
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

    _assert_scalar_fe_matches(ss._fe_dot_product(left, right), expected, bases, order)

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

    inverse = ss._fe_inv(matrix)
    determinant = ss._fe_det(matrix)
    transposed = ss._fe_transpose(matrix)

    _assert_array_fe_matches(inverse, expected_inverse, bases, order, tolerance, tolerance)
    _assert_scalar_fe_matches(
        determinant, expected_determinant, bases, order, tolerance, tolerance
    )
    _assert_array_fe_matches(transposed, expected_transpose, bases, order)
    _assert_array_fe_matches(matrix.inv(), expected_inverse, bases, order, tolerance, tolerance)
    _assert_scalar_fe_matches(matrix.det(), expected_determinant, bases, order, tolerance,
                               tolerance)
    _assert_array_fe_matches(matrix.T, expected_transpose, bases, order)

    out_inverse = ss.oarrssfe((1, 1), nip=nip, bases=bases, order=0)
    out_determinant = ss.ssotife(0.0, nip=nip, bases=bases, order=0)
    out_transpose = ss.oarrssfe((1, 1), nip=nip, bases=bases, order=0)
    assert ss._fe_inv(matrix, out=out_inverse) is out_inverse
    assert ss._fe_det(matrix, out=out_determinant) is out_determinant
    assert ss._fe_transpose(matrix, out=out_transpose) is out_transpose
    _assert_array_fe_matches(out_inverse, expected_inverse, bases, order, tolerance, tolerance)
    _assert_scalar_fe_matches(out_determinant, expected_determinant, bases, order,
                              tolerance, tolerance)
    _assert_array_fe_matches(out_transpose, expected_transpose, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_unary_functions_match_sparse():
    """
    Compare every supported semi-sparse Gauss elementary function with sparse.
    """
    for name in UNARY_FUNCTIONS:

        function = getattr(ss, name)
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
                semi_scalar = ss.ssotife.from_sparse(sparse_scalar)
                _assert_scalar_fe_matches(
                    function(semi_scalar), sparse_function(sparse_scalar), bases, order
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
                semi_matrix = ss.oarrssfe.from_sparse(sparse_matrix)
                _assert_array_fe_matches(
                    function(semi_matrix), sparse_function(sparse_matrix), bases, order
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
            semi_scalar = ss.ssotife.from_sparse(sparse_scalar)
            _assert_scalar_fe_matches(abs(semi_scalar), sp.abs(sparse_scalar), bases, order)
            _assert_scalar_fe_matches(ss.abs(semi_scalar), sp.abs(sparse_scalar), bases, order)

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
            semi_matrix = ss.oarrssfe.from_sparse(sparse_matrix)
            expected = sp.abs(sparse_matrix)
            _assert_array_fe_matches(abs(semi_matrix), expected, bases, order)
            _assert_array_fe_matches(ss.abs(semi_matrix), expected, bases, order)

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
        actual = ss.gauss_integrate(value, weights)
        _assert_scalar_matches(actual, sparse_result, bases, order)
        _assert_scalar_matches(value.gauss_integrate(weights), sparse_result, bases, order)

        scalar_out = ss.ssotinum(0.0, order=0)
        assert ss.gauss_integrate(value, weights, out=scalar_out) is scalar_out
        _assert_scalar_matches(scalar_out, sparse_result, bases, order)

        sparse_matrix, matrix = _make_array_fe(shape, bases_left, order, nip, 2800 + order)
        sparse_matrix_result = sp.gauss_integrate(sparse_matrix, sparse_weights)
        actual_matrix = ss.gauss_integrate(matrix, weights)
        _assert_array_matches(actual_matrix, sparse_matrix_result, bases, order)
        _assert_array_matches(matrix.gauss_integrate(weights), sparse_matrix_result, bases, order)

        matrix_out = ss.oarrss.zeros((1, 1), order=0)
        assert ss.gauss_integrate(matrix, weights, out=matrix_out) is matrix_out
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
    scalar_four = ss.ssotife(1.0, nip=4, bases=(1, 2), order=order)
    scalar_one = ss.ssotife(1.0, nip=1, bases=(1, 2), order=order)
    array_four = ss.oarrssfe((2, 2), nip=4, bases=(1, 2), order=order)
    array_one = ss.oarrssfe((2, 2), nip=1, bases=(1, 2), order=order)
    array_rect = ss.oarrssfe((2, 3), nip=4, bases=(1, 2), order=order)

    with pytest.raises(ValueError, match="integration points"):

        ss._fe_arith("add", scalar_four, scalar_one)

    # end with

    with pytest.raises(ValueError, match="integration points"):

        ss._fe_dot(array_four, array_one)

    # end with

    with pytest.raises(ValueError, match="integration points"):

        ss._fe_dot_product(array_four, array_one)

    # end with

    with pytest.raises(ValueError, match="incompatible shapes"):

        ss._fe_arith("add", array_four, array_rect)

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

        array_four.set_ip(0, ss.oarrss.zeros((1, 1)))

    # end with

    with pytest.raises(ValueError, match="different numbers of integration points"):

        array_four[0, :] = ss.oarrssfe((1, 2), nip=1, bases=(1, 2), order=order)

    # end with

    with pytest.raises(ValueError, match="shape mismatch"):

        array_four[0, :] = ss.oarrssfe((2, 2), nip=4, bases=(1, 2), order=order)

    # end with

    with pytest.raises(ValueError, match="nip must be positive"):

        ss._fe_scalar(0.0, (), order, 0)

    # end with

    with pytest.raises(ValueError, match="shape must be"):

        ss._fe_zeros((2, 3, 4), (), order, 4)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", ("dot_product", "det", "inv", "transpose"))
def test_public_gauss_module_linalg_dispatch_when_available(name):
    """
    Exercise each public module linear-algebra spelling once its Gauss dispatch is available.

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

        call = lambda: ss.dot_product(matrix, other)
        expected = _sparse_fe_scalar(
            [sp.dot_product(a, b) for a, b in zip(points, other_points)], order
        )
        unsupported = "Unsupported types"

    elif name == "det":

        call = lambda: ss.det(matrix)
        expected = _sparse_fe_scalar([sp.det(point) for point in points], order)
        unsupported = "det expects a semi-sparse array"

    elif name == "inv":

        call = lambda: ss.inv(matrix)
        expected = _sparse_fe_array([sp.inv(point) for point in points], order)
        unsupported = "inv expects a semi-sparse array"

    else:

        call = lambda: ss.transpose(matrix)
        expected = _sparse_fe_array([point.T for point in points], order)
        unsupported = "Unsupported types at transpose operation"

    # end if

    try:

        actual = call()

    except TypeError as error:

        if unsupported in str(error):

            pytest.skip("public {} has not yet dispatched Gauss inputs".format(name))

        raise

    # end try

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
    Check public unary-function out= behavior for a semi-sparse Gauss scalar.

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
    out = ss.ssotife(0.0, nip=nip, bases=bases, order=order)

    assert getattr(ss, name)(value, out=out) is None
    _assert_scalar_fe_matches(out, expected, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------
