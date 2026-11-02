"""
Compare AoS dense arrays with the public sparse matrix API.
"""

import numpy as np
import pytest

import pyoti.dense as dn
import pyoti.sparse as sparse


FUNCTIONS = ("sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh", "tanh",
             "asinh", "acosh", "atanh", "exp", "log", "log10", "sqrt", "cbrt", "erf")


# ********************************************************************************************************
def _same(actual, expected, order=2):
    """
    Compare real and imaginary coefficients across an AoS matrix.

    Parameters
    ----------
    actual : arro
        Dense result.
    expected : matso
        Sparse oracle.
    order : int
        Highest direction order to compare.
    """

    assert actual.shape == expected.shape

    for i in range(actual.shape[0]):

        for j in range(actual.shape[1]):

            a, b = actual[i, j], expected[i, j]
            assert a.real == pytest.approx(b.real, abs=1e-9)

            for direction in (1, 2, [1, 2], [[1, 2]], [[2, 2]]):

                if isinstance(direction, int) or order > 1:

                    assert a.get_im(direction) == pytest.approx(
                        b.get_im(direction), rel=1e-8, abs=1e-9)

                # end if

            # end for

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _matrix():
    """
    Construct a diagonally dominant sparse array with element-specific bases.

    Returns
    -------
    matso
        Sparse reference.
    """

    e1 = sparse.e(1, order=2)
    e2 = sparse.e(2, order=2)
    return sparse.array([[3.0 + 0.1 * e1, 0.2 + 0.05 * e2],
                         [0.1 + 0.03 * e1, 2.5 + 0.08 * e2]])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_conversions_and_element_access():
    """
    Preserve per-element active sets and avoid aliasing element copies.
    """

    source = _matrix()
    matrix = dn.arro.from_sparse(source)
    assert matrix.shape == (2, 2)
    assert matrix.order == 2
    assert matrix[0, 0].active_bases == (1,)
    assert matrix[0, 1].active_bases == (1, 2)
    _same(matrix, source)
    _same(dn.arro.from_sparse(matrix.to_sparse()), source)
    soa = matrix.to_soa()
    assert soa.active_bases == (1, 2)
    _same(soa.to_aos(), source)
    _same(dn.arro.from_soa(soa), source)
    item = matrix[0, 0]
    item.set_im(0.75, 1)
    assert matrix[0, 0].get_im(1) == pytest.approx(0.1)
    matrix[0, 0] = item
    assert matrix[0, 0].get_im(1) == pytest.approx(0.75)
    matrix[0, 0] = source[0, 0]
    matrix[1, 0] = 0.3
    assert matrix[1, 0].real == pytest.approx(0.3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_zeros_and_truncation():
    """
    Test zero construction, set growth, order extraction and per-element compaction.
    """

    matrix = dn.arro.zeros((2, 2), order=2)
    assert matrix.order == 2
    matrix[0, 0] = dn.otinum(sparse.e(1, order=2) + sparse.e(2, order=2))
    matrix[1, 1] = sparse.e(2, order=2)
    assert matrix[0, 0].active_bases == (1, 2)
    assert matrix[1, 1].active_bases == (1, 2)
    matrix[0, 0] = dn.otinum(2.0, order=2)
    assert matrix[0, 0].real == pytest.approx(2.0)
    source = _matrix()
    value = dn.arro.from_sparse(source)
    _same(value.truncate(1), sparse.truncate(1, source))
    _same(value.truncate_order(2), source.truncate_order(2), order=1)
    _same(value.get_order_im(1), source.get_order_im(1), order=1)
    _same(value.compact(), source)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_elementwise_and_matrix_algebra():
    """
    Compare AoS array and scalar operations against sparse results.
    """

    source = _matrix()
    matrix = dn.arro.from_sparse(source)

    for actual, expected in ((matrix + matrix, source + source),
                             (matrix - matrix, source - source),
                             (matrix * matrix, source * source),
                             (matrix / matrix, source / source),
                             (matrix + 1.5, source + 1.5),
                             (1.5 - matrix, 1.5 - source),
                             (matrix * 1.5, source * 1.5),
                             (1.5 / matrix, 1.5 / source),
                             (matrix + dn.otinum(1.0), source + 1.0),
                             (matrix ** 1.5, sparse.pow(source, 1.5)),
                             (-matrix, -source),
                             (matrix @ matrix, sparse.dot(source, source)),
                             (dn.matmul(matrix, matrix), sparse.dot(source, source)),
                             (matrix.T, sparse.transpose(source))):

        _same(actual, expected)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", FUNCTIONS)
def test_aos_elementwise_functions(name):
    """
    Compare each elementary function with its sparse matrix counterpart.

    Parameters
    ----------
    name : str
        Function name.
    """

    base = 0.2 if name in ("asin", "acos", "atanh") else 1.5
    source = sparse.array([[base + 0.01 * sparse.e(1, order=2), base + 0.02 *
                            sparse.e(2, order=2)]])
    _same(getattr(dn, name)(dn.arro.from_sparse(source)),
          getattr(sparse, name)(source))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_linear_algebra_and_status():
    """
    Compare direct solve, inverse and determinant, including a singular error.
    """

    source = _matrix()
    rhs = sparse.array([[1.0 + sparse.e(1, order=2)], [2.0]])
    matrix = dn.arro.from_sparse(source)
    vector = dn.arro.from_sparse(rhs)
    _same(dn.solve(matrix, vector), sparse.solve(source, rhs))
    _same(dn.inv(matrix), sparse.inv(source))
    determinant = dn.det(matrix)
    reference = sparse.det(source)
    assert determinant.real == pytest.approx(reference.real)
    assert determinant.get_im(1) == pytest.approx(reference.get_im(1))

    with pytest.raises(np.linalg.LinAlgError):

        dn.solve(dn.arro.zeros((2, 2)), dn.arro.zeros((2, 1)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_elements_keep_their_own_nact_and_order():
    """
    Check that AoS elements keep their own nact and truncation order, and that the SoA conversion
    takes the maxima.
    """
    matrix = dn.arro.zeros((2, 2), order=1)
    matrix[0, 0] = dn.e(3, order=2) + 1.0
    matrix[1, 1] = dn.e(1, order=4) + 2.0

    assert matrix[0, 0].nact == 3
    assert matrix[1, 1].nact == 1
    assert matrix[0, 1].nact == 0
    assert matrix[0, 0].order == 2
    assert matrix[1, 1].order == 4
    assert matrix.order == 4

    soa = matrix.to_soa()

    assert soa.nact == 3
    assert soa.order == 4
    assert soa[0, 0].get_im(3) == pytest.approx(1.0)
    assert soa[1, 1].get_im(1) == pytest.approx(1.0)

    back = soa.to_aos()

    assert all(back[i, j].nact == 3 and back[i, j].order == 4 for i in range(2) for j in range(2))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_linear_algebra_with_mixed_nact_elements():
    """
    Check solve, inv and det of AoS matrices whose elements have different nact, against sparse.
    """
    entries = [[2.0 + 0.1 * sparse.e(1, order=2), 0.3 + 0.05 * sparse.e(4, order=2)],
               [0.2, 3.0 + 0.2 * sparse.e(2, order=2)]]
    source = sparse.array(entries, order=2)
    rhs_source = sparse.array([[1.0 + 0.1 * sparse.e(3, order=2)], [2.0]], order=2)
    matrix = dn.arro.from_sparse(source)
    rhs = dn.arro.from_sparse(rhs_source)

    assert matrix[0, 0].nact == 1
    assert matrix[0, 1].nact == 4

    _same(dn.solve(matrix, rhs), sparse.solve(source, rhs_source))
    _same(dn.inv(matrix), sparse.inv(source))
    determinant = dn.det(matrix)
    reference = sparse.det(source)
    assert determinant.real == pytest.approx(reference.real)

    for direction in (1, 2, 4, [1, 2], [[2, 2]]):

        assert determinant.get_im(direction) == pytest.approx(reference.get_im(direction))

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_linear_algebra_larger_than_three_and_singular():
    """
    Check n = 5 AoS linear algebra (no global order needed) and the singular real part error.
    """
    n = 5
    rng = np.random.default_rng(3)
    rows = [[float(rng.uniform(-0.5, 0.5)) + (n if i == j else 0.0)
             + 0.05 * sparse.e(1 + (i + j) % 3, order=2) for j in range(n)] for i in range(n)]
    source = sparse.array(rows, order=2)
    matrix = dn.arro.from_sparse(source)

    _same(dn.inv(matrix), sparse.inv(source))
    assert dn.det(matrix).real == pytest.approx(sparse.det(source).real, rel=1e-12)

    singular = dn.arro.from_real(np.zeros((3, 3))) if hasattr(dn.arro, "from_real") else (
        dn.arro.zeros((3, 3), order=1))

    with pytest.raises(np.linalg.LinAlgError):

        dn.inv(singular)

    # end with

    with pytest.raises(np.linalg.LinAlgError):

        dn.det(singular)

    # end with

    with pytest.raises(np.linalg.LinAlgError):

        dn.solve(singular, dn.arro.zeros((3, 1), order=1))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_invalid_requests_raise_python_exceptions():
    """
    Check the validation of the AoS constructors and the shape errors of its operations.
    """
    with pytest.raises(ValueError):

        dn.arro.zeros((2, 2), order=151)

    # end with

    with pytest.raises(ValueError):

        dn.arro.zeros((2, -2))

    # end with

    assert dn.arro.zeros((2, 2), order=150)[0, 0].order == 150

    left = dn.arro.zeros((2, 3), order=1)
    right = dn.arro.zeros((2, 3), order=1)

    with pytest.raises(ValueError):

        _ = left @ right

    # end with

    with pytest.raises(ValueError):

        _ = left + dn.arro.zeros((3, 2), order=1)

    # end with

    with pytest.raises(ValueError):

        dn.inv(left)

    # end with

    with pytest.raises(ValueError):

        dn.det(left)

    # end with

    with pytest.raises(IndexError):

        _ = left[2, 0]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_add_and_list_repr_like_matso():
    """
    Provide ``add`` and ``list_repr`` like ``pyoti.sparse.matso``.
    """

    left = dn.omat.from_real(np.eye(2), order=1).to_aos()
    right = dn.omat.from_real(2.0 * np.ones((2, 2)), order=1).to_aos()
    holder = dn.arro.zeros((2, 2), order=1)

    assert np.array_equal(dn.arro.add(left, right).real, left.real + right.real)
    assert dn.arro.add(left, right, out=holder) is None
    assert np.array_equal(holder.real, left.real + right.real)
    assert left.list_repr().startswith("arro< shape: (2, 2)")

# end function
# --------------------------------------------------------------------------------------------------------
