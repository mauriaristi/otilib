"""
Check the dense OTI sparse matrices (``pyoti.dense.lil_matrix`` / ``csr_matrix`` / sparse
``solve``) against the ``pyoti.sparse`` oracle and the dense (SoA) solver.

Port of test_semisparse_csr.py. A dense value is dense over the bases 1..nact, so the semi-sparse
"interleaved" sets give a larger nact, the active bases are [1, ..., nact], and every comparison runs
over every direction of the bases 1..max(bases).
"""

from importlib import metadata
from importlib.metadata import PackageNotFoundError
from itertools import combinations_with_replacement

import numpy as np
import pytest
import scipy.sparse as scipy_sparse

import pyoti.dense as dn
import pyoti.sparse as sp


SETS = [
    ("same", (1, 2, 3), (1, 2, 3)),
    ("leading", (1, 2), (1, 2, 3, 4)),
    ("interleaved", (1, 3, 5), (2, 4, 6)),
]

ORDERS = [1, 2, 3, 4, 5]

SOLVERS = ["SuperLU", "spilu", "cholesky", "umfpack"]


# ********************************************************************************************************
def _directions(bases, order):
    """
    Enumerate the real part and every direction over the bases 1..max(bases) through an order.

    Parameters
    ----------
    bases : tuple of int
        Basis labels.
    order : int
        Highest order.

    Returns
    -------
    list of list of int
        Directions; ``[]`` is the real part.
    """

    directions = [[]]
    dense_bases = tuple(range(1, max(bases) + 1)) if len(bases) > 0 else ()

    for degree in range(1, order + 1):

        directions.extend(list(d) for d in combinations_with_replacement(dense_bases, degree))

    # end for

    return directions

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sparse_scalar(rng, real, bases, order):
    """
    Build a sparse OTI scalar with random coefficients in every direction over some bases.

    Parameters
    ----------
    rng : numpy.random.Generator
        Random source.
    real : float
        Real part.
    bases : tuple of int
        Basis labels.
    order : int
        Truncation order.

    Returns
    -------
    sotinum
        Scalar.
    """

    value = sp.zero(order=order) + real

    for direction in _directions(bases, order)[1:]:

        value = value + (rng.random() - 0.5) * sp.e(direction, order=order)

    # end for

    return value

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _positions(n):
    """
    List the stored positions of the test matrices: a band of width one plus two corners.

    Parameters
    ----------
    n : int
        Matrix size.

    Returns
    -------
    list of tuple of int
        (row, column) pairs, in a scrambled order.
    """

    positions = [(i, j) for i in range(n) for j in range(max(0, i - 1), min(n, i + 2))]
    positions += [(0, n - 1), (n - 1, 0)]
    order = np.random.default_rng(7).permutation(len(positions))
    return [positions[k] for k in order]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _system(bases, order, n=8, seed=1):
    """
    Build the same OTI sparse matrix as sparse and dense builders.

    The real part is diagonally dominant; the diagonal of even rows is real only, so the elements'
    active sets differ, and every element is assembled in two halves (``K[i, j] = K[i, j] + v``).

    Parameters
    ----------
    bases : tuple of int
        Basis labels of the imaginary parts.
    order : int
        Truncation order.
    n : int
        Matrix size.
    seed : int
        Random seed.

    Returns
    -------
    tuple
        (sparse lil_matrix, dense lil_matrix).
    """

    rng = np.random.default_rng(seed)
    sparse_lil = sp.lil_matrix((n, n))
    dense_lil = dn.lil_matrix((n, n))

    for i, j in _positions(n):

        real = 8.0 + rng.random() if i == j else rng.random() - 0.5

        if i == j and i % 2 == 0:

            sparse_lil[i, j] = real
            dense_lil[i, j] = real
            continue

        # end if

        for part in (0.4, 0.6):

            value = _sparse_scalar(rng, part * real, bases, order)
            sparse_lil[i, j] = sparse_lil[i, j] + value
            dense_lil[i, j] = dense_lil[i, j] + dn.otinum(value)

        # end for

    # end for

    return sparse_lil, dense_lil

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _rhs(bases, order, n=8, ncols=2, seed=2):
    """
    Build a dense OTI right-hand side as a sparse matso and a dense omat.

    Parameters
    ----------
    bases : tuple of int
        Basis labels.
    order : int
        Truncation order.
    n : int
        Rows.
    ncols : int
        Columns.
    seed : int
        Random seed.

    Returns
    -------
    tuple
        (matso, omat) with the same values.
    """

    rng = np.random.default_rng(seed)
    rhs = sp.zeros((n, ncols), order=order)

    for i in range(n):

        for j in range(ncols):

            rhs[i, j] = _sparse_scalar(rng, rng.random() + 0.5, bases, order)

        # end for

    # end for

    return rhs, dn.omat.from_sparse(rhs)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _max_rel_diff(actual, expected, bases, order):
    """
    Largest coefficient difference over every direction, relative to the largest expected value.

    Parameters
    ----------
    actual : omat
        Result under test.
    expected : matso or omat
        Oracle.
    bases : tuple of int
        Basis labels to compare (the union of the operands').
    order : int
        Highest order to compare.

    Returns
    -------
    float
        max |actual - expected| / max(1, max |expected|).
    """

    diff = 0.0
    scale = 0.0

    for direction in _directions(bases, order):

        got = np.asarray(actual.get_im(direction), dtype=np.float64)
        want = np.asarray(expected.get_im(direction), dtype=np.float64)
        diff = max(diff, float(np.abs(got - want).max(initial=0.0)))
        scale = max(scale, float(np.abs(want).max(initial=0.0)))

    # end for

    return diff / max(1.0, scale)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _skip_missing_solver(solver):
    """
    Skip a test whose optional solver backend is missing or has an unsupported API.

    Parameters
    ----------
    solver : str
        Solver name.
    """

    if solver == "cholesky":

        try:

            version = metadata.version("scikit-sparse")

        except PackageNotFoundError:

            pytest.skip("scikit-sparse is not installed")

        # end try

        if tuple(int(part) for part in version.split(".")[:2]) >= (0, 5):

            pytest.skip("solve assumes the scikit-sparse 0.4 callable Factor API; found " + version)

        # end if

    elif solver == "umfpack":

        pytest.importorskip("scikits.umfpack", reason="scikit-umfpack is not installed")

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_lil_get_set_semantics_match_sparse():
    """
    Setting overwrites, a missing element reads as a real zero, explicit zeros are stored.
    """

    order = 2
    sparse_lil = sp.lil_matrix((3, 4))
    dense_lil = dn.lil_matrix((3, 4))
    first = 1.0 + sp.e(1, order=order)
    second = 2.0 + 0.5 * sp.e([2, 3], order=order)

    for lil, cast in ((sparse_lil, lambda v: v), (dense_lil, dn.otinum)):

        lil[0, 2] = cast(first)
        lil[0, 2] = cast(second)
        lil[1, 1] = 4.0
        lil[2, 0] = 0.0
        lil[2, 3] = lil[2, 3] + cast(first)
        lil[2, 3] = lil[2, 3] + cast(first)

    # end for

    assert dense_lil.shape == sparse_lil.shape == (3, 4)
    assert dense_lil.nnz == sparse_lil.nnz == 4
    assert dense_lil.order == sparse_lil.order == order
    assert repr(dense_lil) == repr(sparse_lil)
    assert dense_lil[0, 2].get_im([2, 3]) == pytest.approx(0.5)
    assert dense_lil[0, 2].get_im(1) == 0.0
    assert dense_lil[2, 3].get_im(1) == pytest.approx(2.0)
    assert dense_lil[2, 3].real == pytest.approx(2.0)

    missing = dense_lil[1, 2]
    assert isinstance(missing, dn.otinum)
    assert missing.real == 0.0 and missing.order == sparse_lil[1, 2].order == 0

    # A read is a copy.
    value = dense_lil[1, 1]
    value += 1.0
    assert dense_lil[1, 1].real == 4.0

    np.testing.assert_array_equal(dense_lil.real.toarray(), sparse_lil.real.toarray())
    assert [list(row) for row in dense_lil.rows] == [list(row) for row in sparse_lil.rows]

    for dense_row, sparse_row in zip(dense_lil.data, sparse_lil.data):

        for dense_value, sparse_value in zip(dense_row, sparse_row):

            assert dn.otinum(sparse_value).get_im([2, 3]) == dense_value.get_im([2, 3])
            assert dn.otinum(sparse_value).real == dense_value.real

        # end for

    # end for

    assert dense_lil.get_active_bases() == sparse_lil.get_active_bases() == [1, 2, 3]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_lil_index_errors_and_copy():
    """
    Bad keys raise IndexError or TypeError; copies are independent; ``add`` accumulates.
    """

    lil = dn.lil_matrix((2, 2))

    for key in ((2, 0), (0, 2), (-1, 0), (0,), 1):

        with pytest.raises(IndexError):

            lil[key] = 1.0

        # end with

        with pytest.raises(IndexError):

            lil[key]

        # end with

    # end for

    with pytest.raises(TypeError):

        lil[0, 0] = "one"

    # end with

    with pytest.raises(ValueError):

        dn.lil_matrix(3)

    # end with

    lil[np.int64(1), np.int32(0)] = dn.e(1, order=1)
    lil.add(1, 0, 2.0)
    lil.add(0, 1, dn.e(2, order=1))
    assert lil[1, 0].real == 2.0 and lil[1, 0].get_im(1) == 1.0
    assert lil[0, 1].get_im(2) == 1.0

    duplicate = lil.copy()
    duplicate[1, 0] = 5.0
    assert lil[1, 0].real == 2.0 and duplicate[1, 0].real == 5.0 and duplicate.nnz == 2

    zeros = lil.zeros_like()
    assert zeros.nnz == 2 and zeros[1, 0].real == 0.0 and zeros.order == 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("module", [sp, dn], ids=["sparse", "dense"])
