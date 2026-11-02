"""
Save and read of semi-sparse scalars, AoS and SoA arrays: round trips, a cross-check against
pyoti.sparse, and bad files.
"""

import itertools
import pathlib

import numpy as np
import pytest

import pyoti.semisparse as semi
import pyoti.sparse as sparse


# Active sets of the round-trip cases: none, one, leading, interleaved and the largest labels.
BASES = ([], [4], [1, 2, 3], [1, 3, 5], [1, 300, 65535])

# (bases, order) of the round-trip cases. The largest labels stop at order 4: the Python API names a
# direction by its global index, which does not fit in 64 bits for label 65535 at order 5 (the file
# format stores local blocks and has no such limit; tests/c/test_semisparse_io.c covers it).
CASES = [(b, o) for b in BASES for o in range(1, 6) if not (max(b, default=0) > 1000 and o > 4)]
CASE_IDS = ["bases%s-order%d" % ("-".join(map(str, b)), o) for b, o in CASES]

# Sets of the sparse cross-check, as in the leveling plan: same, leading and interleaved.
SPARSE_BASES = ([1, 2, 3], [1, 2], [1, 2, 3, 4], [1, 3, 5], [2, 4, 6])


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
def _visible_order(bases, order):
    """
    Highest order whose directions the Python API can name for a set of bases.

    Parameters
    ----------
    bases : list of int
        Active bases.
    order : int
        Truncation order.

    Returns
    -------
    int
        ``order``, or 4 at most when the bases include the largest labels (see ``CASES``).
    """

    return min(order, 4) if max(bases, default=0) > 1000 else order

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _scalar_dump(num):
    """
    Collect everything a semi-sparse scalar holds.

    Parameters
    ----------
    num : ssotinum
        The scalar.

    Returns
    -------
    dict
        Truncation order, active bases, real part and every coefficient of the active set.
    """

    bases = list(num.active_bases)

    return {
        "order": num.order,
        "bases": tuple(bases),
        "real": num.real,
        "ims": [num.get_im(c) for c in _combos(bases, _visible_order(bases, num.order))],
    }

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _dump(obj):
    """
    Collect everything a semi-sparse scalar or array holds, for exact comparisons.

    Parameters
    ----------
    obj : ssotinum or arrss or oarrss
        Scalar or array.

    Returns
    -------
    dict
        Type name, shape, truncation order, active bases and coefficients (per element for AoS,
        per direction block for SoA).
    """

    if isinstance(obj, semi.ssotinum):

        return dict(_scalar_dump(obj), kind="ssotinum")

    # end if

    if isinstance(obj, semi.arrss):

        return {
            "kind": "arrss",
            "shape": obj.shape,
            "elements": [_scalar_dump(obj[i, j]) for i in range(obj.shape[0])
                         for j in range(obj.shape[1])],
        }

    # end if

    bases = list(obj.active_bases)

    # An empty array has no blocks to view.
    if obj.shape[0] * obj.shape[1] == 0:

        return {"kind": "oarrss", "shape": obj.shape, "order": obj.order, "bases": tuple(bases),
                "real": np.zeros(obj.shape), "blocks": []}

    # end if

    return {
        "kind": "oarrss",
        "shape": obj.shape,
        "order": obj.order,
        "bases": tuple(bases),
        "real": obj.get_block(0).copy(),
        "blocks": [obj.get_block(c).copy() for c in _combos(bases, obj.order)],
    }

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _same(first, second):
    """
    Assert that two objects hold exactly the same structure and coefficients.

    Parameters
    ----------
    first : ssotinum or arrss or oarrss
        First object.
    second : ssotinum or arrss or oarrss
        Second object.
    """

    assert type(first) is type(second)

    a, b = _dump(first), _dump(second)

    assert a.keys() == b.keys()

    for key in a:

        if key == "elements":

            assert len(a[key]) == len(b[key])

            for x, y in zip(a[key], b[key]):

                assert x == y

            # end for

        elif key == "blocks":

            assert len(a[key]) == len(b[key])

            for x, y in zip(a[key], b[key]):

                assert np.array_equal(x, y)

            # end for

        elif key == "real" and isinstance(a[key], np.ndarray):

            assert np.array_equal(a[key], b[key])

        else:

            assert a[key] == b[key], key

        # end if

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make_scalar(bases, order, rng, top=None, cap=False):
    """
    Build a semi-sparse scalar with random coefficients over a set of bases.

    Parameters
    ----------
    bases : list of int
        Active bases.
    order : int
        Truncation order.
    rng : numpy.random.Generator
        Source of the coefficients.
    top : int, optional
        Highest order that gets coefficients (default: ``order``).
    cap : bool
        Cap ``top`` at 4 when the bases include the largest labels (see ``CASES``).

    Returns
    -------
    ssotinum
        The scalar.
    """

    num = semi.ssotinum(float(rng.uniform(0.5, 2.0)), order=order)
    top = order if top is None else top

    if cap and max(bases, default=0) > 1000:

        top = min(top, 4)

    # end if

    for combo in _combos(bases, top):

        num.set_im(float(rng.uniform(-2.0, 2.0)), combo)

    # end for

    return num

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make_soa(shape, bases, order, rng):
    """
    Build a semi-sparse SoA array with random coefficients over a set of bases.

    Parameters
    ----------
    shape : tuple of int
        Rows and columns.
    bases : list of int
        Active bases.
    order : int
        Truncation order.
    rng : numpy.random.Generator
        Source of the coefficients.

    Returns
    -------
    oarrss
        The array.
    """

    arr = semi.zeros(shape, bases=bases, order=order)

    if shape[0] * shape[1] == 0:

        return arr

    # end if

    arr.set_im(rng.uniform(0.5, 2.0, size=shape), 0)

    for combo in _combos(bases, order):

        arr.set_im(rng.uniform(-2.0, 2.0, size=shape), combo)

    # end for

    return arr

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make_aos(shape, order, rng):
    """
    Build an AoS array whose elements cycle through different active sets.

    Parameters
    ----------
    shape : tuple of int
        Rows and columns.
    order : int
        Truncation order of every element.
    rng : numpy.random.Generator
        Source of the coefficients.

    Returns
    -------
    arrss
        The array.
    """

    arr = semi.arrss.zeros(shape, order=order)
    count = 0

    for i in range(shape[0]):

        for j in range(shape[1]):

            arr[i, j] = _make_scalar(BASES[count % len(BASES)], order, rng, cap=True)
            count += 1

        # end for

    # end for

    return arr

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _sparse_matrix(shape, bases, order, rng):
    """
    Build a random pyoti.sparse matrix over a set of bases.

    Parameters
    ----------
    shape : tuple of int
        Rows and columns.
    bases : list of int
        Active bases.
    order : int
        Truncation order.
    rng : numpy.random.Generator
        Source of the coefficients.

    Returns
    -------
    matso
        The matrix.
    """

    units = {tuple(c): sparse.e(c, order=order) for c in _combos(bases, order)}
    rows = []

    for i in range(shape[0]):

        row = []

        for j in range(shape[1]):

            elem = float(rng.uniform(0.5, 2.0)) + 0.0 * sparse.e(bases[0], order=order)

            for combo, unit in units.items():

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
@pytest.mark.parametrize("bases, order", CASES, ids=CASE_IDS)
def test_scalar_roundtrip(tmp_path, bases, order):
    """
    A scalar comes back with the same order, active bases and every coefficient.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    bases : list of int
        Active bases.
    order : int
        Truncation order.
    """

    rng = np.random.default_rng(100 + order)
    path = tmp_path / "scalar.bin"

    for top in {order, max(order - 1, 0)}:

        num = _make_scalar(bases, order, rng, top=top)
        semi.save(num, path)
        back = semi.read(path)

        assert isinstance(back, semi.ssotinum)
        _same(num, back)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("bases, order", CASES, ids=CASE_IDS)
