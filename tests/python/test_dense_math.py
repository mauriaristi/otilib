"""
Check dense elementary functions and algebra module functions against sparse for all public value
types (scalar, SoA and AoS arrays, Gauss-point values).
"""

from itertools import combinations_with_replacement

import numpy as np
import pytest

import pyoti.dense as dn
import pyoti.sparse as sp


ORDERS = (1, 2, 3, 4, 5)
RELATIONS = (
    ("same", (1, 2, 3), (1, 2, 3)),
    ("leading", (1, 2), (1, 2, 3, 4)),
    ("larger_nact", (1, 3, 5), (2, 4, 6)),
)
KINDS = ("otinum", "omat", "arro", "otife", "omatfe")
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
    Return the active sets for a same, leading or larger nact relation.

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
    Create a 2x2 sparse matrix with independent dense-friendly entries.

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
    Construct an input for one of the five public dense value types.

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
    if kind == "otinum":

        position = 1 if name == "abs" and not second else 0
        return _random_scalar(bases, order, seed, name, position=position, second=second)

    # end if

    if kind in ("omat", "arro"):

        return _random_matrix(bases, order, seed, name, second=second)

    # end if

    if kind == "otife":

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
def _to_dense(kind, value):
    """
    Convert a sparse input into the selected dense type.

    Parameters
    ----------
    kind : str
        Scalar, SoA, AoS or Gauss type name.
    value : object
        Sparse value.

    Returns
    -------
    object
        Dense value.
    """
    if kind == "otinum":

        return dn.otinum(value)

    elif kind == "omat":

        return dn.omat.from_sparse(value)

    elif kind == "arro":

        return dn.arro.from_sparse(value)

    elif kind == "otife":

        return dn.otife.from_sparse(value)

    else:

        return dn.omatfe.from_sparse(value)

    # end if

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _as_sparse(value):
    """
    Convert a dense result to its sparse counterpart for comparison.

    Parameters
    ----------
    value : object
        Dense value.

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
        Converted dense result.
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
def _gauss_ready():
    """
    Tell whether the dense Gauss-point types can be built from sparse values.

    Returns
    -------
    bool
        True once ``pyoti.dense.otife`` and ``pyoti.dense.omatfe`` implement ``from_sparse``.
    """
    return hasattr(dn.otife, "from_sparse") and hasattr(dn.omatfe, "from_sparse")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _evaluate(name, value):
    """
    Evaluate one public dense mathematical function.

    Parameters
    ----------
    name : str
        Function name.
    value : object
        Dense argument.

    Returns
    -------
    object
        Function result.
    """
    if name == "pow":

        return dn.pow(value, EXPONENT)

    elif name == "logb":

        return dn.logb(value, LOG_BASE)

    else:

        return getattr(dn, name)(value)

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
        Dense scalar, SoA, AoS or Gauss type.
    name : str
        Elementary function, abs, power or logarithm in a base.
    order : int
        Truncation order, one through five.
    relation : str
        Same, leading or larger nact active-set relationship.
    """
    if kind in ("otife", "omatfe") and not _gauss_ready():

        pytest.skip("the dense Gauss-point types are not implemented yet")

    # end if

    bases_argument, bases_second = _active_sets(relation)

    if kind in ("otife", "omatfe"):

        if kind == "otife":

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

    dn_argument = _to_dense(kind, sparse_argument)
    dn_second = _to_dense(kind, sparse_second)

    dn_result = _evaluate(name, dn_argument)
    sparse_result = _sparse_evaluate(name, sparse_argument)
    bases_result = tuple(sorted(set(bases_argument).union(bases_second)))
    _assert_sparse_equal(
        _as_sparse(dn_result),
        sparse_result,
        bases_argument,
        order,
    )

    dn_product = dn_result * dn_second
    sparse_product = sparse_result * sparse_second
    _assert_sparse_equal(
        _as_sparse(dn_product),
        sparse_product,
        bases_result,
        order,
    )

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sparse_reference(name, bases, order, seed=4000):
    """
    Build the sparse scalar and its dense image for the extra tests.

    Parameters
    ----------
    name : str
        Function under test (selects the real-part domain).
    bases : tuple of int
        Active basis labels.
    order : int
        Truncation order.
    seed : int
        Random generator seed.

    Returns
    -------
    tuple
        Sparse scalar and dense scalar.
    """
    sparse_value = _random_scalar(bases, order, seed, name)
    return sparse_value, dn.otinum(sparse_value)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", [n for n in FUNCTIONS if n not in ("abs", "pow", "logb")])