def test_lil_add_block_matches_elementwise_scatter(module):
    """
    ``add_block`` gives the loops of ``K[i, j] = K[i, j] + block[a, b]`` in both algebras.

    The blocks differ in shape and active set, overlap each other and stored elements (a real one and
    one over another basis), and one repeats a row and a column. A failed call changes nothing.
    """

    rng = np.random.default_rng(11)
    order = 2
    bases = (1, 2, 3, 4)
    cast = (lambda v: v) if module is sp else dn.otinum
    blocked = module.lil_matrix((6, 6))
    looped = module.lil_matrix((6, 6))

    for lil in (blocked, looped):

        lil[3, 3] = 7.0
        lil[0, 5] = cast(sp.e(3, order=order))

    # end for

    for block_bases, rows, cols in (((1, 2), [0, 3, 5], [0, 3, 5]), ((2, 4), [3, 1], [5, 3, 0, 2]),
                                    ((1,), [2, 2], [4, 4])):

        values = [[_sparse_scalar(rng, rng.random(), block_bases, order) for _ in cols] for _ in rows]
        blocked.add_block(np.array(rows), cols, sp.array(values))

        for a, i in enumerate(rows):

            for b, j in enumerate(cols):

                looped[i, j] = looped[i, j] + cast(values[a][b])

            # end for

        # end for

    # end for

    assert blocked.nnz == looped.nnz == 15
    assert [list(row) for row in blocked.rows] == [list(row) for row in looped.rows]

    # Semi-sparse adds a block column by column, so a repeated position sums in another order.
    actual = dn.csr_matrix(blocked, preserve_in=True).toarray()
    expected = dn.csr_matrix(looped, preserve_in=True).toarray()
    assert _max_rel_diff(actual, expected, bases, order) < 1e-15
    before = blocked[0, 0]

    for rows, cols, block in (([0, 6], [0], sp.zeros((2, 1))), ([-1], [0], sp.zeros((1, 1)))):

        with pytest.raises(IndexError):

            blocked.add_block(rows, cols, block + 1.0)

        # end with

    # end for

    with pytest.raises(ValueError):

        blocked.add_block([0, 1], [0], sp.zeros((1, 2)) + 1.0)

    # end with

    assert blocked.nnz == 15 and blocked[0, 0].real == before.real

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name, kbases, bbases", SETS)
@pytest.mark.parametrize("order", [1, 3])
def test_tocsr_matches_sparse(name, kbases, bbases, order):
    """
    ``tocsr`` gives sparse's pattern and values, over the union of the elements' sets.

    Parameters
    ----------
    name : str
        Set scenario.
    kbases : tuple of int
        Matrix bases.
    bbases : tuple of int
        Unused (right-hand-side bases of the scenario).
    order : int
        Truncation order.
    """

    sparse_lil, dense_lil = _system(kbases, order)
    dense_copy = dense_lil.copy()
    sparse_csr = sparse_lil.tocsr()
    dense_csr = dense_lil.tocsr()

    # As pyoti.sparse: tocsr empties the builder unless asked not to.
    assert dense_lil.nnz == 0 and sparse_lil.nnz == 0
    kept = dense_copy.tocsr(preserve_in=True)
    assert dense_copy.nnz == kept.nnz == dense_csr.nnz

    assert dense_csr.shape == sparse_csr.shape
    assert dense_csr.nnz == sparse_csr.nnz
    assert dense_csr.order == sparse_csr.order == order
    assert list(dense_csr.active_bases) == list(range(1, max(kbases) + 1))
    np.testing.assert_array_equal(dense_csr.indices, sparse_csr.indices)
    np.testing.assert_array_equal(dense_csr.indptr, sparse_csr.indptr)
    assert _max_rel_diff(dense_csr.data, sparse_csr.data, kbases, order) == 0.0
    assert _max_rel_diff(dense_csr.toarray(), sparse_csr.toarray(), kbases, order) == 0.0
    np.testing.assert_array_equal(dense_csr.real.toarray(), sparse_csr.real.toarray())
    assert repr(dense_csr) == repr(sparse_csr)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_real_part_is_shared():
    """
    ``real`` is a SciPy CSR matrix over the real block, without a copy; the pattern is read-only.
    """

    _, dense_lil = _system((1, 2), 2, n=5)
    K = dense_lil.tocsr()
    real = K.real

    assert isinstance(real, scipy_sparse.csr_matrix)
    assert np.shares_memory(real.data, K.real.data)
    assert real.indices is K.indices and real.indptr is K.indptr
    assert not K.indices.flags.writeable and not K.indptr.flags.writeable

    real.data[0] = 123.0
    assert K.toarray().real[0, int(K.indices[0])] == 123.0
    np.testing.assert_array_equal((real @ np.ones(5)), K.real.toarray() @ np.ones(5))

    with pytest.raises(ValueError):

        K.indices[0] = 1

    # end with

    # The SciPy matrix keeps the OTI matrix alive.
    del K
    assert real.data[0] == 123.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_conversions():
    """
    Round trips through pyoti.sparse and SciPy, the (data, indices, indptr) and empty creators.
    """

    order = 2
    sparse_lil, dense_lil = _system((1, 3), order, n=6)
    sparse_csr = sparse_lil.tocsr()
    dense_csr = dense_lil.tocsr()
    bases = (1, 3)

    from_sparse = dn.csr_matrix(sparse_csr)
    assert _max_rel_diff(from_sparse.toarray(), sparse_csr.toarray(), bases, order) == 0.0
    np.testing.assert_array_equal(from_sparse.indptr, sparse_csr.indptr)

    back = dense_csr.to_sparse()
    assert isinstance(back, sp.csr_matrix)
    assert _max_rel_diff(dense_csr.toarray(), back.toarray(), bases, order) == 0.0

    real = scipy_sparse.random(5, 4, density=0.5, random_state=3, format="csr")
    from_scipy = dn.csr_matrix(real)
    assert from_scipy.order == 0 and from_scipy.shape == (5, 4)
    np.testing.assert_array_equal(from_scipy.real.toarray(), real.toarray())
    np.testing.assert_array_equal(dn.csr_matrix(real.tocoo()).real.toarray(), real.toarray())

    triple = dn.csr_matrix((dense_csr.data, dense_csr.indices, dense_csr.indptr))
    assert _max_rel_diff(triple.toarray(), dense_csr.toarray(), bases, order) == 0.0

    listed = dn.csr_matrix(([1.0, dn.e(2, order=1), 3.0], [0, 2, 1], [0, 2, 3]), shape=(2, 3))
    assert listed.shape == (2, 3) and listed.nnz == 3
    assert listed.toarray().get_im(2)[0, 2] == 1.0 and listed.toarray().real[1, 1] == 3.0

    lil_back = dense_csr.tolil()
    assert lil_back.nnz == dense_csr.nnz
    assert _max_rel_diff(lil_back.tocsr().toarray(), dense_csr.toarray(), bases, order) == 0.0

    empty = dn.csr_matrix((3, 2))
    assert empty.shape == (3, 2) and empty.nnz == 0
    assert dn.csr_matrix((np.int64(3), np.int32(2))).shape == (3, 2)
    assert np.asarray(empty.toarray().real).shape == (3, 2)
    assert (empty @ dn.omat.from_real(np.ones((2, 1)))).shape == (3, 1)

    copied = dense_csr.copy()
    copied.real.data[:] = 0.0
    assert dense_csr.real.data.any()

    with pytest.raises(ValueError):

        dn.csr_matrix(([1.0, 2.0], [0, 5], [0, 1, 2]), shape=(2, 3))

    # end with

    with pytest.raises(ValueError):

        dn.csr_matrix(([1.0, 2.0], [0, 1], [0, 2, 1]), shape=(2, 3))

    # end with

    with pytest.raises(ValueError):

        dn.csr_matrix(([1.0], [0, 1], [0, 1, 2]), shape=(2, 3))

    # end with

    with pytest.raises(ValueError):

        dn.csr_matrix("matrix")

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name, kbases, xbases", SETS)
@pytest.mark.parametrize("order", ORDERS)
def test_matmul_matches_sparse(name, kbases, xbases, order):
    """
    CSR times a dense array agrees with sparse ``dot`` to 1e-13 relative.

    Parameters
    ----------
    name : str
        Set scenario.
    kbases : tuple of int
        Matrix bases.
    xbases : tuple of int
        Array bases.
    order : int
        Truncation order.
    """

    sparse_lil, dense_lil = _system(kbases, order)
    sparse_csr = sparse_lil.tocsr()
    dense_csr = dense_lil.tocsr()
    sparse_x, dense_x = _rhs(xbases, order, ncols=3)
    union = tuple(sorted(set(kbases) | set(xbases)))

    expected = sp.dot(sparse_csr, sparse_x)
    product = dense_csr @ dense_x
    assert list(product.active_bases) == list(range(1, max(union) + 1))
    assert _max_rel_diff(product, expected, union, order) < 1e-13
    assert _max_rel_diff(dn.dot(dense_csr, dense_x), expected, union, order) < 1e-13
    assert _max_rel_diff(dense_csr.dot(sparse_x), expected, union, order) < 1e-13
    assert _max_rel_diff(dn.matmul(dense_csr, dense_x), expected, union, order) < 1e-13

    holder = dn.zeros((8, 3))
    assert dense_csr.dot(dense_x, out=holder) is None
    assert _max_rel_diff(holder, expected, union, order) < 1e-13

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name, kbases, bbases", SETS)
@pytest.mark.parametrize("order", ORDERS)
def test_solve_matches_sparse_and_dense(name, kbases, bbases, order):
    """
    The CSR block solve agrees with sparse ``solve`` and the dense SoA solve to 1e-12.

    Parameters
    ----------
    name : str
        Set scenario.
    kbases : tuple of int
        Matrix bases.
    bbases : tuple of int
        Right-hand-side bases.
    order : int
        Truncation order.
    """

    sparse_lil, dense_lil = _system(kbases, order)
    sparse_csr = sparse_lil.tocsr()
    dense_csr = dense_lil.tocsr()
    sparse_b, dense_b = _rhs(bbases, order)
    union = tuple(sorted(set(kbases) | set(bbases)))

    solution = dn.solve(dense_csr, dense_b, solver="SuperLU")
    assert isinstance(solution, dn.omat)
    assert list(solution.active_bases) == list(range(1, max(union) + 1)) and solution.order == order
    assert _max_rel_diff(solution, sp.solve(sparse_csr, sparse_b), union, order) < 1e-12
    assert _max_rel_diff(solution, dn.solve(dense_csr.toarray(), dense_b), union, order) < 1e-12

    residual = dense_csr @ solution - dense_b
    assert _max_rel_diff(residual, dn.zeros((8, 2)), union, order) < 1e-12

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("solver", SOLVERS)
@pytest.mark.parametrize("name, kbases, bbases", SETS)
def test_solve_solvers_match_sparse(solver, name, kbases, bbases):
    """
    Every real solver gives sparse's solution with the same solver.

    Parameters
    ----------
    solver : str
        Real solver.
    name : str
        Set scenario.
    kbases : tuple of int
        Matrix bases.
    bbases : tuple of int
        Right-hand-side bases.
    """

    _skip_missing_solver(solver)

    order = 3
    sparse_lil, dense_lil = _system(kbases, order)
    sparse_csr = sparse_lil.tocsr()
    dense_csr = dense_lil.tocsr()
    sparse_b, dense_b = _rhs(bbases, order)
    union = tuple(sorted(set(kbases) | set(bbases)))

    expected = sp.solve(sparse_csr, sparse_b, solver=solver)
    solution = dn.solve(dense_csr, dense_b, solver=solver)
    assert _max_rel_diff(solution, expected, union, order) < 1e-12

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_solve_symmetric_cholesky_and_out():
    """
    A symmetric positive-definite system solves with every solver; ``out`` receives the solution.
    """

    order = 2
    n = 6
    rng = np.random.default_rng(5)
    lil = dn.lil_matrix((n, n))

    for i in range(n):

        lil[i, i] = 4.0 + dn.e(1, order=order)

        if i + 1 < n:

            value = -1.0 + 0.1 * rng.random() * dn.e([1, 2], order=order)
            lil[i, i + 1] = value
            lil[i + 1, i] = value

        # end if

    # end for

    K = lil.tocsr()
    b = dn.omat.from_real(np.arange(1.0, n + 1.0).reshape(-1, 1), order=order)
    expected = dn.solve(K.toarray(), b)

    for solver in SOLVERS:

        if solver == "cholesky":

            try:

                _skip_missing_solver(solver)

            except pytest.skip.Exception:

                continue

            # end try

        elif solver == "umfpack":

            try:

                import scikits.umfpack  # noqa: F401

            except ImportError:

                continue

            # end try

        # end if

        holder = dn.zeros((n, 1))
        assert dn.solve(K, b, out=holder, solver=solver) is None
        assert _max_rel_diff(holder, expected, (1, 2), order) < 1e-12

    # end for

    # A real right-hand side and a one-dimensional NumPy vector are accepted.
    vector = dn.solve(K, np.arange(1.0, n + 1.0))
    assert _max_rel_diff(vector, expected, (1, 2), order) < 1e-12

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_arithmetic_and_extraction_match_sparse():
    """
    Negation, sums, scaling, powers and the derivative extractors agree with sparse.
    """

    order = 3
    bases = (1, 2)
    sparse_lil, dense_lil = _system(bases, order, n=5)
    sparse_csr = sparse_lil.tocsr()
    dense_csr = dense_lil.tocsr()
    other_sparse = sp.lil_matrix((5, 5))
    other_semi = dn.lil_matrix((5, 5))

    for i, j in ((0, 3), (2, 2), (4, 1)):

        value = (i + 1.0) + 0.5 * sp.e([1, 3], order=order)
        other_sparse[i, j] = value
        other_semi[i, j] = dn.otinum(value)

    # end for

    other_sparse = other_sparse.tocsr()
    other_semi = other_semi.tocsr()
    union = (1, 2, 3)
    scalar = 2.0 + sp.e(3, order=order)

    pairs = [
        (-dense_csr, -sparse_csr),
        (dense_csr + other_semi, sparse_csr + other_sparse),
        (dense_csr - other_semi, sparse_csr - other_sparse),
        (dense_csr + dense_csr, sparse_csr + sparse_csr),
        (2.5 * dense_csr, 2.5 * sparse_csr),
        (dense_csr * dn.otinum(scalar), sparse_csr * scalar),
        (dense_csr * scalar, sparse_csr * scalar),
        (dense_csr ** 2, sparse_csr ** 2),
        (dense_csr.extract_im(1), sparse_csr.extract_im(1)),
        (dense_csr.extract_deriv([1, 2]), sparse_csr.extract_deriv([1, 2])),
        (dense_csr.get_order_im(2), sparse_csr.get_order_im(2)),
        (dense_csr.truncate(1), sparse_csr.truncate(1)),
    ]

    for actual, expected in pairs:

        np.testing.assert_array_equal(actual.indptr, expected.indptr)
        np.testing.assert_array_equal(actual.indices, expected.indices)
        assert _max_rel_diff(actual.toarray(), expected.toarray(), union, order) < 1e-13

    # end for

    quotient = dense_csr / 4.0
    assert _max_rel_diff(quotient.toarray(), (0.25 * sparse_csr).toarray(), union, order) < 1e-15

    for direction in ([1], [1, 2], [2, 2, 1]):

        np.testing.assert_allclose(dense_csr.get_deriv(direction).real.toarray(),
                                   sparse_csr.get_deriv(direction).real.toarray(), rtol=1e-13)
        np.testing.assert_allclose(dense_csr.get_im(direction).real.toarray(),
                                   sparse_csr.get_im(direction).real.toarray(), rtol=1e-13)

    # end for

    assert dense_csr.get_active_bases() == list(range(1, max(sparse_csr.get_active_bases()) + 1))
    assert str(dense_csr).count("\n") == dense_csr.nnz

    with pytest.raises(ValueError):

        dense_csr + dn.csr_matrix((4, 4))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_solve_and_matmul_errors():
    """
    Shape mismatches, a rectangular matrix and an unknown solver raise.
    """

    _, dense_lil = _system((1, 2), 1, n=4)
    K = dense_lil.tocsr()
    rectangular = dn.csr_matrix(([1.0, 2.0], [0, 2], [0, 1, 2]), shape=(2, 3))

    with pytest.raises(ValueError):

        dn.solve(K, dn.zeros((3, 1)))

    # end with

    with pytest.raises(ValueError):

        dn.solve(rectangular, dn.zeros((2, 1)))

    # end with

    with pytest.raises(ValueError):

        dn.solve(K, dn.zeros((4, 1)), solver="gauss")

    # end with

    with pytest.raises(ValueError):

        K @ dn.zeros((3, 1))

    # end with

    with pytest.raises(TypeError):

        K @ "x"

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_failed_reinit_leaves_the_matrix_unchanged():
    """
    A failing ``__init__`` on a live matrix leaves it unchanged, and products stay in bounds.
    """

    K = dn.csr_matrix(([1.0, 2.0], [0, 1], [0, 1, 2]), shape=(2, 2))
    before = K.toarray().real.copy()

    with pytest.raises(ValueError):

        K.__init__(([1.0, 2.0], [0, 1, 2, 3], [0, 1, 2, 3, 4]), shape=(4, 10))

    # end with

    with pytest.raises(ValueError):

        K.__init__(([1.0, 2.0], [0, 5], [0, 1, 2]), shape=(2, 3))

    # end with

    assert K.shape == (2, 2) and K.nnz == 2
    np.testing.assert_array_equal(K.toarray().real, before)
    np.testing.assert_array_equal((K @ dn.omat.from_real(np.ones((2, 1)))).real, [[1.0], [2.0]])

    lil = dn.lil_matrix((2, 2))
    lil[0, 0] = 1.0

    with pytest.raises(ValueError):

        dn.csr_matrix(([1.0], [0], [0, 1]), shape=(3, 3))

    # end with

    K.__init__(lil)
    assert K.shape == (2, 2) and K.nnz == 1 and lil.nnz == 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_shape_validation_and_python_int_sizes():
    """
    Shapes too large for int64 indices are rejected at construction; sizes are Python integers.
    """

    for shape in ((2**64 - 1, 1), (2**63, 1), (1, 2**63), (-1, 2)):

        with pytest.raises(ValueError):

            dn.lil_matrix(shape)

        # end with

    # end for

    with pytest.raises(ValueError):

        dn.csr_matrix((2**63, 2))

    # end with

    with pytest.raises(TypeError):

        dn.lil_matrix((2.5, 2))

    # end with

    assert dn.lil_matrix((2**40, 2**40)).size == 2**80
    assert dn.lil_matrix((3, 4)).tocsr().shape == (3, 4)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_index_arrays_are_immutable_and_copies_are_independent():
    """
    The pattern cannot be made writeable, and ``copy.copy`` / ``deepcopy`` copy the values.
    """

    import copy

    _, dense_lil = _system((1, 2), 2, n=4)
    K = dense_lil.tocsr()

    for array in (K.indices, K.indptr):

        with pytest.raises(ValueError):

            array.flags.writeable = True

        # end with

    # end for

    for clone in (copy.copy(K), copy.deepcopy(K)):

        assert isinstance(clone, dn.csr_matrix) and clone.nnz == K.nnz
        clone.real.data[0] = 42.0
        assert K.real.data[0] != 42.0

    # end for

    _, builder = _system((1, 2), 2, n=4)
    clone = copy.copy(builder)
    clone[0, 0] = 99.0
    assert builder[0, 0].real != 99.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_duplicates_add_up_in_tolil():
    """
    ``tolil`` sums duplicate entries, like ``toarray``, ``@`` and ``solve``.
    """

    K = dn.csr_matrix(([1.0, 2.0 + dn.e(1, order=1)], [0, 0], [0, 2]), shape=(1, 2))
    lil = K.tolil()

    assert lil[0, 0].real == 3.0 and lil[0, 0].get_im(1) == 1.0
    np.testing.assert_array_equal(lil.tocsr().toarray().real, K.toarray().real)
    np.testing.assert_array_equal((K @ dn.omat.from_real(np.ones((2, 1)))).real, [[3.0]])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_nested_lists_of_oti_scalars_as_operands():
    """
    Nested lists holding OTI scalars are accepted by add_block, ``@`` and solve, like pyoti.sparse.
    """

    value = 1.0 + dn.e(1, order=1)
    lil = dn.lil_matrix((2, 2))
    sparse_lil = sp.lil_matrix((2, 2))
    lil.add_block([0, 1], [0, 1], [[value, 0.5], [0.5, value]])
    sparse_lil[0, 0] = value.to_sparse()
    sparse_lil[0, 1] = 0.5
    sparse_lil[1, 0] = 0.5
    sparse_lil[1, 1] = value.to_sparse()
    K = lil.tocsr()
    sparse_K = sparse_lil.tocsr()

    product = K @ [[value], [2.0]]
    expected = K @ dn.array([[value], [2.0]])
    assert _max_rel_diff(product, expected, (1,), 1) == 0.0
    assert _max_rel_diff(K.toarray(), sparse_K.toarray(), (1,), 1) == 0.0

    solution = dn.solve(K, [[value], [1.0]])
    assert _max_rel_diff(solution, dn.solve(K.toarray(), dn.array([[value], [1.0]])), (1,), 1) < 1e-13

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("korder, border", [(1, 4), (5, 2)])
def test_solve_with_mixed_truncation_orders(korder, border):
    """
    K and b of different truncation orders: the CSR solve matches the dense SoA solve and its
    residual is zero (the sparse oracle truncates per element, so it cannot be used here).

    Parameters
    ----------
    korder : int
        Truncation order of the matrix.
    border : int
        Truncation order of the right-hand side.
    """

    _, dense_lil = _system((1, 2), korder)
    _, b = _rhs((2, 3), border)
    K = dense_lil.tocsr()
    order = max(korder, border)

    solution = dn.solve(K, b)
    assert solution.order == order
    assert _max_rel_diff(solution, dn.solve(K.toarray(), b), (1, 2, 3), order) < 1e-12
    assert _max_rel_diff(K @ solution - b, dn.zeros((8, 2)), (1, 2, 3), order) < 1e-12

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_solve_beyond_the_global_table_matches_semisparse():
    """
    Base 11 at order 5 (beyond Nbasis(5) = 10): the CSR solve and product equal semi-sparse.
    """

    import pyoti.semisparse as ss

    order = 5
    n = 5
    lils = [dn.lil_matrix((n, n)), ss.lil_matrix((n, n))]

    for module, lil in zip((dn, ss), lils):

        for i in range(n):

            lil[i, i] = 4.0 + 0.1 * module.e(11, order=order) + 0.05 * i * module.e([1, 3], order=order)

            if i + 1 < n:

                lil[i, i + 1] = -1.0 + 0.02 * module.e(2, order=order)
                lil[i + 1, i] = -1.0

            # end if

        # end for

    # end for

    b = dn.zeros((n, 1), order=order)
    semi_b = ss.zeros((n, 1), order=order)

    for i in range(n):

        b[i, 0] = 1.0 + i * dn.e(11, order=order)
        semi_b[i, 0] = 1.0 + i * ss.e(11, order=order)

    # end for

    K, semi_K = lils[0].tocsr(), lils[1].tocsr()
    pairs = [(dn.solve(K, b), ss.solve(semi_K, semi_b)), (K @ b, semi_K @ semi_b)]

    for actual, expected in pairs:

        assert actual.nact == 11

        for direction in ([], [11], [11, 11], [1, 3, 11], [2, 11, 11, 11, 11], [7]):

            np.testing.assert_allclose(actual.get_im(direction), expected.get_im(direction),
                                       rtol=1e-12, atol=1e-13)

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_real_part_outlives_the_matrix_and_sparse_lil_is_emptied():
    """
    ``K.real`` stays valid after K is deleted, and a sparse lil_matrix source is emptied unless
    ``preserve_in``.
    """

    import gc

    _, dense_lil = _system((1, 2), 2, n=5)
    K = dense_lil.tocsr()
    expected = K.real.toarray()
    real = K.real
    del K, dense_lil
    gc.collect()
    _ = [np.ones(100000) for _ in range(20)]
    np.testing.assert_array_equal(real.toarray(), expected)

    sparse_lil, _ = _system((1, 2), 1, n=4)
    kept = dn.csr_matrix(sparse_lil, preserve_in=True)
    assert sparse_lil.nnz == kept.nnz > 0
    emptied = dn.csr_matrix(sparse_lil)
    assert emptied.nnz == kept.nnz and sparse_lil.nnz == 0

# end function
# --------------------------------------------------------------------------------------------------------