@pytest.mark.parametrize("shape", [(0, 0), (1, 1), (3, 2), (2, 0)])
def test_soa_roundtrip(tmp_path, shape, bases, order):
    """
    A SoA array comes back with the same shape, order, active bases and every block.

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

    rng = np.random.default_rng(200 + order)
    path = tmp_path / "soa.bin"
    arr = _make_soa(shape, bases, order, rng)

    semi.save(arr, path)
    back = semi.read(path)

    assert isinstance(back, semi.oarrss)
    assert back.shape == shape
    _same(arr, back)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", [1, 2, 3, 4, 5])
@pytest.mark.parametrize("shape", [(0, 0), (1, 1), (2, 3), (3, 2)])
def test_aos_roundtrip(tmp_path, shape, order):
    """
    An AoS array comes back with every element's own order, active bases and coefficients.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    shape : tuple of int
        Rows and columns.
    order : int
        Truncation order.
    """

    rng = np.random.default_rng(300 + order)
    path = tmp_path / "aos.bin"
    arr = _make_aos(shape, order, rng)

    semi.save(arr, path)
    back = semi.read(path)

    assert isinstance(back, semi.arrss)
    assert back.shape == shape
    _same(arr, back)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_zero_bases_stay_active(tmp_path):
    """
    Active bases whose coefficients are all zero survive a round trip: nothing is compacted.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    path = tmp_path / "zeros.bin"
    arr = semi.zeros((2, 2), bases=[1, 2, 3], order=2)

    semi.save(arr, path)
    back = semi.read(path)

    assert back.active_bases == (1, 2, 3)
    assert not back.get_block([1, 3]).any()
    _same(arr, back)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_save_overwrites_and_accepts_paths(tmp_path):
    """
    Saving over a file replaces it; ``str`` and ``pathlib.Path`` names both work.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    rng = np.random.default_rng(7)
    big = _make_soa((5, 5), [1, 2, 3], 4, rng)
    small = _make_soa((1, 1), [1, 2], 1, rng)
    path = tmp_path / "overwrite.bin"

    semi.save(big, str(path))
    semi.save(small, path)

    _same(small, semi.read(str(path)))
    _same(small, semi.read(pathlib.Path(path)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", [1, 2, 3, 4, 5])
@pytest.mark.parametrize("bases", SPARSE_BASES, ids=lambda b: "bases" + "-".join(map(str, b)))
def test_cross_check_with_sparse(tmp_path, bases, order):
    """
    Values written and read by ``pyoti.sparse`` and converted to semi-sparse match the semi-sparse
    round trip of the same values, for scalars, AoS and SoA arrays.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    bases : list of int
        Active bases.
    order : int
        Truncation order.
    """

    rng = np.random.default_rng(400 + order)
    shape = (2, 3)
    source = _sparse_matrix(shape, bases, order, rng)
    sparse_path = str(tmp_path / "matso.bin")
    semi_path = str(tmp_path / "semi.bin")

    sparse.save(source, sparse_path)
    loaded = sparse.read(sparse_path)

    # The sparse round trip is exact, so both conversions start from the same values.
    _same(semi.oarrss.from_sparse(source), semi.oarrss.from_sparse(loaded))

    for build in (semi.oarrss.from_sparse, semi.arrss.from_sparse):

        converted = build(loaded)

        semi.save(converted, semi_path)
        back = semi.read(semi_path)

        _same(converted, back)
        _same(build(source), back)

    # end for

    # Coefficient by coefficient against the sparse values.
    soa = semi.read(semi_path)

    for i in range(shape[0]):

        for j in range(shape[1]):

            for combo in _combos(bases, order):

                assert soa[i, j].get_im(combo) == source[i, j].get_im(combo)

            # end for

        # end for

    # end for

    scalar = semi.ssotinum(loaded[1, 2])

    semi.save(scalar, semi_path)
    _same(scalar, semi.read(semi_path))
    assert semi.read(semi_path).real == source[1, 2].real

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_missing_and_invalid_names(tmp_path):
    """
    Missing files, directories, empty names and unsupported objects raise Python exceptions.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    arr = semi.zeros((1, 1), bases=[1], order=1)

    with pytest.raises(FileNotFoundError):

        semi.read(tmp_path / "does-not-exist.bin")

    # end with

    with pytest.raises(IsADirectoryError):

        semi.read(tmp_path)

    # end with

    with pytest.raises(ValueError):

        semi.read("")

    # end with

    with pytest.raises(ValueError):

        semi.save(arr, "")

    # end with

    with pytest.raises(OSError):

        semi.save(arr, tmp_path / "no-such-directory" / "x.bin")

    # end with

    with pytest.raises(TypeError):

        semi.save(3.0, tmp_path / "x.bin")

    # end with

    with pytest.raises(TypeError):

        semi.save(sparse.array([[1.0]]), tmp_path / "x.bin")

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_bad_files(tmp_path):
    """
    Files that are not valid semi-sparse files raise ``ValueError``: wrong magic, a sparse file,
    truncation anywhere, trailing bytes, an unknown version and a corrupted header.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    rng = np.random.default_rng(11)
    path = tmp_path / "bad.bin"
    good = tmp_path / "good.bin"
    semi.save(_make_soa((3, 2), [1, 3, 5], 3, rng), good)
    data = good.read_bytes()

    def read_bytes(content):
        path.write_bytes(content)
        return semi.read(path)

    # end function

    with pytest.raises(ValueError, match="magic"):

        read_bytes(b"")

    # end with

    with pytest.raises(ValueError, match="magic"):

        read_bytes(b"this is not an OTI file" * 10)

    # end with

    # A pyoti.sparse file has another magic number.
    sparse.save(_sparse_matrix((2, 2), [1, 2], 2, rng), str(path))

    with pytest.raises(ValueError, match="magic"):

        semi.read(path)

    # end with

    for cut in range(4, len(data), max(1, len(data) // 40)):

        with pytest.raises(ValueError, match="truncated"):

            read_bytes(data[:cut])

        # end with

    # end for

    with pytest.raises(ValueError, match="longer"):

        read_bytes(data + b"\0")

    # end with

    with pytest.raises(ValueError, match="version"):

        read_bytes(data[:4] + (2).to_bytes(2, "little") + data[6:])

    # end with

    with pytest.raises(ValueError):

        read_bytes(data[:6] + bytes([9]) + data[7:])

    # end with

    # Labels 1, 3, 5 rewritten as 3, 1, 5.
    with pytest.raises(ValueError):

        read_bytes(data[:64] + (3).to_bytes(2, "little") + (1).to_bytes(2, "little") + data[68:])

    # end with

    # A header claiming a huge array is rejected without trying to allocate it.
    huge = (1 << 40).to_bytes(8, "little")

    with pytest.raises(ValueError):

        read_bytes(data[:16] + huge + huge + data[32:])

    # end with

# end function
# --------------------------------------------------------------------------------------------------------
