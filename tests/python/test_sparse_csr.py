"""
Check sparse OTI CSR assembly and solver behavior against dense sparse matrices.
"""

from importlib import metadata
from importlib.metadata import PackageNotFoundError
from itertools import combinations_with_replacement

import numpy as np
import pytest
import scipy.sparse as scipy_sparse

import pyoti.sparse as oti


# ********************************************************************************************************
def _directions(bases, order):
    """
    Enumerate every nonconstant direction through a truncation order.

    Parameters
    ----------
    bases : tuple[int, ...]
        One-based imaginary basis labels.
    order : int
        Highest direction order to include.

    Returns
    -------
    list[tuple[int, ...]]
        Directions over the requested bases.
    """
    directions = []

    for degree in range(1, order + 1):

        directions.extend(combinations_with_replacement(bases, degree))

    # end for

    return directions

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_matrix_close(actual, expected, bases, order):
    """
    Compare sparse matrices and all requested derivative matrices.

    Parameters
    ----------
    actual : matso
        Result under test.
    expected : matso
        Dense sparse oracle.
    bases : tuple[int, ...]
        Active basis labels to compare.
    order : int
        Highest derivative order to compare.
    """
    np.testing.assert_allclose(
        np.asarray(actual.real), np.asarray(expected.real), rtol=1e-13, atol=1e-13
    )

    for direction in _directions(bases, order):

        np.testing.assert_allclose(
            np.asarray(actual.get_deriv(direction).real),
            np.asarray(expected.get_deriv(direction).real),
            rtol=1e-13,
            atol=1e-13,
        )

    # end for

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _build_solver_system(order):
    """
    Build a positive-definite OTI system and its CSR representation.

    Parameters
    ----------
    order : int
        Truncation order for the matrix and right-hand side.

    Returns
    -------
    tuple
        Dense matrix, OTI CSR matrix and dense right-hand side.
    """
    bases = 3
    dense = oti.array(
        [[6.0, 1.0, 0.5], [1.0, 5.0, 0.25], [0.5, 0.25, 4.0]],
        nbases=bases,
        order=order,
    )
    dense[0, 0] += 0.1 * oti.e(1, order=order)
    dense[0, 1] += 0.05 * oti.e(2, order=order)
    dense[1, 0] += 0.05 * oti.e(2, order=order)

    if order >= 2:

        dense[1, 1] += 0.02 * oti.e([1, 2], order=order)

    # end if

    if order >= 3:

        dense[1, 2] += 0.01 * oti.e([3, 3, 3], order=order)
        dense[2, 1] += 0.01 * oti.e([3, 3, 3], order=order)

    # end if

    if order >= 4:

        dense[2, 2] += 0.01 * oti.e([1, 2, 3, 3], order=order)

    # end if

    rhs = oti.array([[1.0], [2.0], [3.0]], nbases=bases, order=order)

    for degree in range(1, order + 1):

        basis = (degree - 1) % bases + 1
        row = degree % 3
        rhs[row, 0] += 0.03 * degree * oti.e([basis] * degree, order=order)

    # end for

    lil = oti.lil_matrix(dense.shape)

    for i in range(dense.shape[0]):

        for j in range(dense.shape[1]):

            lil[i, j] = dense[i, j]

        # end for

    # end for

    return dense, lil.tocsr(), rhs

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_sparse_lil_accumulation_and_csr_properties():
    """
    Check LIL assembly, item accumulation and CSR structure against SciPy.
    """
    order = 4
    bases = (1, 2, 3)
    lil = oti.lil_matrix((3, 3))
    lil[0, 0] = 4.0
    lil[0, 2] = 1.0 + oti.e(1, order=order)
    lil[1, 1] = 5.0 + oti.e(2, order=order)
    lil[2, 0] = oti.e([1, 2], order=order)
    lil[0, 2] = lil[0, 2] + 0.25 * oti.e([2, 3], order=order)

    assert lil.shape == (3, 3)
    assert lil.nnz == 4
    assert lil.order == order
    assert float(lil[0, 2].get_deriv([2, 3])) == pytest.approx(0.25)

    expected_indices = np.array([0, 2, 1, 0], dtype=np.uint64)
    expected_indptr = np.array([0, 2, 3, 4], dtype=np.uint64)
    expected_real = scipy_sparse.csr_matrix(
        (
            np.array([4.0, 1.0, 5.0, 0.0]),
            expected_indices,
            expected_indptr,
        ),
        shape=(3, 3),
    )
    np.testing.assert_allclose(lil.real.toarray(), expected_real.toarray())

    csr = lil.tocsr()
    assert csr.shape == (3, 3)
    assert csr.nnz == 4
    assert csr.order == order
    np.testing.assert_array_equal(csr.indices, expected_indices)
    np.testing.assert_array_equal(csr.indptr, expected_indptr)
    np.testing.assert_allclose(csr.real.toarray(), expected_real.toarray())

    dense_expected = oti.zeros((3, 3), nbases=len(bases), order=order)
    dense_expected[0, 0] = 4.0
    dense_expected[0, 2] = 1.0 + oti.e(1, order=order)
    dense_expected[0, 2] += 0.25 * oti.e([2, 3], order=order)
    dense_expected[1, 1] = 5.0 + oti.e(2, order=order)
    dense_expected[2, 0] = oti.e([1, 2], order=order)
    _assert_matrix_close(csr.toarray(), dense_expected, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", [1, 2, 3, 4])
@pytest.mark.parametrize("solver", ["SuperLU", "spilu", "cholesky", "umfpack"])
def test_sparse_csr_solve_matches_dense(order, solver):
    """
    Compare sparse CSR solves with the dense sparse solver for orders one through four.

    Parameters
    ----------
    order : int
        OTI truncation order.
    solver : str
        Real sparse factorization backend.
    """
    if solver == "cholesky":

        try:

            version = metadata.version("scikit-sparse")

        except PackageNotFoundError:

            pytest.skip("scikit-sparse is not installed")

        # end try

        version_tuple = tuple(int(part) for part in version.split(".")[:2])

        if version_tuple >= (0, 5):

            pytest.skip(
                "sparse solve assumes the scikit-sparse 0.4 callable Factor API; found " + version
            )

        # end if

    # end if

    if solver == "umfpack":

        try:

            import scikits.umfpack

        except ImportError:

            pytest.skip("scikit-umfpack is not installed")

        # end try

    # end if

    dense, csr, rhs = _build_solver_system(order)
    expected = oti.solve(dense, rhs)
    actual = oti.solve(csr, rhs, solver=solver)
    _assert_matrix_close(actual, expected, (1, 2, 3), order)

# end function
# --------------------------------------------------------------------------------------------------------
