"""
Dense API parity with pyoti.sparse: creators, scalar and array methods, indexing and slice
assignment, functions and the "sparse script runs unchanged" check.

Every check compares pyoti.dense with pyoti.sparse, the oracle, coefficient by coefficient to
1e-13 relative, at orders 1 to 5 and with the same, leading and larger nact active sets.
"""

import inspect
import itertools
import math
import os
import re
import tempfile
from math import comb

import numpy as np
import pytest

import pyoti.sparse as sp
import pyoti.dense as dn


ORDERS = [1, 2, 3, 4, 5]
RTOL = 1e-13
NBASES = 6

# Active sets of the first operand; test_algebra_functions pairs each with the second operand's set:
# {1,2,3} with {1,2,3} (same), {1,2} with {1,2,3,4} (leading), {1,3,5} with {2,4,6} (larger nact).
PATTERNS = [
    pytest.param([1, 2, 3], id="same"),
    pytest.param([1, 2], id="leading"),
    pytest.param([1, 3, 5], id="larger_nact"),
]

LAYOUTS = ["soa", "aos"]

UNARY_FUNCTIONS = [
    "sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh", "tanh", "asinh", "acosh", "atanh",
    "exp", "log", "log10", "sqrt", "cbrt", "erf",
]

# Real part range that keeps every function of UNARY_FUNCTIONS inside its domain.
DOMAIN = {"asin": (0.1, 0.6), "acos": (0.1, 0.6), "atanh": (0.1, 0.6), "acosh": (1.5, 2.5)}


