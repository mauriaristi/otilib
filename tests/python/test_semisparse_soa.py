"""
Compare semi-sparse SoA arrays with the sparse oracle and check block views.
"""

import gc
import weakref

import numpy as np
import pytest

import pyoti.semisparse as semi
import pyoti.sparse as sparse


# ********************************************************************************************************
def _same(actual, expected, order=2):
    """
    Compare every matrix element's real and selected imaginary coefficients.

    Parameters
    ----------
    actual : oarrss
        SoA result.
    expected : matso
        Sparse reference.
    order : int
        Highest checked order.
    """

    assert actual.shape == expected.shape

    for row in range(actual.shape[0]):

        for col in range(actual.shape[1]):

            lhs = actual[row, col]
            rhs = expected[row, col]
            assert lhs.real == pytest.approx(rhs.real, rel=1e-8, abs=1e-9)

            for direction in (1, 2, [1, 2], [[1, 2]], [[2, 2]]):

                if isinstance(direction, int) or order > 1:

                    assert lhs.get_im(direction) == pytest.approx(
                        rhs.get_im(direction), rel=1e-8, abs=1e-9)

                # end if

            # end for

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _matrix():
    """
    Build a small well-conditioned sparse matrix over two bases.

    Returns
    -------
    matso
        Sparse reference matrix.
    """

    e1 = sparse.e(1, order=2)
    e2 = sparse.e(2, order=2)
    return sparse.array([[3.0 + 0.1 * e1, 0.2 + 0.05 * e2],
                         [0.1 + 0.03 * e1, 2.5 + 0.08 * e2]])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_conversion_and_elementwise():
    """
    Compare sparse conversion, element access, and broadcast arithmetic.
    """

    source = _matrix()
    matrix = semi.oarrss.from_sparse(source)
    assert matrix.shape == (2, 2)
    assert matrix.active_bases == (1, 2)
    assert matrix.order == 2
    _same(matrix, source)
    _same(semi.oarrss.from_sparse(matrix.to_sparse()), source)
    _same(matrix + matrix, source + source)
    _same(matrix - matrix, source - source)
    _same(matrix * matrix, source * source)
    _same(matrix / matrix, source / source)
    _same(matrix * 2.0, source * 2.0)
    _same(2.0 - matrix, 2.0 - source)
    _same(matrix + semi.ssotinum(1.0), source + 1.0)
    matrix[0, 0] = semi.ssotinum(source[0, 0])
    _same(matrix, source)
    _same(matrix.truncate([1, 2]), sparse.truncate([1, 2], source))
    _same(matrix.truncate_order(2), source.truncate_order(2), order=1)
    _same(matrix.get_order_im(2), source.get_order_im(2))
    _same(matrix.compact(), source)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_real_and_block_view():
    """
    Ensure direction blocks share memory, stay Fortran-ordered, and retain the parent.
    """

    real = np.arange(6.0).reshape(2, 3)
    matrix = semi.oarrss.from_real(real, order=2)
    assert np.array_equal(matrix.get_block(0), real)
    zero = semi.zeros((2, 3), bases=[1, 2], order=2)
    zero[0, 1] = semi.ssotinum(sparse.e(1, order=2))
    view = zero.get_block(1)
    assert np.shares_memory(view, zero.get_block(semi.rawdir(0, 1)))
    assert np.array_equal(zero.get_block(semi.rawdir(0, 0)), zero.get_block(0))
    assert view.shape == (2, 3)
    assert view.flags.f_contiguous
    view[1, 2] = 0.75
    assert zero[1, 2].get_im(1) == pytest.approx(0.75)
    reference = weakref.ref(zero)
    del zero
    gc.collect()
    assert reference() is not None
    assert view[1, 2] == pytest.approx(0.75)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_math_and_matrix_operations():
    """
    Compare elementwise functions and matrix algebra to the sparse implementation.
    """

    source = _matrix()
    matrix = semi.oarrss.from_sparse(source)
    _same(matrix @ matrix, sparse.dot(source, source))
    _same(semi.dot(matrix, matrix), sparse.dot(source, source))
    _same(matrix.T, sparse.transpose(source))
    _same(semi.exp(matrix), sparse.exp(source))
    _same(semi.sin(matrix), sparse.sin(source))
    _same(semi.pow(matrix, 1.5), sparse.pow(source, 1.5))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_linear_algebra():
    """
    Compare solve, inverse, determinant, and repeated LU solves against sparse.
    """

    source = _matrix()
    rhs = sparse.array([[1.0 + sparse.e(1, order=2)], [2.0]])
    matrix = semi.oarrss.from_sparse(source)
    vector = semi.oarrss.from_sparse(rhs)
    expected = sparse.solve(source, rhs)
    _same(semi.solve(matrix, vector), expected)
    factor = semi.lu_factor(matrix)
    _same(semi.lu_solve(factor, vector), expected)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_inverse_and_determinant():
    """
    Check the inverse and determinant against sparse matrix algebra.
    """

    source = _matrix()
    matrix = semi.oarrss.from_sparse(source)
    _same(semi.inv(matrix), sparse.inv(source))
    result = semi.det(matrix)
    reference = sparse.det(source)
    assert result.real == pytest.approx(reference.real)

    for direction in (1, 2, [1, 2], [[1, 2]], [[2, 2]]):

        assert result.get_im(direction) == pytest.approx(reference.get_im(direction))

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_lu_with_uniform_rhs_order():
    """
    Compare LU and direct solve when every sparse RHS entry has order two.
    """

    source = _matrix()
    rhs = sparse.array([[1.0 + sparse.e(1, order=2)],
                        [sparse.number(2.0, nbases=2, order=2)]])
    matrix = semi.oarrss.from_sparse(source)
    vector = semi.oarrss.from_sparse(rhs)
    assert vector.order == 2
    _same(semi.solve(matrix, vector), sparse.solve(source, rhs))
    _same(semi.lu_solve(semi.lu_factor(matrix), vector), sparse.solve(source, rhs))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_input_validation_and_singular_matrix():
    """
    Raise Python exceptions for shape errors and singular real blocks.
    """

    matrix = semi.oarrss.from_real(np.eye(2), order=1)

    with pytest.raises(ValueError):

        _ = matrix @ semi.oarrss.zeros((3, 1))

    # end with

    with pytest.raises(IndexError):

        _ = matrix[2, 0]

    # end with

    with pytest.raises(np.linalg.LinAlgError):

        semi.solve(semi.oarrss.from_real(np.zeros((2, 2))), matrix)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------