def test_real_argument_gives_a_float(name):
    """
    Check that a plain real goes through the floating-point function, as in pyoti.sparse.

    Parameters
    ----------
    name : str
        Elementary function.
    """
    low, high = DOMAIN.get(name, (0.6, 1.15))
    value = 0.5 * (low + high)

    result = getattr(dn, name)(value)

    assert isinstance(result, float)
    assert result == pytest.approx(getattr(sp, name)(value), rel=1e-15)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
def test_logb_and_pow_of_reals(order):
    """
    Check the logarithm in a base of a real and the power of a real.

    Parameters
    ----------
    order : int
        Truncation order (unused by reals; keeps the grid of the other tests).
    """
    assert dn.logb(7.5, LOG_BASE) == pytest.approx(np.log(7.5) / np.log(LOG_BASE), rel=1e-15)
    assert dn.pow(2.0, EXPONENT) == pytest.approx(2.0**EXPONENT, rel=1e-15)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", [n for n in FUNCTIONS if n not in ("abs", "pow", "logb")])
@pytest.mark.parametrize("order", ORDERS)
def test_sparse_scalar_argument_is_converted(name, order):
    """
    Check that a pyoti.sparse scalar passed to a dense function gives the dense result.

    Parameters
    ----------
    name : str
        Elementary function.
    order : int
        Truncation order.
    """
    bases = (1, 3, 5)
    sparse_value = _random_scalar(bases, order, 4000, name)

    result = getattr(dn, name)(sparse_value)

    assert isinstance(result, dn.otinum)
    _assert_sparse_equal(result.to_sparse(), _sparse_evaluate(name, sparse_value), bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", ["sin", "exp", "sqrt", "logb", "pow"])
@pytest.mark.parametrize("order", ORDERS)
def test_scalar_result_goes_into_out(name, order):
    """
    Check the ``out=`` holder of scalar functions, including a holder that is also the argument.

    Parameters
    ----------
    name : str
        Function under test.
    order : int
        Truncation order.
    """
    bases = (1, 2, 4)
    sparse_value, value = _sparse_reference(name, bases, order)
    expected = _sparse_evaluate(name, sparse_value)
    holder = dn.otinum(0.0)

    if name == "pow":

        assert dn.pow(value, EXPONENT, out=holder) is None

    elif name == "logb":

        assert dn.logb(value, LOG_BASE, out=holder) is None

    else:

        assert getattr(dn, name)(value, out=holder) is None

    # end if

    _assert_sparse_equal(holder.to_sparse(), expected, bases, order)

    # The holder is also the argument.
    aliased = dn.otinum(sparse_value)

    if name == "pow":

        dn.pow(aliased, EXPONENT, out=aliased)

    elif name == "logb":

        dn.logb(aliased, LOG_BASE, out=aliased)

    else:

        getattr(dn, name)(aliased, out=aliased)

    # end if

    _assert_sparse_equal(aliased.to_sparse(), expected, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("kind", ("omat", "arro"))
@pytest.mark.parametrize("order", ORDERS)
def test_array_result_goes_into_out(kind, order):
    """
    Check the ``out=`` holder of array functions and the shape check.

    Parameters
    ----------
    kind : str
        SoA or AoS array.
    order : int
        Truncation order.
    """
    bases = (1, 3, 5)
    sparse_value = _random_matrix(bases, order, 4000, "exp")
    value = _to_dense(kind, sparse_value)
    holder = _to_dense(kind, _random_matrix(bases, order, 5000, "exp"))

    assert dn.exp(value, out=holder) is None
    _assert_sparse_equal(_as_sparse(holder), sp.exp(sparse_value), bases, order)

    wrong = _to_dense(kind, sp.array([[1.0, 2.0, 3.0]], order=order))

    with pytest.raises(ValueError):

        dn.exp(value, out=wrong)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_function_of_a_scalar_keeps_its_nact_and_order():
    """
    Check that the result of a function has the argument's nact and truncation order, and that
    a scalar with a larger nact grows the result of a product with it.
    """
    argument = dn.e(3, order=3) + 1.0
    result = dn.exp(argument)

    assert result.nact == 3
    assert result.order == 3

    product = result * dn.e(5, order=3)

    assert product.nact == 5
    assert product.order == 3

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_type_errors():
    """
    Check that unsupported arguments raise TypeError rather than reaching the C kernels.
    """
    with pytest.raises(TypeError):

        dn.sin("text")

    # end with

    with pytest.raises(TypeError):

        dn.logb("text", 2.0)

    # end with

    with pytest.raises(TypeError):

        dn.transpose(1.0)

    # end with

    with pytest.raises(TypeError):

        dn.norm(dn.otinum(1.0))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _algebra_operands(kind, bases_left, bases_right, order):
    """
    Build two 2x2 operands of one array kind with their sparse images.

    Parameters
    ----------
    kind : str
        SoA or AoS array.
    bases_left : tuple of int
        Active bases of the first operand.
    bases_right : tuple of int
        Active bases of the second operand.
    order : int
        Truncation order.

    Returns
    -------
    tuple
        Sparse and dense first operand, sparse and dense second operand.
    """
    left = _random_matrix(bases_left, order, 4000, "sin")
    right = _random_matrix(bases_right, order, 4100, "sin", second=True)
    return left, _to_dense(kind, left), right, _to_dense(kind, right)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("kind", ("omat", "arro"))
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("relation", [entry[0] for entry in RELATIONS])
def test_algebra_functions_match_sparse(kind, order, relation):
    """
    Compare the module-level algebra functions with pyoti.sparse.

    Parameters
    ----------
    kind : str
        SoA or AoS array.
    order : int
        Truncation order.
    relation : str
        Same, leading or larger-nact relationship of the operands' active sets.
    """
    bases_left, bases_right = _active_sets(relation)
    union = tuple(sorted(set(bases_left).union(bases_right)))
    left_sp, left, right_sp, right = _algebra_operands(kind, bases_left, bases_right, order)

    for name in ("sum", "sub", "mul", "div", "dot", "matmul"):

        actual = getattr(dn, name)(left, right)
        expected = getattr(sp, "dot" if name == "matmul" else name)(left_sp, right_sp)
        _assert_sparse_equal(_as_sparse(actual), expected, union, order)

    # end for

    _assert_sparse_equal(_as_sparse(dn.neg(left)), sp.neg(left_sp), bases_left, order)
    _assert_sparse_equal(_as_sparse(dn.abs(left)), sp.abs(left_sp), bases_left, order)
    _assert_sparse_equal(_as_sparse(dn.transpose(left)), sp.transpose(left_sp), bases_left, order)

    for p in (1.0, 2.0, 3.0):

        _assert_sparse_equal(dn.norm(left, p).to_sparse(), sp.norm(left_sp, p), bases_left, order)

    # end for

    assert dn.get_active_bases(left) == list(range(1, max(bases_left) + 1))

    for direction in ([1], [2], [1, 2], [3, 3]):

        _assert_sparse_equal(
            _as_sparse(dn.truncate(direction, left)), sp.truncate(direction, left_sp), union, order
        )

        if len(direction) <= order:

            for name in ("get_im", "get_deriv"):

                actual = getattr(dn, name)(direction, left)
                expected = getattr(sp, name)(direction, left_sp)
                _assert_values_close(
                    np.asarray(actual.real), np.asarray(expected.real), RTOL
                )

            # end for

        # end if

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("kind", ("omat", "arro"))
@pytest.mark.parametrize("order", (1, 3, 5))
def test_algebra_out_holders_and_errors(kind, order):
    """
    Check ``out=`` of the algebra functions, scalar operands, and shape errors.

    Parameters
    ----------
    kind : str
        SoA or AoS array.
    order : int
        Truncation order.
    """
    bases = (1, 2, 3)
    left_sp, left, right_sp, right = _algebra_operands(kind, bases, bases, order)
    holder = _to_dense(kind, sp.array([[0.0, 0.0], [0.0, 0.0]], order=order))

    assert dn.sum(left, right, out=holder) is None
    _assert_sparse_equal(_as_sparse(holder), sp.sum(left_sp, right_sp), bases, order)

    assert dn.dot(left, right, out=holder) is None
    _assert_sparse_equal(_as_sparse(holder), sp.dot(left_sp, right_sp), bases, order)

    assert dn.sum(1.0, 2.0) == 3.0

    scalar_sp = _random_scalar(bases, order, 4200, "sin")
    scalar = dn.otinum(scalar_sp)
    _assert_sparse_equal(
        _as_sparse(dn.mul(scalar, left)), sp.mul(scalar_sp, left_sp), bases, order
    )

    wrong = _to_dense(kind, sp.array([[1.0, 2.0, 3.0]], order=order))

    with pytest.raises(ValueError):

        dn.sum(left, wrong)

    # end with

    with pytest.raises(ValueError):

        dn.dot(wrong, wrong)

    # end with

    scalar_holder = dn.otinum(0.0)
    assert dn.norm(left, out=scalar_holder) is None
    _assert_sparse_equal(scalar_holder.to_sparse(), sp.norm(left_sp), bases, order)

# end function
# --------------------------------------------------------------------------------------------------------
