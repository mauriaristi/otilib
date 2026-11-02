"""
Compare AoS semi-sparse arrays with the public sparse matrix API.
"""

import numpy as np
import pytest

import pyoti.semisparse as semi
import pyoti.sparse as sparse


FUNCTIONS = ("sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh", "tanh",
             "asinh", "acosh", "atanh", "exp", "log", "log10", "sqrt", "cbrt", "erf")


# ********************************************************************************************************
def _same(actual, expected, order=2):
    """
    Compare real and imaginary coefficients across an AoS matrix.

    Parameters
    ----------
    actual : arrss
        Semi-sparse result.
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
    matrix = semi.arrss.from_sparse(source)
    assert matrix.shape == (2, 2)
    assert matrix.order == 2
    assert matrix[0, 0].active_bases == (1,)
    assert matrix[0, 1].active_bases == (2,)
    _same(matrix, source)
    _same(semi.arrss.from_sparse(matrix.to_sparse()), source)
    soa = matrix.to_soa()
    assert soa.active_bases == (1, 2)
    _same(soa.to_aos(), source)
    _same(semi.arrss.from_soa(soa), source)
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

    matrix = semi.arrss.zeros((2, 2), order=2)
    assert matrix.order == 2
    matrix[0, 0] = semi.ssotinum(sparse.e(1, order=2) + sparse.e(2, order=2))
    matrix[1, 1] = sparse.e(2, order=2)
    assert matrix[0, 0].active_bases == (1, 2)
    assert matrix[1, 1].active_bases == (2,)
    matrix[0, 0] = semi.ssotinum(2.0, order=2)
    assert matrix[0, 0].real == pytest.approx(2.0)
    source = _matrix()
    value = semi.arrss.from_sparse(source)
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
    matrix = semi.arrss.from_sparse(source)

    for actual, expected in ((matrix + matrix, source + source),
                             (matrix - matrix, source - source),
                             (matrix * matrix, source * source),
                             (matrix / matrix, source / source),
                             (matrix + 1.5, source + 1.5),
                             (1.5 - matrix, 1.5 - source),
                             (matrix * 1.5, source * 1.5),
                             (1.5 / matrix, 1.5 / source),
                             (matrix + semi.ssotinum(1.0), source + 1.0),
                             (matrix ** 1.5, sparse.pow(source, 1.5)),
                             (-matrix, -source),
                             (matrix @ matrix, sparse.dot(source, source)),
                             (semi.matmul(matrix, matrix), sparse.dot(source, source)),
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
    _same(getattr(semi, name)(semi.arrss.from_sparse(source)),
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
    matrix = semi.arrss.from_sparse(source)
    vector = semi.arrss.from_sparse(rhs)
    _same(semi.solve(matrix, vector), sparse.solve(source, rhs))
    _same(semi.inv(matrix), sparse.inv(source))
    determinant = semi.det(matrix)
    reference = sparse.det(source)
    assert determinant.real == pytest.approx(reference.real)
    assert determinant.get_im(1) == pytest.approx(reference.get_im(1))

    with pytest.raises(np.linalg.LinAlgError):

        semi.solve(semi.arrss.zeros((2, 2)), semi.arrss.zeros((2, 1)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------