# ********************************************************************************************************
def random_scalar(bases, order, seed, real=None):
    """
    Build a random sparse scalar over the given bases.

    Every base gets an order-1 term, so the sparse active set is exactly ``bases``; the higher
    orders receive a random half of their directions.

    Parameters
    ----------
    bases : list of int
        Bases the scalar depends on.
    order : int
        Truncation order.
    seed : int
        Seed of the random generator.
    real : tuple of float, optional
        Range of the real part; (1, 2) when omitted.

    Returns
    -------
    pyoti.sparse.sotinum
        The scalar.
    """

    rng = np.random.default_rng(seed)
    low, high = real if real is not None else (1.0, 2.0)
    number = sp.number(float(rng.uniform(low, high)), order=order)

    for base in bases:

        number.set_im(float(rng.uniform(0.2, 1.0)), [base])

    # end for

    for power in range(2, order + 1):

        for direction in itertools.combinations_with_replacement(bases, power):

            if rng.uniform() < 0.5:

                number.set_im(float(rng.uniform(0.2, 1.0)), list(direction))

            # end if

        # end for

    # end for

    return number

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def random_array(shape, bases, order, seed, real=None):
    """
    Build a random sparse matrix of random scalars over the given bases.

    Parameters
    ----------
    shape : tuple of int
        Rows and columns.
    bases : list of int
        Bases the elements depend on.
    order : int
        Truncation order.
    seed : int
        Seed of the random generator.
    real : tuple of float, optional
        Range of the real parts.

    Returns
    -------
    pyoti.sparse.matso
        The matrix.
    """

    matrix = sp.zeros(shape, order=order)

    for i in range(shape[0]):

        for j in range(shape[1]):

            matrix[i, j] = random_scalar(bases, order, seed + 31 * i + 7 * j, real)

        # end for

    # end for

    return matrix

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def to_layout(matrix, layout):
    """
    Convert a sparse matrix into a dense array of the requested layout.

    Parameters
    ----------
    matrix : pyoti.sparse.matso
        Sparse matrix.
    layout : str
        ``"soa"`` or ``"aos"``.

    Returns
    -------
    pyoti.dense.omat or pyoti.dense.arro
        Dense copy.
    """

    if layout == "soa":

        return dn.omat.from_sparse(matrix)

    # end if

    return dn.arro.from_sparse(matrix)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def coefficients(value, order):
    """
    Collect the real part and every coefficient of a scalar over the bases 1 to 6.

    Parameters
    ----------
    value : pyoti.sparse.sotinum or pyoti.dense.otinum
        Scalar.
    order : int
        Highest order collected.

    Returns
    -------
    numpy.ndarray
        Coefficients in the order real part, then each order's directions.
    """

    values = [value.real]

    for power in range(1, order + 1):

        for direction in itertools.combinations_with_replacement(range(1, NBASES + 1), power):

            values.append(value.get_im(list(direction)))

        # end for

    # end for

    return np.array(values, dtype=np.float64)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def array_values(value, order):
    """
    Collect the real part and every coefficient of a matrix over the bases 1 to 6.

    Parameters
    ----------
    value : pyoti.sparse.matso or pyoti.dense.omat or pyoti.dense.arro
        Matrix.
    order : int
        Highest order collected.

    Returns
    -------
    numpy.ndarray
        Array of shape (number of directions, rows, columns).
    """

    values = [np.asarray(value.real)]

    for power in range(1, order + 1):

        for direction in itertools.combinations_with_replacement(range(1, NBASES + 1), power):

            values.append(np.asarray(value.get_im(list(direction))))

        # end for

    # end for

    return np.array(values, dtype=np.float64)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def assert_close(actual, expected, rtol=RTOL):
    """
    Assert two arrays agree to a relative tolerance scaled by the largest expected value.

    Parameters
    ----------
    actual : array_like
        Computed values.
    expected : array_like
        Oracle values.
    rtol : float
        Relative tolerance.
    """

    expected = np.asarray(expected, dtype=np.float64)
    actual = np.asarray(actual, dtype=np.float64)
    scale = max(1.0, float(np.max(np.abs(expected)))) if expected.size else 1.0

    assert actual.shape == expected.shape
    np.testing.assert_allclose(actual, expected, rtol=rtol, atol=rtol * scale)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def assert_scalar_matches(actual, expected, order):
    """
    Assert a dense scalar equals a sparse scalar in every coefficient.

    Parameters
    ----------
    actual : pyoti.dense.otinum
        Computed scalar.
    expected : pyoti.sparse.sotinum
        Oracle scalar.
    order : int
        Highest order compared.
    """

    assert_close(coefficients(actual, order), coefficients(expected, order))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def assert_array_matches(actual, expected, order):
    """
    Assert a dense matrix equals a sparse matrix in shape and every coefficient.

    Parameters
    ----------
    actual : pyoti.dense.omat or pyoti.dense.arro
        Computed matrix.
    expected : pyoti.sparse.matso
        Oracle matrix.
    order : int
        Highest order compared.
    """

    assert actual.shape == expected.shape
    assert_close(array_values(actual, order), array_values(expected, order))

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------------
# Scalars
# ------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_scalar_getitem_setitem(order, pattern):
    """
    Read and write coefficients by raw direction key, like the sparse scalar.

    Parameters
    ----------
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the scalar.
    """

    reference = random_scalar(pattern, order, 1)
    scalar = dn.otinum(reference)

    for power in range(1, order + 1):

        for index in range(comb(NBASES + power - 1, power)):

            assert scalar[[index, power]] == pytest.approx(reference[[index, power]], rel=RTOL,
                                                           abs=RTOL)

        # end for

    # end for

    assert scalar[dn.rawdir(0, 1)] == scalar[[0, 1]]
    assert scalar[(0, 0)] == scalar.real

    reference[[0, 1]] = 0.75
    scalar[[0, 1]] = 0.75
    reference[[4, 1]] = -0.5
    scalar[[4, 1]] = -0.5
    scalar[dn.rawdir(1, 1)] = 0.125
    reference[[1, 1]] = 0.125

    assert_scalar_matches(scalar, reference, order)

    with pytest.raises(TypeError):

        scalar[3]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_scalar_copy_set_and_real(order, pattern):
    """
    Copy, overwrite in place and change the real part of a scalar.

    Parameters
    ----------
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the scalar.
    """

    reference = random_scalar(pattern, order, 2)
    scalar = dn.otinum(reference)
    duplicate = scalar.copy()

    assert isinstance(duplicate, dn.otinum)
    assert_scalar_matches(duplicate, reference, order)

    duplicate.real = 5.5
    assert scalar.real == reference.real
    assert duplicate.real == 5.5

    other = random_scalar(pattern, order, 3)
    holder = dn.number(0.0, order=order)
    holder.set(dn.otinum(other))
    assert_scalar_matches(holder, other, order)

    holder.set(2.5)
    assert holder.real == 2.5
    assert holder.order == order
    assert not np.any(coefficients(holder, order)[1:])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_scalar_set_deriv(order, pattern):
    """
    Set coefficients from derivative values.

    Parameters
    ----------
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the scalar.
    """

    reference = random_scalar(pattern, order, 4)
    scalar = dn.otinum(reference)
    directions = [[1], [2, 3], [1, 1], [4], [1, 1, 2], [3, 3, 3], [5, 5]]

    for direction in directions:

        if len(direction) > order:

            continue

        # end if

        reference.set_deriv(3.25, direction)
        scalar.set_deriv(3.25, direction)
        assert scalar.get_deriv(direction) == pytest.approx(3.25, rel=RTOL)

    # end for

    assert_scalar_matches(scalar, reference, order)

    with pytest.raises(TypeError):

        scalar.set_deriv(dn.number(1.0), [1])

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_scalar_extract(order, pattern):
    """
    Extract the multiples of a direction, as coefficients and as derivatives.

    Parameters
    ----------
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the scalar.
    """

    reference = random_scalar(pattern, order, 5)
    scalar = dn.otinum(reference)
    directions = [0, [1], [2], [1, 2], [1, 1], [3], [1, 3], [2, 2, 3], [[1, 3]], [5], [6, 6]]

    for direction in directions:

        expected = reference.extract_im(direction)
        actual = scalar.extract_im(direction)
        assert isinstance(actual, dn.otinum)
        assert_scalar_matches(actual, expected, order)

        expected = reference.extract_deriv(direction)
        actual = scalar.extract_deriv(direction)
        assert_scalar_matches(actual, expected, order)

    # end for

    # A direction of the scalar's own order keeps its coefficient as the real part.
    assert scalar.extract_im([1]).order == order - 1
    assert scalar.extract_deriv([1]).order == order - 1

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_scalar_counts_and_bases(order, pattern):
    """
    Compare the counting properties and the active bases with the sparse scalar.

    Parameters
    ----------
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the scalar.
    """

    reference = random_scalar(pattern, order, 6)
    scalar = dn.otinum(reference)
    counts_ref = reference.get_nnz_full()
    counts = scalar.get_nnz_full()

    assert scalar.nnz == reference.nnz
    assert scalar.actual_order == reference.actual_order
    assert scalar.order == reference.order
    assert reference.get_active_bases() == sorted(pattern)
    assert scalar.get_active_bases() == list(range(1, max(pattern) + 1))
    assert dn.get_active_bases(scalar) == list(range(1, max(pattern) + 1))
    assert scalar.nact == max(pattern)
    assert counts[0] == counts_ref[0]
    assert np.array_equal(counts[2], counts_ref[2])
    assert counts[1] >= counts[0]
    assert counts[3].shape == counts_ref[3].shape

    # The storable size is the dense size over the bases 1..nact.
    for power in range(1, order + 1):

        assert counts[3][power - 1] == comb(max(pattern) + power - 1, power)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_scalar_pow_abs_and_inplace(order, pattern):
    """
    Raise scalars to float and OTI powers, take absolute values and use the in-place operators.

    Parameters
    ----------
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the scalar.
    """

    reference = random_scalar(pattern[0:], order, 7)
    scalar = dn.otinum(reference)
    other_ref = random_scalar(pattern, order, 8)
    other = dn.otinum(other_ref)

    assert_scalar_matches(scalar ** 0.5, reference ** 0.5, order)
    assert_scalar_matches(scalar ** 2.0, reference ** 2.0, order)
    assert_scalar_matches(scalar ** other, reference ** other_ref, order)
    assert_scalar_matches(2.5 ** other, sp.number(2.5, order=order) ** other_ref, order)

    negative = dn.otinum(-reference)
    assert_scalar_matches(abs(negative), reference, order)
    assert_scalar_matches(abs(scalar), reference, order)
    assert_scalar_matches(dn.abs(negative), reference, order)

    total = scalar
    total += other
    assert_scalar_matches(total, reference + other_ref, order)
    total -= other
    assert_scalar_matches(total, reference, order)
    total *= other
    assert_scalar_matches(total, reference * other_ref, order)
    total /= other
    assert_scalar_matches(total, reference * other_ref / other_ref, order)

    # Like the sparse types, += binds a new scalar and leaves other references unchanged.
    alias = scalar
    scalar += 1.0
    assert alias.real == reference.real

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_scalar_reprs_and_printoptions():
    """
    Check the short and long representations and the print options.
    """

    number = dn.number(2.0, order=3) + dn.e([1, 2], order=3)

    assert "nnz: 2" in number.short_repr()
    assert number.short_repr().startswith("otinum(2.0")
    assert "truncation order: 3" in number.long_repr()
    assert "Order 2->" in number.long_repr()

    dn.set_printoptions(terms_print=-1)

    try:

        assert "e([1,2])" in str(number) and "np." not in str(number)
        assert "..." not in str(number)

    finally:

        dn.set_printoptions()

    # end try

    assert dn.imdir([1, 2]) == sp.imdir([1, 2])
    assert dn.imdir([[1, 2], 3]) == sp.imdir([[1, 2], 3])

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------------
# Arrays
# ------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", LAYOUTS)
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_array_properties_and_derivatives(layout, order, pattern):
    """
    Compare the shape properties, the real part and the per-direction accessors of an array.

    Parameters
    ----------
    layout : str
        ``"soa"`` or ``"aos"``.
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the elements.
    """

    reference = random_array((3, 4), pattern, order, 10)
    array = to_layout(reference, layout)

    assert (array.nrows, array.ncols, array.size) == (3, 4, 12)
    assert array.nrows == reference.nrows and array.ncols == reference.ncols
    assert array.size == reference.size
    assert array.order == reference.order

    assert isinstance(array.real, np.ndarray)
    assert array.real.shape == (3, 4)
    assert_close(array.real, reference.real)
    assert array.get_active_bases() == list(range(1, max(pattern) + 1))
    assert dn.get_active_bases(array) == list(range(1, max(pattern) + 1))

    duplicate = array.copy()
    assert type(duplicate) is type(array)
    assert_array_matches(duplicate, reference, order)
    duplicate[0, 0] = 99.0
    assert_close(array.real, reference.real)

    for power in range(1, order + 1):

        for direction in itertools.combinations_with_replacement([1, 2, 3, 5, 6], power):

            actual = array.get_im(list(direction))
            assert isinstance(actual, np.ndarray)
            assert_close(actual, reference.get_im(list(direction)))
            assert_close(array.get_deriv(list(direction)), reference.get_deriv(list(direction)))

        # end for

    # end for

    assert_close(array.get_im(0), reference.real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", LAYOUTS)
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_array_set_im_and_set_deriv(layout, order, pattern):
    """
    Set one direction of every element from a matrix or a scalar, as coefficients or derivatives.

    Parameters
    ----------
    layout : str
        ``"soa"`` or ``"aos"``.
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the elements.
    """

    reference = random_array((2, 3), pattern, order, 11)
    array = to_layout(reference, layout)
    values = np.arange(1.0, 7.0).reshape(2, 3)
    new_base = 6
    deriv_direction = [1, new_base] if order > 1 else [new_base]
    elements = [[reference[i, j] for j in range(3)] for i in range(2)]

    for i in range(2):

        for j in range(3):

            elements[i][j].set_im(values[i, j], [new_base])
            elements[i][j].set_deriv(0.5 * values[i, j], deriv_direction)

        # end for

    # end for

    array.set_im(values, [new_base])
    array.set_deriv(0.5 * values, deriv_direction)
    reference = sp.array(elements, order=order)

    assert_array_matches(array, reference, order)

    array.set_im(2.0, [2])
    assert_close(array.get_im([2]), np.full((2, 3), 2.0))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", LAYOUTS)
@pytest.mark.parametrize("order", [1, 3, 5])
@pytest.mark.parametrize("pattern", PATTERNS)
def test_array_indexing(layout, order, pattern):
    """
    Read elements, rows, columns and strided blocks with the indexing rules of the sparse matrix.

    Parameters
    ----------
    layout : str
        ``"soa"`` or ``"aos"``.
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the elements.
    """

    reference = random_array((3, 4), pattern, order, 12)
    array = to_layout(reference, layout)
    keys = [
        0, 2, slice(None), slice(0, 2), slice(1, None, 2), (1, 2), (0, 0), (2, 3),
        (slice(None), 1), (1, slice(0, 4, 2)), (slice(0, 3, 2), slice(1, 4)), (slice(None), slice(None)),
        (2, slice(None)), (slice(1, 3), 3),
    ]

    for key in keys:

        expected = reference[key]
        actual = array[key]

        if isinstance(expected, sp.sotinum):

            assert isinstance(actual, dn.otinum)
            assert_scalar_matches(actual, expected, order)

        else:

            assert type(actual) is type(array)
            assert_array_matches(actual, expected, order)

        # end if

    # end for

    # The result is an independent copy.
    block = array[0]
    block[0, 0] = 42.0
    assert array[0, 0].real == reference[0, 0].real

    for bad in (3, (3, 0), (0, 4), 1.5, (0, 1, 2), "a"):

        with pytest.raises((IndexError, TypeError)):

            array[bad]

        # end with

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", LAYOUTS)
def test_array_negative_indices(layout):
    """
    Count negative indices from the end, as NumPy does.

    Parameters
    ----------
    layout : str
        ``"soa"`` or ``"aos"``.
    """

    reference = random_array((3, 4), [1, 2], 2, 13)
    array = to_layout(reference, layout)

    assert_scalar_matches(array[-1, -1], reference[2, 3], 2)
    assert_scalar_matches(array[-3, 0], reference[0, 0], 2)
    assert_array_matches(array[-1], reference[2], 2)
    assert_array_matches(array[:, -2], reference[:, 2], 2)

    array[-1, -1] = 7.0
    assert array[2, 3].real == 7.0

    with pytest.raises(IndexError):

        array[-4, 0]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", LAYOUTS)
@pytest.mark.parametrize("order", [1, 3, 5])
@pytest.mark.parametrize("pattern", PATTERNS)
def test_array_slice_assignment(layout, order, pattern):
    """
    Assign reals, scalars and arrays to elements and blocks, like the sparse matrix.

    Parameters
    ----------
    layout : str
        ``"soa"`` or ``"aos"``.
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the value.
    """

    reference = sp.zeros((3, 4))
    array = to_layout(reference, layout)
    row = random_array((1, 2), pattern, order, 14)
    column = random_array((3, 1), pattern, order, 15)
    scalar = random_scalar(pattern, order, 16)

    reference[1, 0:4:2] = row
    array[1, 0:4:2] = to_layout(row, layout)
    assert_array_matches(array, reference, order)

    reference[:, 3] = column
    array[:, 3] = to_layout(column, layout)
    assert_array_matches(array, reference, order)

    reference[2, 1] = scalar
    array[2, 1] = dn.otinum(scalar)
    assert_array_matches(array, reference, order)

    reference[0, :] = 2.5
    array[0, :] = 2.5
    assert_array_matches(array, reference, order)

    reference[1] = scalar
    array[1] = dn.otinum(scalar)
    assert_array_matches(array, reference, order)

    reference[2] = 1.5
    array[2] = 1.5
    assert_array_matches(array, reference, order)

    # Sparse scalars and matrices are accepted; so are real NumPy arrays of the block's size.
    array[0, 0] = scalar
    array[0:1, 1:3] = row
    reference[0, 0] = scalar
    reference[0:1, 1:3] = row
    assert_array_matches(array, reference, order)

    array[1, 0:2] = np.array([3.0, 4.0])
    reference[1, 0] = 3.0
    reference[1, 1] = 4.0
    assert_array_matches(array, reference, order)

    with pytest.raises(ValueError):

        array[0, 0:2] = to_layout(column, layout)

    # end with

    with pytest.raises(IndexError):

        array[3, 0] = 1.0

    # end with

    with pytest.raises(TypeError):

        array[0, 0] = "text"

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", LAYOUTS)
@pytest.mark.parametrize("order", [2, 3, 5])
@pytest.mark.parametrize("pattern", PATTERNS)
def test_assignment_raises_truncation_order(layout, order, pattern):
    """
    Assigning a value of a higher order raises the array's order and keeps every derivative.

    The finite element loops write ``f[i, 0] = f[i, 0] + x`` into an array created with order 0;
    the derivatives of ``x`` must survive, and the entries already there must be zero-extended.

    Parameters
    ----------
    layout : str
        ``"soa"`` or ``"aos"``.
    order : int
        Order of the assigned values.
    pattern : list of int
        Active bases of the values.
    """

    value = random_scalar(pattern, order, 17)
    other = random_scalar(pattern, order - 1, 18)
    block = random_array((1, 2), pattern, order, 19)

    # Scalar item assignment.
    reference = sp.zeros((3, 2))
    array = to_layout(reference, layout)
    assert array.order == 0
    reference[1, 0] = reference[1, 0] + value
    array[1, 0] = array[1, 0] + dn.otinum(value)
    assert array.order == order
    assert_array_matches(array, reference, order)
    assert_close(array[1, 0].get_deriv([pattern[0]]), value.get_deriv([pattern[0]]))

    # A lower-order value keeps the raised order and the earlier entries.
    reference[2, 1] = other
    array[2, 1] = dn.otinum(other)
    assert array.order == order
    assert_array_matches(array, reference, order)

    # Row and block assignment.
    reference = sp.zeros((3, 4))
    array = to_layout(reference, layout)
    reference[0, 0] = 1.25
    array[0, 0] = 1.25
    reference[2, 0:4:2] = block
    array[2, 0:4:2] = to_layout(block, layout)
    assert array.order == order
    assert_array_matches(array, reference, order)
    assert array[0, 0].real == 1.25

    # Scalar broadcast over a block.
    reference = sp.zeros((2, 3))
    array = to_layout(reference, layout)
    reference[:, 1] = value
    array[:, 1] = dn.otinum(value)
    assert array.order == order
    assert_array_matches(array, reference, order)

    # Accumulation in a loop, as in the assembly of a load vector.
    reference = sp.zeros((3, 1))
    array = to_layout(reference, layout)

    for i in range(3):

        term = random_scalar(pattern, order, 20 + i)
        reference[i, 0] = reference[i, 0] + term
        array[i, 0] = array[i, 0] + dn.otinum(term)

    # end for

    assert_array_matches(array, reference, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", LAYOUTS)
@pytest.mark.parametrize("order", [1, 3, 5])
@pytest.mark.parametrize("pattern", PATTERNS)
def test_array_matrix_methods(layout, order, pattern):
    """
    Compare dot, inv, transpose and the reflected matrix product with the sparse matrix.

    Parameters
    ----------
    layout : str
        ``"soa"`` or ``"aos"``.
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the elements.
    """

    reference = random_array((3, 3), pattern, order, 30) + 6.0 * sp.eye(3)
    other_ref = random_array((3, 2), pattern, order, 31)
    array = to_layout(reference, layout)
    other = to_layout(other_ref, layout)

    assert_array_matches(array.T, reference.T, order)
    assert_array_matches(array.transpose(), sp.transpose(reference), order)
    assert_array_matches(dn.transpose(array), reference.T, order)
    assert_array_matches(array.dot(other), sp.dot(reference, other_ref), order)
    assert_array_matches(dn.dot(array, other), sp.dot(reference, other_ref), order)
    assert_array_matches(array @ other, reference @ other_ref, order)
    assert_array_matches(array.inv(), sp.inv(reference), order)
    assert_array_matches(dn.inv(array), sp.inv(reference), order)
    assert_array_matches(type(array).dot(array, other), sp.dot(reference, other_ref), order)

    # A sparse matrix on the left is converted by the reflected product.
    assert_array_matches(other.__rmatmul__(reference), reference @ other_ref, order)
    assert_array_matches(array.T @ to_layout(reference, layout), reference.T @ reference, order)

    # The other dense layout on the left is converted to this layout.
    swapped = to_layout(reference, "aos" if layout == "soa" else "soa")
    product = swapped @ other
    assert_array_matches(product, reference @ other_ref, order)

    with pytest.raises(ValueError):

        array @ array.T[0:2]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", LAYOUTS)
@pytest.mark.parametrize("order", [1, 3, 5])
@pytest.mark.parametrize("pattern", PATTERNS)
def test_array_inplace_and_printing(layout, order, pattern):
    """
    Use ``+=``, ``-=``, ``*=`` and ``/=`` on arrays and print them.

    Parameters
    ----------
    layout : str
        ``"soa"`` or ``"aos"``.
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the elements.
    """

    reference = random_array((2, 3), pattern, order, 40)
    other_ref = random_array((2, 3), pattern, order, 41)
    scalar_ref = random_scalar(pattern, order, 42)
    array = to_layout(reference, layout)
    other = to_layout(other_ref, layout)
    alias = array

    array += other
    reference = reference + other_ref
    assert_array_matches(array, reference, order)

    array -= other
    reference = reference - other_ref
    assert_array_matches(array, reference, order)

    array *= dn.otinum(scalar_ref)
    reference = reference * scalar_ref
    assert_array_matches(array, reference, order)

    array /= other
    reference = reference / other_ref
    assert_array_matches(array, reference, order)

    array *= 2.0
    reference = reference * 2.0
    assert_array_matches(array, reference, order)

    # As in sparse, the in-place operators bind a new array; other names keep the old one.
    assert alias is not array

    assert str(array).startswith("matso< shape: (2, 3)")
    assert "shape: (2, 3)" in array.short_repr()
    assert "order: {}".format(order) in array.long_repr()

    assert_array_matches(abs(-array), reference, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", UNARY_FUNCTIONS)
@pytest.mark.parametrize("order", [1, 3, 5])
@pytest.mark.parametrize("layout", LAYOUTS)
def test_math_functions_on_arrays_and_reals(name, order, layout):
    """
    Evaluate every elementary function on AoS and SoA arrays, and on plain reals.

    Parameters
    ----------
    name : str
        Function name.
    order : int
        Truncation order.
    layout : str
        ``"soa"`` or ``"aos"``.
    """

    reference = random_array((2, 2), [1, 3, 5], order, 50, DOMAIN.get(name, (0.5, 1.5)))
    array = to_layout(reference, layout)
    function = getattr(dn, name)
    expected = getattr(sp, name)(reference)
    result = function(array)

    assert type(result) is type(array)
    assert_array_matches(result, expected, order)

    holder = to_layout(sp.zeros((2, 2)), layout)
    assert function(array, out=holder) is None
    assert_array_matches(holder, expected, order)

    point = DOMAIN.get(name, (0.5, 1.5))[0] + 0.1
    assert function(point) == pytest.approx(getattr(math, name)(point), rel=RTOL)

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------------
# Creators and functions
# ------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
def test_scalar_creators(order):
    """
    Create scalars with ``zero``, ``one``, ``number`` and ``e``, with the sparse call signatures.

    Parameters
    ----------
    order : int
        Truncation order.
    """

    for maker, value in ((dn.zero, 0.0), (dn.one, 1.0)):

        scalar = maker(order=order)
        assert isinstance(scalar, dn.otinum)
        assert scalar.real == value and scalar.order == order
        assert scalar.active_bases == ()

        # nbases is a capacity hint: the value is the one sparse gives.
        hinted = maker(7, order)
        assert hinted.real == value and hinted.order == order and hinted.active_bases == ()

    # end for

    number = dn.number(2.5, nbases=3, order=order)
    assert number.real == 2.5 and number.order == order
    assert_scalar_matches(number, sp.number(2.5, nbases=3, order=order), order)

    for direction in ([1], [2, 3], [[1, 2]], 4):

        assert_scalar_matches(dn.e(direction, nbases=5, order=order),
                              sp.e(direction, nbases=5, order=order), order)

    # end for

    with pytest.raises(ValueError):

        dn.number(1.0, order=256)

    # end with

    with pytest.raises(ValueError):

        dn.zero(nbases=-1)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
def test_array_creators(order):
    """
    Create arrays with ``zeros``, ``ones``, ``eye`` and ``array``, with the sparse call signatures.

    Parameters
    ----------
    order : int
        Truncation order.
    """

    assert dn.zeros(4).shape == sp.zeros(4).shape == (4, 1)
    assert dn.zeros((3,)).shape == (3, 1)
    assert dn.zeros((2, 3), order=order).shape == (2, 3)
    assert dn.zeros((2, 3), 4, order).order == order
    assert dn.zeros((2, 3), nbases=4, order=order).active_bases == ()
    assert dn.zeros((2, 3), bases=[2, 5], order=order).active_bases == (1, 2, 3, 4, 5)
    assert isinstance(dn.zeros(2), dn.omat)

    assert_array_matches(dn.ones((2, 3), order=order), sp.ones((2, 3), order=order), order)
    assert_array_matches(dn.ones(3), sp.ones(3), order)
    assert_array_matches(dn.eye(3, order=order), sp.eye(3, order=order), order)
    assert dn.eye(3, nbases=2, order=order).order == order

    with pytest.raises(ValueError):

        dn.zeros((2, 3, 4))

    # end with

    with pytest.raises(ValueError):

        dn.zeros((2, 3), order=300)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_array_from_nested_lists(order, pattern):
    """
    Build arrays from scalars, lists of OTI scalars and floats, and NumPy arrays.

    Parameters
    ----------
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the scalars.
    """

    first = random_scalar(pattern, order, 60)
    second = random_scalar(pattern, order, 61)
    firsts, seconds = dn.otinum(first), dn.otinum(second)

    got = dn.array([[firsts, 2.0, 0], [seconds, firsts + 1.0, 3]])
    expected = sp.array([[first, 2.0, 0], [second, first + 1.0, 3]])
    assert isinstance(got, dn.omat)
    assert_array_matches(got, expected, order)
    assert got.order == order

    assert_array_matches(dn.array([firsts, seconds, 1.0]), sp.array([first, second, 1.0]), order)
    assert_array_matches(dn.array(firsts), sp.array(first), order)
    assert_array_matches(dn.array(2.5), sp.array(2.5), order)
    assert_array_matches(dn.array([[1, 2], [3, 4]]), sp.array([[1, 2], [3, 4]]), order)

    column = np.arange(1.0, 5.0)
    assert dn.array(column).shape == (4, 1)
    assert dn.array(column)[2, 0].real == 3.0
    assert dn.array(column)[2].real.item() == 3.0
    assert_close(dn.array(np.arange(6.0).reshape(2, 3)).real, np.arange(6.0).reshape(2, 3))

    # Lists of sparse scalars are accepted too, and a higher minimum order is honoured.
    assert_array_matches(dn.array([[first, 2.0]]), sp.array([[first, 2.0]]), order)
    assert dn.array([[1.0, 2.0]], order=order + 1).order == order + 1
    assert_array_matches(dn.array(dn.array([firsts])), sp.array([first]), order)
    assert_array_matches(dn.array(sp.array([first])), sp.array([first]), order)

    with pytest.raises(ValueError):

        dn.array(np.zeros((1, 1, 1, 1)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_creators_call_the_gauss_hooks(monkeypatch):
    """
    Check that a positive ``nip`` sends every creator to the Gauss-point hooks.

    Parameters
    ----------
    monkeypatch : pytest.MonkeyPatch
        Fixture used to replace the hooks with recorders.
    """

    calls = []

    def fake_zeros(shape, bases, order, nip):
        """
        Record the call and return an ordinary zero array.

        Parameters
        ----------
        shape : tuple of int
            Matrix shape.
        bases : list of int
            Active bases.
        order : int
            Truncation order.
        nip : int
            Number of integration points.

        Returns
        -------
        pyoti.dense.omat
            Zero array.
        """

        calls.append(("zeros", tuple(shape), list(bases), order, nip))
        return dn.zeros(shape, bases=bases, order=order)

    # end function

    def fake_scalar(value, bases, order, nip):
        """
        Record the call and return one ordinary scalar per point.

        Parameters
        ----------
        value : float or pyoti.dense.otinum
            Value at every point.
        bases : list of int
            Active bases.
        order : int
            Truncation order.
        nip : int
            Number of integration points.

        Returns
        -------
        list of pyoti.dense.otinum
            One scalar per integration point.
        """

        calls.append(("scalar", value, list(bases), order, nip))
        real = value.real if isinstance(value, dn.otinum) else value
        points = [dn.number(real, order=order) for _ in range(nip)]

        if isinstance(value, dn.otinum):

            points = [value.copy() for _ in range(nip)]

        # end if

        return points

    # end function

    monkeypatch.setattr(dn, "_fe_zeros", fake_zeros)
    monkeypatch.setattr(dn, "_fe_scalar", fake_scalar)

    dn.zeros((2, 3), order=2, nip=4)
    assert calls[-1] == ("zeros", (2, 3), [], 2, 4)

    dn.zero(order=1, nip=3)
    assert calls[-1] == ("scalar", 0.0, [], 1, 3)

    dn.one(nip=2)
    assert calls[-1] == ("scalar", 1.0, [], 0, 2)

    dn.number(2.5, order=3, nip=5)
    assert calls[-1] == ("scalar", 2.5, [], 3, 5)

    # e passes the unit number itself to the hook.
    points = dn.e([1, 2], order=1, nip=2)
    assert isinstance(calls[-1][1], dn.otinum)
    assert calls[-1][2:] == ([], 2, 2)
    assert [point.get_im([1, 2]) for point in points] == [1.0, 1.0]

    identity = dn.eye(2, order=1, nip=2)
    assert calls[-1] == ("zeros", (2, 2), [], 1, 2)
    assert_close(identity.real, np.eye(2))

    ones = dn.ones((1, 2), nip=3)
    assert calls[-1] == ("zeros", (1, 2), [], 0, 3)
    assert_close(ones.real, np.ones((1, 2)))

    dn.array([[1.0, 2.0]], order=2, nip=6)
    assert calls[-1] == ("zeros", (1, 2), [], 2, 6)

    # Without nip the hooks stay untouched.
    count = len(calls)
    dn.zeros((2, 2))
    dn.zero()
    assert len(calls) == count

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", LAYOUTS)
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_algebra_functions(layout, order, pattern):
    """
    Compare sum, sub, mul, div, neg, abs, norm and transpose with their sparse counterparts.

    Parameters
    ----------
    layout : str
        ``"soa"`` or ``"aos"``.
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the first operand (the second uses the leading, larger nact or same set).
    """

    other_bases = {(1, 2, 3): [1, 2, 3], (1, 2): [1, 2, 3, 4], (1, 3, 5): [2, 4, 6]}[tuple(pattern)]
    left_ref = random_array((2, 3), pattern, order, 70)
    right_ref = random_array((2, 3), other_bases, order, 71)
    scalar_ref = random_scalar(other_bases, order, 72)
    left, right = to_layout(left_ref, layout), to_layout(right_ref, layout)
    scalar = dn.otinum(scalar_ref)

    for name in ("sum", "sub", "mul", "div"):

        function, oracle = getattr(dn, name), getattr(sp, name)

        assert_array_matches(function(left, right), oracle(left_ref, right_ref), order)
        assert_array_matches(function(left, scalar), oracle(left_ref, scalar_ref), order)
        assert_array_matches(function(scalar, right), oracle(scalar_ref, right_ref), order)
        assert_array_matches(function(left, 1.5), oracle(left_ref, 1.5), order)
        assert_array_matches(function(2.5, right), oracle(2.5, right_ref), order)
        assert_scalar_matches(function(scalar, 1.5), oracle(scalar_ref, 1.5), order)
        assert_scalar_matches(function(scalar, scalar), oracle(scalar_ref, scalar_ref), order)

        holder = to_layout(sp.zeros((2, 3)), layout)
        assert function(left, right, out=holder) is None
        assert_array_matches(holder, oracle(left_ref, right_ref), order)

    # end for

    assert dn.sum(1.0, 2.0) == 3.0

    assert_array_matches(dn.neg(left), sp.neg(left_ref), order)
    assert_scalar_matches(dn.neg(scalar), sp.neg(scalar_ref), order)
    assert_array_matches(dn.abs(dn.neg(left)), sp.abs(sp.neg(left_ref)), order)
    assert_array_matches(dn.transpose(left), sp.transpose(left_ref), order)

    for p in (1.0, 2.0, 3.0):

        assert_scalar_matches(dn.norm(left, p), sp.norm(left_ref, p), order)

    # end for

    assert_scalar_matches(dn.norm(left), sp.norm(left_ref), order)

    holder = dn.number(0.0)
    assert dn.norm(left, out=holder) is None
    assert_scalar_matches(holder, sp.norm(left_ref), order)

    holder = to_layout(sp.zeros((3, 2)), layout)
    assert dn.transpose(left, out=holder) is None
    assert_array_matches(holder, sp.transpose(left_ref), order)

    holder = dn.number(0.0)
    assert dn.neg(scalar, out=holder) is None
    assert_scalar_matches(holder, sp.neg(scalar_ref), order)

    with pytest.raises(ValueError):

        dn.sum(left, left.T)

    # end with

    with pytest.raises(TypeError):

        dn.transpose(scalar)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", LAYOUTS)
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_direction_functions(layout, order, pattern):
    """
    Compare truncate, get_im and get_deriv as module functions with the sparse ones.

    Parameters
    ----------
    layout : str
        ``"soa"`` or ``"aos"``.
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the elements.
    """

    reference = random_array((2, 2), pattern, order, 80)
    scalar_ref = random_scalar(pattern, order, 81)
    array = to_layout(reference, layout)
    scalar = dn.otinum(scalar_ref)

    for direction in ([1], [1, 2], [3], [[1, 2]]):

        if len(_expand(direction)) > order:

            continue

        # end if

        assert_array_matches(dn.truncate(direction, array), sp.truncate(direction, reference), order)
        assert_scalar_matches(dn.truncate(direction, scalar), sp.truncate(direction, scalar_ref),
                              order)

        for name in ("get_im", "get_deriv"):

            actual = getattr(dn, name)(direction, array)
            assert type(actual) is type(array)
            assert_close(actual.real, getattr(sp, name)(direction, reference).real)

            actual = getattr(dn, name)(direction, scalar)
            assert isinstance(actual, dn.otinum)
            assert actual.real == pytest.approx(getattr(sp, name)(direction, scalar_ref).real,
                                                rel=RTOL, abs=RTOL)

        # end for

    # end for

    holder = to_layout(sp.zeros((2, 2)), layout)
    assert dn.get_deriv([1], array, out=holder) is None
    assert_close(holder.real, sp.get_deriv([1], reference).real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _expand(direction):
    """
    Expand a human direction into the flat list of its bases.

    Parameters
    ----------
    direction : list
        Direction in the sparse format, with exponent pairs such as ``[[1, 2]]``.

    Returns
    -------
    list of int
        One entry per unit of order.
    """

    flat = []

    for item in direction:

        if isinstance(item, list):

            flat.extend([item[0]] * item[1])

        else:

            flat.append(item)

        # end if

    # end for

    return flat

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def run_script(oti, order):
    """
    Run a small finite-element-style script written only with the API shared by both modules.

    Parameters
    ----------
    oti : module
        ``pyoti.sparse`` or ``pyoti.dense``.
    order : int
        Truncation order.

    Returns
    -------
    dict
        NumPy results of the script.
    """

    oti.set_printoptions(terms_print=-1)

    E = 200e9 + oti.e(1, order=order)
    nu = 0.3 + oti.e(2, order=order)
    D = (E / ((1 + nu) * (1 - 2 * nu))) * oti.array([
        [1 - nu, nu, 0],
        [nu, 1 - nu, 0],
        [0, 0, (1 - 2 * nu) / 2],
    ])

    nb = 4
    Nx = oti.array([[0.1, 0.2, 0.3, 0.4]])
    Ny = oti.array([[0.5, 0.25, 0.125, 0.0625]])
    dV = 0.5 + oti.e(3, order=order)

    Be = oti.zeros((3, 2 * nb))
    Be[0, 0:2 * nb:2] = Nx
    Be[1, 1:2 * nb:2] = Ny
    Be[2, 0:2 * nb:2] = Ny
    Be[2, 1:2 * nb:2] = Nx

    Ke = oti.zeros((2 * nb, 2 * nb))

    for _ in range(2):

        Ke += oti.dot(Be.T, oti.dot(D, Be)) * dV

    # end for

    fe = oti.zeros((2 * nb))
    Pi = 1000 + oti.e(4, order=order)

    for k in range(2 * nb):

        fe[k, 0] = fe[k, 0] + (-Pi) * Ke[k, (k + 1) % (2 * nb)] / E

    # end for

    A = Ke + E * oti.eye(2 * nb)
    u = oti.solve(A, fe)
    x = oti.array(np.arange(1.0, 5.0))

    results = {
        "Ke": Ke.real,
        "dKe_dE": Ke.get_deriv(1),
        "dKe_dnu": Ke.get_deriv(2),
        "dKe_dV": Ke.get_deriv(3),
        "fe": fe.real,
        "dfe_dPi": fe.get_deriv(4),
        "u": u.real,
        "du_dE": u.get_deriv(1),
        "x": x.real,
        "x2": np.array([x[2, 0].real, x[2].real.item(), x.nrows, x.ncols, x.size]),
        "element": np.array([Ke[1, 2].order, len(Ke[1, 2].get_active_bases()), Ke[1, 2].real,
                             (Ke[1, 2] ** 0.5).real]),
        "norm": np.array([oti.norm(Ke[0:2, 0:3]).real, oti.norm(Ke, 1.0).real]),
        "transposed": oti.transpose(Ke).real,
    }

    if order >= 2:

        results["d2Ke"] = Ke.get_deriv([1, 2])
        results["d2u"] = u.get_deriv([[1, 2]])

    # end if

    oti.set_printoptions()
    return results

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
def test_sparse_script_runs_unchanged(order):
    """
    Run the same script body with pyoti.sparse and pyoti.dense and compare the results.

    Parameters
    ----------
    order : int
        Truncation order.
    """

    expected = run_script(sp, order)
    actual = run_script(dn, order)

    assert expected.keys() == actual.keys()

    for key in expected:

        assert_close(actual[key], expected[key], rtol=1e-11)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", [1, 3, 5])
@pytest.mark.parametrize("pattern", PATTERNS)
def test_module_functions_dispatch_gauss_operands(order, pattern):
    """
    Send the module functions to the Gauss-point kernels when an operand has integration points.

    Every point of the result must equal the same operation on the sparse matrices.

    Parameters
    ----------
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the elements.
    """

    if not hasattr(dn.otife, "from_sparse"):

        pytest.skip("the dense Gauss-point types are not implemented yet")

    # end if

    nip = 3
    reference = random_array((2, 2), pattern, order, 90) + 4.0 * sp.eye(2)
    other_ref = random_array((2, 2), pattern, order, 91)
    array = to_layout(reference, "soa")
    other = to_layout(other_ref, "soa")
    points = dn.zeros((2, 2), nip=nip, order=order) + array

    def check(result, expected):
        """
        Compare every integration point of a Gauss-point array with the oracle matrix.

        Parameters
        ----------
        result : pyoti.dense.omatfe
            Computed Gauss-point array.
        expected : pyoti.sparse.matso
            Oracle matrix.
        """

        assert result.nip == nip

        for k in range(nip):

            assert_array_matches(result.get_ip(k), expected, order)

        # end for

    # end function

    check(dn.dot(points, points), sp.dot(reference, reference))
    check(dn.dot(points, other), sp.dot(reference, other_ref))
    check(dn.dot(other, points), sp.dot(other_ref, reference))
    check(dn.matmul(points, points), sp.dot(reference, reference))
    check(dn.sum(points, other), sp.sum(reference, other_ref))
    check(dn.sub(other, points), sp.sub(other_ref, reference))
    check(dn.mul(points, other), sp.mul(reference, other_ref))
    check(dn.div(points, other), sp.div(reference, other_ref))
    check(dn.transpose(points), sp.transpose(reference))
    check(dn.inv(points), sp.inv(reference))

    determinant = dn.det(points)
    assert determinant.nip == nip
    assert_scalar_matches(determinant[1], sp.det(reference), order)

    holder = dn.zeros((2, 2), nip=nip, order=order)
    dn.sum(points, other, out=holder)
    check(holder, sp.sum(reference, other_ref))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("shape", [(0, 0), (2, 0), (0, 3)])
def test_get_block_of_zero_size_arrays(shape):
    """
    Return an empty block for a zero-size array, and keep KeyError for directions outside the set.

    Parameters
    ----------
    shape : tuple of int
        Zero-size shape.
    """

    array = dn.zeros(shape, bases=[1, 3], order=2)

    # The array is dense over 1..3 (bases=[1, 3] gives nact = 3), so base 2 is inside the layout.
    for direction in (0, [], [1], [2], [3], [1, 3], [1, 2], [[3, 2]]):

        block = array.get_block(direction)
        assert block.shape == shape
        assert block.dtype == np.float64
        assert block.size == 0

    # end for

    for direction in ([4], [1, 4], [[4, 4]], [1, 1, 1]):

        with pytest.raises(KeyError):

            array.get_block(direction)

        # end with

    # end for

    assert dn.zeros(shape).get_block(0).shape == shape

    with pytest.raises(KeyError):

        dn.zeros(shape).get_block([1])

    # end with

    # The non-empty case still shares memory with the array.
    full = dn.zeros((2, 2), bases=[1])
    full.get_block(0)[0, 1] = 5.0
    assert full[0, 1].real == 5.0

# end function
# --------------------------------------------------------------------------------------------------------


# ------------------------------------------------------------------------------------------------------
# Keyword-name parity
# ------------------------------------------------------------------------------------------------------

# Intentional or still-pending differences of the parameter names, as {qualified name: (names in
# pyoti.dense, reason)}. The names listed are the exact dense parameters, so the test also
# fails when an entry becomes stale (after a rename, delete its entry).
NAME_ALLOW_LIST = {
    "zeros": (["shape_in", "nbases", "order", "nip", "bases"],
              "intentional: the dense extra bases= comes last"),
    "lil_matrix.tocsr": (["preserve_in"], "intentional: extra keyword of the dense builder"),
    # Pending renames owned by other work packages (see build-orch/briefs/WPN-report.md).
}


# ********************************************************************************************************
def parameter_names(function):
    """
    List the parameter names of a function or method without ``self``.

    Parameters
    ----------
    function : callable
        Function or method.

    Returns
    -------
    list of str or None
        Names in positional order, or None when no signature is available.
    """

    try:

        parameters = inspect.signature(function).parameters

    except (TypeError, ValueError):

        return None

    # end try

    return [name for name in parameters if name != "self"]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def name_mismatches():
    """
    Compare the parameter names of every public function and method with a sparse counterpart.

    Returns
    -------
    dict
        ``{qualified name: (sparse names, dense names)}`` for every mismatch.
    """

    mismatches = {}
    checked = 0

    def compare(label, reference, candidate):
        """
        Record a mismatch of the parameter names of two callables.

        Parameters
        ----------
        label : str
            Qualified name used as the key.
        reference : callable
            Sparse function or method.
        candidate : callable
            Dense function or method.
        """

        nonlocal checked
        expected, actual = parameter_names(reference), parameter_names(candidate)

        if expected is None or actual is None:

            return

        # end if

        checked += 1

        if expected != actual:

            mismatches[label] = (expected, actual)

        # end if

    # end function

    for name in dir(sp):

        function = getattr(sp, name)

        if name.startswith("_") or not callable(function) or isinstance(function, type):

            continue

        # end if

        if hasattr(dn, name):

            compare(name, function, getattr(dn, name))

        # end if

    # end for

    pairs = [(sp.sotinum, dn.otinum), (sp.matso, dn.omat), (sp.matso, dn.arro),
             (sp.sotife, dn.otife), (sp.matsofe, dn.omatfe)]

    for name in ("lil_matrix", "csr_matrix"):

        if hasattr(dn, name):

            pairs.append((getattr(sp, name), getattr(dn, name)))

        # end if

    # end for

    for reference_class, candidate_class in pairs:

        for name in dir(reference_class):

            member = getattr(reference_class, name)

            if name.startswith("_") or not callable(member) or not hasattr(candidate_class, name):

                continue

            # end if

            compare("{}.{}".format(candidate_class.__name__, name), member,
                    getattr(candidate_class, name))

        # end for

    # end for

    assert checked > 100, "too few signatures compared: {}".format(checked)
    return mismatches

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_parameter_names_match_sparse():
    """
    Require the same positional parameter names as pyoti.sparse, so keyword calls carry over.

    Every mismatch must be listed in ``NAME_ALLOW_LIST`` with the exact dense names.
    """

    mismatches = name_mismatches()
    unexpected = {
        label: names for label, names in mismatches.items()
        if label not in NAME_ALLOW_LIST or NAME_ALLOW_LIST[label][0] != names[1]
    }
    stale = [label for label in NAME_ALLOW_LIST if label not in mismatches
             and ("." not in label or hasattr(getattr(dn, label.split(".")[0], None),
                                              label.split(".")[1]))]

    assert not unexpected, "parameter names differ from pyoti.sparse: {}".format(unexpected)
    assert not stale, "stale entries in NAME_ALLOW_LIST (now matching sparse): {}".format(stale)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_keyword_calls_from_sparse_scripts():
    """
    Call the renamed functions and methods with the keyword names of pyoti.sparse.
    """

    number = 0.5 + dn.e(1, order=3)
    array = dn.array([[2.0 + dn.e(1, order=3), 1.0], [0.5, 3.0]])

    for name in UNARY_FUNCTIONS:

        if name in ("acosh",):

            continue

        # end if

        assert getattr(dn, name)(val=number).real == pytest.approx(getattr(sp, name)(0.5))

    # end for

    assert dn.pow(val=number, e=2.0).real == pytest.approx(0.25)
    assert dn.logb(val=number, b=2.0).real == pytest.approx(-1.0)
    assert dn.det(arr=array).real == pytest.approx(5.5)
    assert dn.inv(arr=array).shape == (2, 2)
    assert dn.zeros(shape_in=(2, 3)).shape == (2, 3)
    assert dn.ones(shape_in=2).shape == (2, 1)
    assert dn.get_active_bases(obj_in=number) == [1]
    assert dn.imdir(hum_dir=[1, 2]) == sp.imdir([1, 2])
    assert dn.get_deriv(humdir=1, val=number).real == 1.0
    assert dn.truncate(humdir=1, val=number).real == 0.5

    assert number.get_im(humdir=1) == 1.0
    assert number.get_deriv(humdir=1) == 1.0
    assert number.extract_im(humdir=[1]).real == 1.0
    assert number.extract_deriv(humdir=[1]).real == 1.0
    assert number.truncate(humdir=1).real == 0.5

    copy = number.copy()
    copy.set_im(val=3.0, humdir=1)
    assert copy.get_im(1) == 3.0
    copy.set_deriv(val=4.0, humdir=1)
    assert copy.get_deriv(1) == 4.0

    for layout in LAYOUTS:

        matrix = array if layout == "soa" else array.to_aos()

        assert matrix.get_im(hum_dir=1)[0, 0] == 1.0
        assert matrix.get_deriv(hum_dir=1)[0, 0] == 1.0
        assert matrix.truncate(humdir=1).get_deriv(1)[0, 0] == 0.0
        assert type(matrix).dot(matrix, rhs=matrix).shape == (2, 2)
        assert matrix.dot(rhs=matrix).shape == (2, 2)
        assert type(matrix).inv(matrix, out=None).shape == (2, 2)
        assert type(matrix).transpose(matrix, out=None).shape == (2, 2)

        holder = matrix.copy()
        holder.set_im(val=9.0, humdir=2)
        assert holder.get_im(hum_dir=2)[1, 1] == 9.0

    # end for

    assert array.get_block(humdir=1).shape == (2, 2)

    right = dn.array([[1.0], [2.0 + dn.e(1, order=3)]])
    solution = dn.solve(K_in=array, b_in=right)
    assert solution.shape == (2, 1)
    assert_close(dn.dot(lhs=array, rhs=solution).real, right.real)
    assert_close(dn.matmul(lhs=array, rhs=solution).real, right.real)

    holder = dn.zeros((2, 1))
    assert dn.solve(K_in=array, b_in=right, out=holder) is None
    assert_close(holder.real, solution.real)

    factors = dn.lu_factor(A=array)
    stored = dn.zeros((2, 2))
    dn.lu_factor(A=array, out=stored)
    assert_close(stored.real, np.array([[2.0, 1.0], [0.25, 2.75]]))
    assert_close(dn.lu_solve(lu_and_piv=factors, b=right).real, solution.real)
    holder = dn.zeros((2, 1))
    assert dn.lu_solve(lu_and_piv=factors, b=right, out=holder) is None
    assert_close(holder.real, solution.real)

    if hasattr(dn, "save"):

        with tempfile.TemporaryDirectory() as folder:

            path = os.path.join(folder, "array.dnoti")
            dn.save(arr=array, filename=path)
            assert dn.read(filename=path).shape == (2, 2)

        # end with

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def plain(text):
    """
    Turn the NumPy scalar reprs that pyoti.sparse prints (``np.uint16(1)``) into plain integers.

    Parameters
    ----------
    text : str
        Text printed by a sparse scalar or matrix.

    Returns
    -------
    str
        The same text with ``np.uintNN(k)`` replaced by ``k``.
    """

    return re.sub(r"np\.u?int\d+\((\d+)\)", r"\1", text)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("terms_print", [-1, 4, 2, 1])
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("pattern", PATTERNS)
def test_printing_uses_plain_integers_like_sparse(order, pattern, terms_print):
    """
    Print scalars and arrays with plain integer directions, otherwise like pyoti.sparse.

    Parameters
    ----------
    order : int
        Truncation order.
    pattern : list of int
        Active bases of the scalar.
    terms_print : int
        Number of terms printed (-1 for all).
    """

    reference = random_scalar(pattern, order, 100)
    matrix = random_array((2, 2), pattern, order, 101)
    dn.set_printoptions(terms_print=terms_print)

    try:

        text = str(dn.otinum(reference))
        assert text == plain(str(reference))
        assert "np." not in text
        assert repr(dn.otinum(reference)).startswith("otinum(" + text)

        for layout in LAYOUTS:

            printed = str(to_layout(matrix, layout))
            assert printed == plain(str(matrix))
            assert "np." not in printed

        # end for

    finally:

        dn.set_printoptions()

    # end try

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_printing_examples():
    """
    Check the printed form of a few literal numbers, with and without a real part.
    """

    value = dn.e(1, order=3) + dn.e([[1, 2]], order=3)
    assert str(value) == " + 1 * e([1]) + 1 * e([[1,2]])"
    assert str(2.5 + dn.e([3, 2], order=2) * -4) == "2.5 - 4 * e([2,3])"
    assert str(dn.zero()) == "0"
    assert str(dn.e([[1, 2], 3, [4, 3]], order=6)) == " + 1 * e([[1,2],3,[4,3]])"
    assert "uint" not in str(dn.array([[value, 1.0]]))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", LAYOUTS)
def test_strided_slices_and_negative_steps(layout):
    """
    Read and write blocks with steps and reversed slices, like NumPy on the real parts.

    Parameters
    ----------
    layout : str
        ``"soa"`` or ``"aos"``.
    """

    reference = random_array((4, 5), [1, 3], 2, 110)
    array = to_layout(reference, layout)
    real = array.real
    keys = [(slice(None, None, -1), slice(None)), (slice(3, 0, -2), slice(4, 0, -3)),
            (slice(1, 4, 2), slice(0, 5, 2)), slice(2, 0, -1), (2, slice(None, None, -1))]

    for key in keys:

        expected = real[key if isinstance(key, tuple) else (key, slice(None))]
        assert_close(array[key].real, expected.reshape(array[key].shape))
        assert_array_matches(array[key], reference[key], 2)

    # end for

    target = to_layout(sp.zeros((4, 5)), layout)
    block = array[1:3, 0:4:2]
    target[3:0:-2, 4:0:-2] = block
    expected = np.zeros((4, 5))
    expected[3:0:-2, 4:0:-2] = block.real
    assert_close(target.real, expected)
    assert target.order == 2

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_array_builder_edge_cases():
    """
    Build arrays from tuples, ragged lists, empty lists and mixed numeric types.
    """

    number = 1.0 + dn.e(1, order=2)

    assert_close(dn.array(((1, 2.5), (np.float64(3.0), True))).real, [[1.0, 2.5], [3.0, 1.0]])
    assert dn.array((number, 2.0)).shape == (2, 1)
    assert dn.array([[number, 1], [2.0, number]]).order == 2
    assert dn.array([[number], [1.0]], order=4).order == 4
    assert dn.array([[1.0, 2.0], [3.0, 4.0]], order=3).order == 3

    with pytest.raises((ValueError, TypeError)):

        dn.array([[1.0, 2.0], [3.0]])

    # end with

    with pytest.raises((ValueError, TypeError)):

        dn.array([[1.0, "a"]])

    # end with

    # Element bases outside the first element's set grow the shared set.
    mixed = dn.array([[dn.e(3, order=2), dn.e(1, order=2)]])
    assert mixed.active_bases == (1, 2, 3)
    assert mixed[0, 0].get_deriv(3) == 1.0 and mixed[0, 1].get_deriv(1) == 1.0

# end function
# --------------------------------------------------------------------------------------------------------
