"""
Check semi-sparse elementary functions against sparse for all public value types.
"""

from itertools import combinations_with_replacement

import numpy as np
import pytest

import pyoti.semisparse as ss
import pyoti.sparse as sp


ORDERS = (1, 2, 3, 4, 5)
RELATIONS = (
    ("same", (1, 2, 3), (1, 2, 3)),
    ("leading", (1, 2), (1, 2, 3, 4)),
    ("interleaved", (1, 3, 5), (2, 4, 6)),
)
KINDS = ("ssotinum", "oarrss", "arrss", "ssotife", "oarrssfe")
FUNCTIONS = (
    "sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh", "tanh", "asinh", "acosh",
    "atanh", "exp", "log", "log10", "sqrt", "cbrt", "erf", "abs", "pow", "logb",
)
DOMAIN = {
    "asin": (-0.35, 0.4),
    "acos": (-0.35, 0.4),
    "atanh": (-0.35, 0.4),
    "acosh": (1.3, 1.9),
}
EXPONENT = 1.37
LOG_BASE = 3.2
RTOL = 1e-13
ATOL = 1e-13


# ********************************************************************************************************
def _directions(bases, order):
    """
    Enumerate all nonconstant directions through an order over selected bases.

    Parameters
    ----------
    bases : tuple of int
        Sorted one-based global basis labels.
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
def _active_sets(relation):
    """
    Return the active sets for a same, leading or interleaved relation.

    Parameters
    ----------
    relation : str
        Active-set relationship.

    Returns
    -------
    tuple of tuple
        Argument and product-operand bases.
    """
    for name, left, right in RELATIONS:

        if relation == name:

            return left, right

        # end if

    # end for

    raise ValueError("unknown active-set relation {!r}".format(relation))

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _real_part(name, seed, position, second=False):
    """
    Select a real coefficient safely inside a function's domain.

    Parameters
    ----------
    name : str
        Function under test.
    seed : int
        Deterministic seed.
    position : int
        Point or matrix entry position.
    second : bool
        True for the post-function product operand.

    Returns
    -------
    float
        Domain-safe real part.
    """
    rng = np.random.default_rng(seed + 19 * position)

    if name == "abs":

        magnitude = float(rng.uniform(0.6, 1.2))

        if second or position % 2 == 0:

            return magnitude

        # end if

        return -magnitude

    # end if

    low, high = DOMAIN.get(name, (0.6, 1.15))
    return float(rng.uniform(low, high))

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _random_scalar(bases, order, seed, name, position=0, second=False):
    """
    Create a sparse scalar with reproducible coefficients in a function's domain.

    Parameters
    ----------
    bases : tuple of int
        Active basis labels.
    order : int
        Truncation order.
    seed : int
        Random generator seed.
    name : str
        Function under test.
    position : int
        Point or matrix entry index.
    second : bool
        True for the follow-up product operand.

    Returns
    -------
    sotinum
        Sparse scalar oracle input.
    """
    rng = np.random.default_rng(seed + 37 * position)
    result = sp.number(_real_part(name, seed, position, second), order=order)

    for base in bases:

        result.set_im(float(rng.uniform(-0.015, 0.015)), [base])

    # end for

    for degree in range(2, order + 1):

        for direction in combinations_with_replacement(bases, degree):

            if rng.uniform() < 0.45:

                result.set_im(float(rng.uniform(-0.01, 0.01)), list(direction))

            # end if

        # end for

    # end for

    return result

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _random_matrix(bases, order, seed, name, second=False):
    """
    Create a 2x2 sparse matrix with independent semi-sparse-friendly entries.

    Parameters
    ----------
    bases : tuple of int
        Active basis labels.
    order : int
        Truncation order.
    seed : int
        Random generator seed.
    name : str
        Function under test.
    second : bool
        True for the follow-up product operand.

    Returns
    -------
    matso
        Sparse matrix oracle input.
    """
    entries = []

    for i in range(2):

        row = []

        for j in range(2):

            position = 2 * i + j
            row.append(
                _random_scalar(
                    bases, order, seed, name, position=position, second=second
                )
            )

        # end for

        entries.append(row)

    # end for

    return sp.array(entries, order=order)

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sparse_gauss_scalar(points, order):
    """
    Pack pointwise sparse scalars into one sparse Gauss scalar.

    Parameters
    ----------
    points : list of sotinum
        Values at the integration points.
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
def _sparse_gauss_array(points, order):
    """
    Pack pointwise sparse matrices into one sparse Gauss matrix.

    Parameters
    ----------
    points : list of matso
        Matrices at the integration points.
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
def _make_sparse_value(kind, bases, order, seed, name, second=False):
    """
    Construct an input for one of the five public semi-sparse value types.

    Parameters
    ----------
    kind : str
        Scalar, SoA, AoS or Gauss type name.
    bases : tuple of int
        Active basis labels.
    order : int
        Truncation order.
    seed : int
        Random generator seed.
    name : str
        Function under test.
    second : bool
        True for the follow-up product operand.

    Returns
    -------
    object
        Sparse scalar, matrix or Gauss value.
    """
    if kind == "ssotinum":

        position = 1 if name == "abs" and not second else 0
        return _random_scalar(bases, order, seed, name, position=position, second=second)

    # end if

    if kind in ("oarrss", "arrss"):

        return _random_matrix(bases, order, seed, name, second=second)

    # end if

    if kind == "ssotife":

        points = [
            _random_scalar(bases, order, seed, name, position=ip, second=second)
            for ip in range(4)
        ]

        return _sparse_gauss_scalar(points, order)

    # end if

    points = [
        _random_matrix(bases, order, seed + ip, name, second=second)
        for ip in range(4)
    ]
    return _sparse_gauss_array(points, order)

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _to_semisparse(kind, value):
    """
    Convert a sparse input into the selected semi-sparse type.

    Parameters
    ----------
    kind : str
        Scalar, SoA, AoS or Gauss type name.
    value : object
        Sparse value.

    Returns
    -------
    object
        Semi-sparse value.
    """
    if kind == "ssotinum":

        return ss.ssotinum(value)

    elif kind == "oarrss":

        return ss.oarrss.from_sparse(value)

    elif kind == "arrss":

        return ss.arrss.from_sparse(value)

    elif kind == "ssotife":

        return ss.ssotife.from_sparse(value)

    else:

        return ss.oarrssfe.from_sparse(value)

    # end if

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _as_sparse(value):
    """
    Convert a semi-sparse result to its sparse counterpart for comparison.

    Parameters
    ----------
    value : object
        Semi-sparse value.

    Returns
    -------
    object
        Sparse scalar, matrix or Gauss value.
    """
    return value.to_sparse()

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _real_block(value):
    """
    Return a sparse value's real coefficient in a common NumPy shape.

    Parameters
    ----------
    value : object
        Sparse scalar, matrix or Gauss value.

    Returns
    -------
    float or numpy.ndarray
        Real coefficient block.
    """
    if isinstance(value, sp.sotinum):

        return float(value.real)

    elif isinstance(value, sp.matso):

        return np.asarray(value.real)

    elif isinstance(value, sp.sotife):

        return np.asarray(value.real_numpy)

    else:

        return np.asarray(value.real_numpy).transpose(2, 0, 1)

    # end if

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _coefficient_block(value, direction):
    """
    Return one sparse coefficient block in the common NumPy layout.

    Parameters
    ----------
    value : object
        Sparse scalar, matrix or Gauss value.
    direction : tuple of int
        Direction whose coefficient is requested.

    Returns
    -------
    float or numpy.ndarray
        Coefficient block.
    """
    if isinstance(value, sp.sotinum):

        return float(value.get_im(direction))

    elif isinstance(value, sp.matso):

        result = value.get_im(direction)
        return np.asarray(result.real if hasattr(result, "real") else result)

    elif isinstance(value, sp.sotife):

        return np.asarray(value.get_im(direction).real_numpy)

    else:

        return np.asarray(value.get_im(direction).real_numpy).transpose(2, 0, 1)

    # end if

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_sparse_equal(actual, expected, bases, order, tolerance=RTOL):
    """
    Compare every coefficient of two sparse values.

    Parameters
    ----------
    actual : object
        Converted semi-sparse result.
    expected : object
        Sparse oracle result.
    bases : tuple of int
        Union of active input bases.
    order : int
        Highest order to compare.
    tolerance : float
        Relative tolerance; scaled absolute tolerance is used for near-zero coefficients.
    """
    if isinstance(expected, (sp.sotife, sp.matsofe)):

        assert actual.nip == expected.nip

    # end if

    if isinstance(expected, (sp.matso, sp.matsofe)):

        assert actual.shape == expected.shape

    # end if

    assert actual.order == expected.order
    _assert_values_close(_real_block(actual), _real_block(expected), tolerance)

    for direction in _directions(bases, order):

        _assert_values_close(
            _coefficient_block(actual, direction),
            _coefficient_block(expected, direction),
            tolerance,
        )

    # end for

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_values_close(actual, expected, tolerance):
    """
    Compare numeric coefficient blocks using a relative and scaled absolute tolerance.

    Parameters
    ----------
    actual : array_like
        Computed block.
    expected : array_like
        Sparse reference block.
    tolerance : float
        Relative tolerance and scale factor for absolute tolerance.
    """
    expected = np.asarray(expected, dtype=np.float64)
    actual = np.asarray(actual, dtype=np.float64)
    scale = max(1.0, float(np.max(np.abs(expected)))) if expected.size else 1.0

    assert actual.shape == expected.shape
    np.testing.assert_allclose(
        actual,
        expected,
        rtol=tolerance,
        atol=tolerance * scale,
    )

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _evaluate(name, value):
    """
    Evaluate one public semi-sparse mathematical function.

    Parameters
    ----------
    name : str
        Function name.
    value : object
        Semi-sparse argument.

    Returns
    -------
    object
        Function result.
    """
    if name == "pow":

        return ss.pow(value, EXPONENT)

    elif name == "logb":

        return ss.logb(value, LOG_BASE)

    else:

        return getattr(ss, name)(value)

    # end if

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sparse_evaluate(name, value):
    """
    Evaluate the sparse oracle function corresponding to a test name.

    Parameters
    ----------
    name : str
        Function name.
    value : object
        Sparse argument.

    Returns
    -------
    object
        Sparse function result.
    """
    if name == "pow":

        return sp.pow(value, EXPONENT)

    elif name == "logb":

        return sp.logb(value, LOG_BASE)

    else:

        return getattr(sp, name)(value)

    # end if

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("kind", KINDS)
@pytest.mark.parametrize("name", FUNCTIONS)
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("relation", [entry[0] for entry in RELATIONS])
def test_math_function_and_union_product_match_sparse(kind, name, order, relation):
    """
    Compare each function and its product with a second active set against sparse.

    Parameters
    ----------
    kind : str
        Semi-sparse scalar, SoA, AoS or Gauss type.
    name : str
        Elementary function, abs, power or logarithm in a base.
    order : int
        Truncation order, one through five.
    relation : str
        Same, leading or interleaved active-set relationship.
    """
    bases_argument, bases_second = _active_sets(relation)

    if kind in ("ssotife", "oarrssfe"):

        nip = 4

        if kind == "ssotife":

            sparse_argument = _make_sparse_value(kind, bases_argument, order, 4000, name)
            sparse_second = _make_sparse_value(
                kind, bases_second, order, 4100, name, second=True
            )

        else:

            sparse_argument = _make_sparse_value(kind, bases_argument, order, 4000, name)
            sparse_second = _make_sparse_value(
                kind, bases_second, order, 4100, name, second=True
            )

        # end if

    else:

        sparse_argument = _make_sparse_value(kind, bases_argument, order, 4000, name)
        sparse_second = _make_sparse_value(kind, bases_second, order, 4100, name, second=True)

    # end if

    semi_argument = _to_semisparse(kind, sparse_argument)
    semi_second = _to_semisparse(kind, sparse_second)

    semi_result = _evaluate(name, semi_argument)
    sparse_result = _sparse_evaluate(name, sparse_argument)
    bases_result = tuple(sorted(set(bases_argument).union(bases_second)))
    _assert_sparse_equal(
        _as_sparse(semi_result),
        sparse_result,
        bases_argument,
        order,
    )

    semi_product = semi_result * semi_second
    sparse_product = sparse_result * sparse_second
    _assert_sparse_equal(
        _as_sparse(semi_product),
        sparse_product,
        bases_result,
        order,
    )

# end function
# --------------------------------------------------------------------------------------------------------
