"""
Save and read of pyoti.sparse arrays (matso): round trips, file names of every length, and bad files.
"""

import itertools
import pathlib

import numpy as np
import pytest

import pyoti.sparse as sparse


# ********************************************************************************************************
def _combos(bases, order):
    """
    List every direction of orders 1..order over a set of bases, as lists of bases.

    Parameters
    ----------
    bases : list of int
        Active bases.
    order : int
        Highest order.

    Returns
    -------
    list of list of int
        Nondecreasing base lists, ordered by order and then lexicographically.
    """

    combos = []

    for p in range(1, order + 1):

        combos.extend(list(c) for c in itertools.combinations_with_replacement(bases, p))

    # end for

    return combos

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _matrix(shape, bases, order, seed):
    """
    Build a random matso over a set of bases.

    Parameters
    ----------
    shape : tuple of int
        Rows and columns.
    bases : list of int
        Active bases.
    order : int
        Truncation order.
    seed : int
        Seed of the coefficients.

    Returns
    -------
    matso
        The matrix.
    """

    rng = np.random.default_rng(seed)
    units = [sparse.e(c, order=order) for c in _combos(bases, order)]
    rows = []

    for i in range(shape[0]):

        row = []

        for j in range(shape[1]):

            elem = float(rng.uniform(0.5, 2.0)) + 0.0 * sparse.e(bases[0], order=order)

            for unit in units:

                elem = elem + float(rng.uniform(-2.0, 2.0)) * unit

            # end for

            row.append(elem)

        # end for

        rows.append(row)

    # end for

    return sparse.array(rows)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_same(first, second, bases, order):
    """
    Assert that two matso arrays hold the same shape and coefficients.

    Parameters
    ----------
    first : matso
        First array.
    second : matso
        Second array.
    bases : list of int
        Bases to compare the coefficients over.
    order : int
        Highest order to compare.
    """

    assert first.shape == second.shape

    for i in range(first.shape[0]):

        for j in range(first.shape[1]):

            assert first[i, j].real == second[i, j].real

            for combo in _combos(bases, order):

                assert first[i, j].get_im(combo) == second[i, j].get_im(combo)

            # end for

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", [1, 2, 3, 4])
@pytest.mark.parametrize("bases", [[1], [1, 2, 3], [1, 3, 5], [2, 4, 6]],
                         ids=lambda b: "bases" + "-".join(map(str, b)))
@pytest.mark.parametrize("shape", [(1, 1), (3, 2), (2, 3)])
def test_matso_roundtrip(tmp_path, shape, bases, order):
    """
    A matso comes back with the same shape and every coefficient.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    shape : tuple of int
        Rows and columns.
    bases : list of int
        Active bases.
    order : int
        Truncation order.
    """

    path = str(tmp_path / "matso.bin")
    source = _matrix(shape, bases, order, 10 * order)

    sparse.save(source, path)
    back = sparse.read(path)

    _assert_same(source, back, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("shape", [(0, 0), (2, 0), (0, 3)])
def test_empty_matso_roundtrip(tmp_path, shape):
    """
    An array with no elements round trips.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    shape : tuple of int
        Rows and columns.
    """

    path = str(tmp_path / "empty.bin")

    sparse.save(sparse.zeros(shape, order=2), path)

    assert sparse.read(path).shape == shape

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("length", [1, 2, 3, 7, 8, 15, 16, 17, 31, 32, 33, 63, 64, 65, 100, 200])
def test_file_names_of_every_length(tmp_path, length):
    """
    Names of any length work in ``save`` and ``read``; the reader used to write one byte past the
    buffer it allocated for the name.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    length : int
        Number of characters of the file name.
    """

    source = _matrix((2, 2), [1, 2], 2, length)
    name = ("m" * length)[:length]
    path = tmp_path / name

    sparse.save(source, str(path))

    # Read it many times: a heap overflow corrupts the allocator's bookkeeping sooner or later.
    for _ in range(50):

        back = sparse.read(str(path))

    # end for

    _assert_same(source, back, [1, 2], 2)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_unusual_file_names(tmp_path):
    """
    Names with spaces, non-ASCII characters, ``bytes`` and ``pathlib.Path`` objects work.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    source = _matrix((2, 2), [1, 2], 2, 5)

    for name in ("with space.bin", "caf\u00e9-\u03c0.bin", "dots.in.name.bin"):

        path = tmp_path / name
        sparse.save(source, str(path))
        _assert_same(source, sparse.read(str(path)), [1, 2], 2)

    # end for

    sparse.save(source, tmp_path / "pathlike.bin")
    _assert_same(source, sparse.read(tmp_path / "pathlike.bin"), [1, 2], 2)

    sparse.save(source, str(tmp_path / "bytes.bin").encode())
    _assert_same(source, sparse.read(str(tmp_path / "bytes.bin").encode()), [1, 2], 2)

    assert isinstance(tmp_path, pathlib.Path)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_missing_and_invalid_names(tmp_path):
    """
    An empty name, a missing file and an unsupported object raise Python exceptions instead of
    reading garbage or exiting the interpreter.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    source = _matrix((1, 1), [1], 1, 1)

    with pytest.raises(ValueError):

        sparse.save(source, "")

    # end with

    with pytest.raises(ValueError):

        sparse.read("")

    # end with

    with pytest.raises(FileNotFoundError):

        sparse.read(str(tmp_path / "does-not-exist.bin"))

    # end with

    with pytest.raises(FileNotFoundError):

        sparse.read(str(tmp_path))

    # end with

    with pytest.raises(TypeError):

        sparse.save(3.0, str(tmp_path / "x.bin"))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_bad_files(tmp_path):
    """
    Files that are not saved matso arrays raise ``ValueError``: wrong magic, another data format,
    truncation and trailing bytes.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    good = tmp_path / "good.bin"
    path = tmp_path / "bad.bin"

    sparse.save(_matrix((2, 2), [1, 2], 2, 3), str(good))
    data = good.read_bytes()

    def read_bytes(content):
        path.write_bytes(content)
        return sparse.read(str(path))

    # end function

    for content in (b"", b"\x93OT", b"not an OTI file" * 20):

        with pytest.raises(ValueError):

            read_bytes(content)

        # end with

    # end for

    with pytest.raises(ValueError):

        read_bytes(data[:6] + bytes([20]) + data[7:])

    # end with

    for cut in range(4, len(data), max(1, len(data) // 30)):

        with pytest.raises(ValueError):

            read_bytes(data[:cut])

        # end with

    # end for

    with pytest.raises(ValueError):

        read_bytes(data + b"\0")

    # end with

    # The untouched content still reads.
    assert read_bytes(data).shape == (2, 2)

# end function
# --------------------------------------------------------------------------------------------------------
