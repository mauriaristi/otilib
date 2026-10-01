"""
Compare dense SoA arrays with the sparse oracle and check block views.
"""

import gc
import weakref

import numpy as np
import pytest

import pyoti.dense as dn
import pyoti.sparse as sparse


# ********************************************************************************************************
def _same(actual, expected, order=2):
    """
    Compare every matrix element's real and selected imaginary coefficients.

    Parameters
    ----------
    actual : omat
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
    matrix = dn.omat.from_sparse(source)
    assert matrix.shape == (2, 2)
    assert matrix.active_bases == (1, 2)
    assert matrix.order == 2
    _same(matrix, source)
    _same(dn.omat.from_sparse(matrix.to_sparse()), source)
    _same(matrix + matrix, source + source)
    _same(matrix - matrix, source - source)
    _same(matrix * matrix, source * source)
    _same(matrix / matrix, source / source)
    _same(matrix * 2.0, source * 2.0)
    _same(2.0 - matrix, 2.0 - source)
    _same(matrix + dn.otinum(1.0), source + 1.0)
    matrix[0, 0] = dn.otinum(source[0, 0])
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
    matrix = dn.omat.from_real(real, order=2)
    assert np.array_equal(matrix.get_block(0), real)
    zero = dn.zeros((2, 3), bases=[1, 2], order=2)
    zero[0, 1] = dn.otinum(sparse.e(1, order=2))
    view = zero.get_block(1)
    assert np.shares_memory(view, zero.get_block(dn.rawdir(0, 1)))
    assert np.array_equal(zero.get_block(dn.rawdir(0, 0)), zero.get_block(0))
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
    matrix = dn.omat.from_sparse(source)
    _same(matrix @ matrix, sparse.dot(source, source))
    _same(dn.dot(matrix, matrix), sparse.dot(source, source))
    _same(matrix.T, sparse.transpose(source))
    _same(dn.exp(matrix), sparse.exp(source))
    _same(dn.sin(matrix), sparse.sin(source))
    _same(dn.pow(matrix, 1.5), sparse.pow(source, 1.5))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_linear_algebra():
    """
    Compare solve, inverse, determinant, and repeated LU solves against sparse.
    """

    source = _matrix()
    rhs = sparse.array([[1.0 + sparse.e(1, order=2)], [2.0]])
    matrix = dn.omat.from_sparse(source)
    vector = dn.omat.from_sparse(rhs)
    expected = sparse.solve(source, rhs)
    _same(dn.solve(matrix, vector), expected)
    factor = dn.lu_factor(matrix)
    _same(dn.lu_solve(factor, vector), expected)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_inverse_and_determinant():
    """
    Check the inverse and determinant against sparse matrix algebra.
    """

    source = _matrix()
    matrix = dn.omat.from_sparse(source)
    _same(dn.inv(matrix), sparse.inv(source))
    result = dn.det(matrix)
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
    matrix = dn.omat.from_sparse(source)
    vector = dn.omat.from_sparse(rhs)
    assert vector.order == 2
    _same(dn.solve(matrix, vector), sparse.solve(source, rhs))
    _same(dn.lu_solve(dn.lu_factor(matrix), vector), sparse.solve(source, rhs))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_input_validation_and_singular_matrix():
    """
    Raise Python exceptions for shape errors and singular real blocks.
    """

    matrix = dn.omat.from_real(np.eye(2), order=1)

    with pytest.raises(ValueError):

        _ = matrix @ dn.omat.zeros((3, 1))

    # end with

    with pytest.raises(IndexError):

        _ = matrix[2, 0]

    # end with

    with pytest.raises(np.linalg.LinAlgError):

        dn.solve(dn.omat.from_real(np.zeros((2, 2))), matrix)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _chain_matrix(n, order, seed):
    """
    Build a diagonally dominant n x n sparse matrix whose entries depend on the bases 1..3.

    Parameters
    ----------
    n : int
        Matrix size.
    order : int
        Truncation order.
    seed : int
        Random generator seed.

    Returns
    -------
    matso
        Sparse reference matrix.
    """
    rng = np.random.default_rng(seed)
    e = [sparse.e(base, order=order) for base in (1, 2, 3)]
    rows = []

    for i in range(n):

        row = []

        for j in range(n):

            value = float(rng.uniform(-0.5, 0.5)) + (n + 1.0 if i == j else 0.0)
            entry = value + 0.05 * float(rng.uniform(-1, 1)) * e[(i + j) % 3]
            entry = entry + 0.03 * float(rng.uniform(-1, 1)) * e[j % 3] * e[i % 3]
            row.append(entry)

        # end for

        rows.append(row)

    # end for

    return sparse.array(rows, order=order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("n", (1, 2, 3, 4, 5, 6, 8))
@pytest.mark.parametrize("order", (1, 2, 3))
def test_soa_linear_algebra_any_size_without_a_global_order(n, order):
    """
    Check solve, inv and det for every size, never setting a global truncation order.

    The old dense det and invert segfaulted unless the global order matched, and were wrong for
    n >= 4.

    Parameters
    ----------
    n : int
        Matrix size.
    order : int
        Truncation order.
    """
    source = _chain_matrix(n, order, 100 + n)
    rhs = sparse.array([[1.0 + 0.1 * sparse.e(1 + i % 3, order=order), 2.0] for i in range(n)],
                       order=order)
    matrix = dn.omat.from_sparse(source)
    vector = dn.omat.from_sparse(rhs)

    _same(dn.solve(matrix, vector), sparse.solve(source, rhs), order=order)
    _same(dn.inv(matrix), sparse.inv(source), order=order)
    assert dn.det(matrix).real == pytest.approx(sparse.det(source).real, rel=1e-12)

    for direction in (1, 2, 3, [1, 2], [[1, 1]]):

        assert dn.det(matrix).get_im(direction) == pytest.approx(
            sparse.det(source).get_im(direction), rel=1e-9, abs=1e-12
        )

    # end for

    identity = matrix @ dn.inv(matrix)
    assert np.allclose(identity.real, np.eye(n), atol=1e-12)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_nact_grows_and_prefix_operands_combine():
    """
    Check that the number of active bases is max(bases), grows on assignment, and that operands
    with different nact combine over the larger one.
    """
    zero = dn.omat.zeros((2, 2), bases=[3], order=2)
    assert zero.nact == 3
    assert zero.active_bases == (1, 2, 3)
    assert dn.omat.zeros((2, 2)).nact == 0

    small_source = sparse.array([[1.0 + 0.5 * sparse.e(1, order=2), 2.0],
                                 [0.5, 1.5 + 0.25 * sparse.e(2, order=2)]])
    large_source = sparse.array([[2.0, 1.0 + 0.5 * sparse.e(4, order=2)],
                                 [0.25 * sparse.e(3, order=2), 1.0]])
    small = dn.omat.from_sparse(small_source)
    large = dn.omat.from_sparse(large_source)
    assert (small.nact, large.nact) == (2, 4)

    _same(small + large, small_source + large_source)
    _same(large - small, large_source - small_source)
    _same(small * large, small_source * large_source)
    assert (small * large).nact == 4
    _same(small @ large, sparse.dot(small_source, large_source))
    _same(large @ small, sparse.dot(large_source, small_source))

    small[0, 0] = dn.e(5, order=2)
    assert small.nact == 5
    assert small[0, 0].get_im(5) == pytest.approx(1.0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_mixed_truncation_orders_use_the_larger():
    """
    Check that the result of an operation between different truncation orders has the larger one.
    """
    low_source = sparse.array([[1.0 + 0.5 * sparse.e(1, order=2), 2.0]], order=2)
    high_source = sparse.array([[2.0 + 0.5 * sparse.e(2, order=4), 1.0]], order=4)
    low = dn.omat.from_sparse(low_source)
    high = dn.omat.from_sparse(high_source)

    assert (low + high).order == 4
    assert (high * low).order == 4
    _same(low + high, low_source + high_source, order=2)
    _same(low * high, low_source * high_source, order=2)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_invalid_requests_raise_python_exceptions():
    """
    Check the order, shape and size validation of the constructors.
    """
    with pytest.raises(ValueError):

        dn.omat.zeros((2, 2), order=151)

    # end with

    with pytest.raises(ValueError):

        dn.omat.zeros((2, 2), order=-1)

    # end with

    with pytest.raises(ValueError):

        dn.omat.zeros((2, -1))

    # end with

    with pytest.raises(ValueError):

        dn.omat.from_real(np.zeros(3))

    # end with

    with pytest.raises(ValueError):

        dn.omat.from_real(np.eye(2), order=151)

    # end with

    assert dn.omat.zeros((2, 2), order=150).order == 150

    with pytest.raises(MemoryError):

        dn.omat.zeros((2, 2), bases=[60000], order=5)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_block_errors():
    """
    Check the block view of a direction outside the array's bases and of an empty array.
    """
    matrix = dn.omat.zeros((2, 2), bases=[2], order=2)

    assert matrix.get_block(2).shape == (2, 2)

    with pytest.raises(KeyError):

        matrix.get_block(3)

    # end with

    with pytest.raises(KeyError):

        matrix.get_block([1, 1, 1])

    # end with

    assert dn.omat.zeros((0, 3), bases=[1], order=1).get_block(1).shape == (0, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_singular_real_part_raises_linalg_error():
    """
    Check that a singular real part gives LinAlgError from every linear algebra function, at
    every size, and leaves the operands usable.
    """
    for n in (1, 2, 4, 5):

        real = np.eye(n)
        real[0, 0] = 0.0
        matrix = dn.omat.from_real(real, order=2)
        matrix[0, 0] = dn.e(1, order=2)
        rhs = dn.omat.from_real(np.ones((n, 1)), order=2)

        with pytest.raises(np.linalg.LinAlgError):

            dn.solve(matrix, rhs)

        # end with

        with pytest.raises(np.linalg.LinAlgError):

            dn.inv(matrix)

        # end with

        with pytest.raises(np.linalg.LinAlgError):

            dn.det(matrix)

        # end with

        with pytest.raises(np.linalg.LinAlgError):

            dn.lu_factor(matrix)

        # end with

        assert matrix[1 % n, 1 % n].real == pytest.approx(1.0 if n > 1 else 0.0)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_lu_factor_holder_and_repeated_solves():
    """
    Check the factored copy returned through ``out`` and several solves with one factorization.
    """
    source = _chain_matrix(4, 2, 7)
    matrix = dn.omat.from_sparse(source)
    holder = dn.omat.zeros((4, 4), order=2)
    factor = dn.lu_factor(matrix, out=holder)

    assert holder.shape == (4, 4)
    assert holder.nact == matrix.nact

    for seed in (1, 2, 3):

        rhs_source = sparse.array([[float(seed + i) + 0.1 * sparse.e(1 + seed % 3, order=2)]
                                   for i in range(4)], order=2)
        rhs = dn.omat.from_sparse(rhs_source)
        solution = dn.omat.zeros((4, 1))
        assert dn.lu_solve(factor, rhs, out=solution) is None
        _same(solution, sparse.solve(source, rhs_source))

    # end for

    with pytest.raises(ValueError):

        dn.lu_solve(factor, dn.omat.zeros((3, 1)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_linear_algebra_shape_and_type_errors():
    """
    Check the Python exceptions of solve, inv, det and lu_factor for bad operands.
    """
    square = dn.omat.from_real(np.eye(3), order=1)
    tall = dn.omat.zeros((3, 2), order=1)

    with pytest.raises(ValueError):

        dn.inv(tall)

    # end with

    with pytest.raises(ValueError):

        dn.det(tall)

    # end with

    with pytest.raises(ValueError):

        dn.lu_factor(tall)

    # end with

    with pytest.raises(ValueError):

        dn.solve(tall, tall)

    # end with

    with pytest.raises(ValueError):

        dn.solve(square, dn.omat.zeros((2, 1), order=1))

    # end with

    with pytest.raises(TypeError):

        dn.solve(square, 1.0)

    # end with

    with pytest.raises(TypeError):

        dn.inv(1.0)

    # end with

    with pytest.raises(TypeError):

        dn.det("a")

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _array_with_view():
    """
    Build a 3 x 3 array over one base and a live view of its order-1 block.

    Returns
    -------
    tuple
        The array and the block view.
    """

    matrix = dn.omat.zeros((3, 3), bases=[1], order=1)
    matrix[0, 0] = 2.0 * dn.e(1, order=1)

    return matrix, matrix.get_block(1)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_block_view_refuses_growth_of_its_array():
    """
    Refuse every assignment that would replace the buffer of an array with a live block view, and
    leave the array and the view intact.
    """

    matrix, view = _array_with_view()
    raised = dn.omat.zeros((3, 3), bases=[4], order=3)

    with pytest.raises(BufferError, match="live block views"):

        matrix[1, 1] = dn.e(4, order=3)

    # end with

    with pytest.raises(BufferError):

        matrix[0:2, 0:2] = dn.e(5, order=2)

    # end with

    with pytest.raises(BufferError):

        matrix[:, :] = raised

    # end with

    with pytest.raises(BufferError):

        matrix.set_im(1.0, [7])

    # end with

    with pytest.raises(BufferError):

        matrix.set_deriv(1.0, [8])

    # end with

    assert (matrix.nact, matrix.order) == (1, 1)
    assert view[0, 0] == pytest.approx(2.0)
    assert matrix[0, 0].get_im(1) == pytest.approx(2.0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_block_view_refuses_out_into_its_array():
    """
    Refuse ``out=`` into an array with a live block view (the buffer would be swapped), and allow
    it again once the view is gone.
    """

    matrix, view = _array_with_view()

    with pytest.raises(BufferError, match="live block views"):

        dn.exp(matrix, out=matrix)

    # end with

    with pytest.raises(BufferError):

        dn.lu_factor(dn.omat.from_real(np.eye(3), order=1), out=matrix)

    # end with

    assert view[0, 0] == pytest.approx(2.0)
    assert matrix[0, 0].get_im(1) == pytest.approx(2.0)

    del view
    gc.collect()

    assert dn.exp(matrix, out=matrix) is None
    assert matrix[0, 0].real == pytest.approx(1.0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dropped_block_view_allows_growth():
    """
    Allow growth again when the block view has been released, for the real block as well.
    """

    matrix, view = _array_with_view()
    real_view = matrix.get_block(0)

    del view
    gc.collect()

    with pytest.raises(BufferError):

        matrix[1, 1] = dn.e(4, order=3)

    # end with

    del real_view
    gc.collect()

    matrix[1, 1] = dn.e(4, order=3)

    assert (matrix.nact, matrix.order) == (4, 3)
    assert matrix[1, 1].get_im(4) == pytest.approx(1.0)
    assert matrix[0, 0].get_im(1) == pytest.approx(2.0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_block_view_keeps_write_through_and_same_layout_assignment():
    """
    Keep the view writable, and allow assignments that do not change nact or the truncation order.
    """

    matrix, view = _array_with_view()

    view[1, 2] = 0.75
    assert matrix[1, 2].get_im(1) == pytest.approx(0.75)

    matrix[2, 2] = dn.e(1, order=1)
    assert view[2, 2] == pytest.approx(1.0)

    matrix[0, 1] = 3.0
    assert matrix[0, 1].real == pytest.approx(3.0)

    matrix[0:2, 0:2] = 4.0
    assert matrix[1, 1].real == pytest.approx(4.0)
    assert view[0, 0] == pytest.approx(0.0)

    same_layout = dn.omat.zeros((3, 3), bases=[1], order=1)
    matrix[:, :] = same_layout
    assert np.all(view == 0.0)

    assert matrix.get_block(1).shape == (3, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_soa_add_and_list_repr_like_matso():
    """
    Provide ``add`` and ``list_repr`` like ``pyoti.sparse.matso``.
    """

    left = dn.omat.from_real(np.eye(2), order=1)
    right = dn.omat.from_real(2.0 * np.ones((2, 2)), order=1)
    holder = dn.omat.zeros((2, 2), order=1)

    assert np.array_equal(dn.omat.add(left, right).real, left.real + right.real)
    assert dn.omat.add(left, right, out=holder) is None
    assert np.array_equal(holder.real, left.real + right.real)
    assert left.list_repr().startswith("omat< shape: (2, 2)")

# end function
# --------------------------------------------------------------------------------------------------------
