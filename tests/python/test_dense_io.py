"""
Save and read of dense scalars, AoS and SoA arrays: round trips, a cross-check against pyoti.sparse,
bad files, and files of the other OTI types (sparse, semi-sparse) in both directions.
"""

import itertools
import os
import pathlib
import subprocess
import sys

import numpy as np
import pytest

import pyoti.dense as dn
import pyoti.semisparse as semi
import pyoti.sparse as sparse


# nact of the round-trip cases: none, one, a few, and a set with base 6 (the dense image of the
# semi-sparse interleaved sets {1, 3, 5} / {2, 4, 6}).
NACTS = (0, 1, 3, 6)

# (nact, order) of the round-trip cases, plus a wide layout at a low order.
CASES = [(k, o) for k in NACTS for o in range(1, 6)] + [(300, 1), (40, 2)]
CASE_IDS = ["nact%d-order%d" % (k, o) for k, o in CASES]

# Sets of the sparse cross-check, as in the leveling plan: same, leading and interleaved.
SPARSE_BASES = ([1, 2, 3], [1, 2], [1, 2, 3, 4], [1, 3, 5], [2, 4, 6])


# ********************************************************************************************************
def _combos(bases, order):
    """
    List every direction of orders 1..order over a set of bases, as lists of bases.

    Parameters
    ----------
    bases : list of int
        Bases.
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
def _scalar_dump(num):
    """
    Collect everything a dense scalar holds.

    Parameters
    ----------
    num : otinum
        The scalar.

    Returns
    -------
    dict
        Truncation order, nact, real part and every coefficient over the bases 1..nact.
    """

    bases = list(range(1, num.nact + 1))

    return {
        "order": num.order,
        "nact": num.nact,
        "real": num.real,
        "ims": [num.get_im(c) for c in _combos(bases, num.order)],
    }

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _dump(obj):
    """
    Collect everything a dense scalar or array holds, for exact comparisons.

    Parameters
    ----------
    obj : otinum or arro or omat
        Scalar or array.

    Returns
    -------
    dict
        Type name, shape, truncation order, nact and coefficients (per element for AoS, per
        direction block for SoA).
    """

    if isinstance(obj, dn.otinum):

        return dict(_scalar_dump(obj), kind="otinum")

    # end if

    if isinstance(obj, dn.arro):

        return {
            "kind": "arro",
            "shape": obj.shape,
            "elements": [_scalar_dump(obj[i, j]) for i in range(obj.shape[0])
                         for j in range(obj.shape[1])],
        }

    # end if

    bases = list(range(1, obj.nact + 1))

    # An empty array has no blocks to view.
    if obj.shape[0] * obj.shape[1] == 0:

        return {"kind": "omat", "shape": obj.shape, "order": obj.order, "nact": obj.nact,
                "real": np.zeros(obj.shape), "blocks": []}

    # end if

    return {
        "kind": "omat",
        "shape": obj.shape,
        "order": obj.order,
        "nact": obj.nact,
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
    first : otinum or arro or omat
        First object.
    second : otinum or arro or omat
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
def _make_scalar(nact, order, rng, top=None):
    """
    Build a dense scalar with random coefficients over the bases 1..nact.

    Parameters
    ----------
    nact : int
        Number of active bases.
    order : int
        Truncation order.
    rng : numpy.random.Generator
        Source of the coefficients.
    top : int, optional
        Highest order that gets coefficients (default: ``order``).

    Returns
    -------
    otinum
        The scalar.
    """

    num = dn.otinum(float(rng.uniform(0.5, 2.0)), order=order)
    top = order if top is None else top

    for combo in _combos(list(range(1, nact + 1)), top):

        num.set_im(float(rng.uniform(-2.0, 2.0)), combo)

    # end for

    return num

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make_soa(shape, nact, order, rng):
    """
    Build a dense SoA array with random coefficients over the bases 1..nact.

    Parameters
    ----------
    shape : tuple of int
        Rows and columns.
    nact : int
        Number of active bases.
    order : int
        Truncation order.
    rng : numpy.random.Generator
        Source of the coefficients.

    Returns
    -------
    omat
        The array.
    """

    arr = dn.zeros(shape, bases=list(range(1, nact + 1)), order=order)

    if shape[0] * shape[1] == 0:

        return arr

    # end if

    arr.set_im(rng.uniform(0.5, 2.0, size=shape), 0)

    for combo in _combos(list(range(1, nact + 1)), order):

        arr.set_im(rng.uniform(-2.0, 2.0, size=shape), combo)

    # end for

    return arr

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make_aos(shape, order, rng):
    """
    Build an AoS array whose elements cycle through different nact.

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
    arro
        The array.
    """

    arr = dn.arro.zeros(shape, order=order)
    count = 0

    for i in range(shape[0]):

        for j in range(shape[1]):

            arr[i, j] = _make_scalar(NACTS[count % len(NACTS)], order, rng)
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
@pytest.mark.parametrize("nact, order", CASES, ids=CASE_IDS)
def test_scalar_roundtrip(tmp_path, nact, order):
    """
    A scalar comes back with the same order, nact and every coefficient.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    nact : int
        Number of active bases.
    order : int
        Truncation order.
    """

    rng = np.random.default_rng(100 + order)
    path = tmp_path / "scalar.bin"

    for top in {order, max(order - 1, 0)}:

        num = _make_scalar(nact, order, rng, top=top)
        dn.save(num, path)
        back = dn.read(path)

        assert isinstance(back, dn.otinum)
        assert back.nact == num.nact
        _same(num, back)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("nact, order", CASES, ids=CASE_IDS)
@pytest.mark.parametrize("shape", [(0, 0), (1, 1), (3, 2), (2, 0)])
def test_soa_roundtrip(tmp_path, shape, nact, order):
    """
    A SoA array comes back with the same shape, order, nact and every block.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    shape : tuple of int
        Rows and columns.
    nact : int
        Number of active bases.
    order : int
        Truncation order.
    """

    rng = np.random.default_rng(200 + order)
    path = tmp_path / "soa.bin"
    arr = _make_soa(shape, nact, order, rng)

    dn.save(arr, path)
    back = dn.read(path)

    assert isinstance(back, dn.omat)
    assert back.shape == shape
    _same(arr, back)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", [1, 2, 3, 4, 5])
@pytest.mark.parametrize("shape", [(0, 0), (1, 1), (2, 3), (3, 2)])
def test_aos_roundtrip(tmp_path, shape, order):
    """
    An AoS array comes back with every element's own order, nact and coefficients.

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

    dn.save(arr, path)
    back = dn.read(path)

    assert isinstance(back, dn.arro)
    assert back.shape == shape
    _same(arr, back)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_zero_bases_stay_active(tmp_path):
    """
    Trailing bases whose coefficients are all zero survive a round trip: nothing is compacted.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    path = tmp_path / "zeros.bin"
    arr = dn.zeros((2, 2), bases=[1, 2, 3], order=2)

    dn.save(arr, path)
    back = dn.read(path)

    assert back.nact == 3
    assert back.active_bases == arr.active_bases
    assert not back.get_block([1, 3]).any()
    _same(arr, back)

    num = dn.otinum(1.5, order=3) + 0.0 * dn.e(4, order=3)
    dn.save(num, path)
    assert dn.read(path).nact == num.nact

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
    big = _make_soa((5, 5), 3, 4, rng)
    small = _make_soa((1, 1), 2, 1, rng)
    path = tmp_path / "overwrite.bin"

    dn.save(big, str(path))
    dn.save(small, path)

    _same(small, dn.read(str(path)))
    _same(small, dn.read(pathlib.Path(path)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", [1, 2, 3, 4, 5])
@pytest.mark.parametrize("bases", SPARSE_BASES, ids=lambda b: "bases" + "-".join(map(str, b)))
def test_cross_check_with_sparse(tmp_path, bases, order):
    """
    Values written and read by ``pyoti.sparse`` and converted to dense match the dense round trip
    of the same values, for scalars, AoS and SoA arrays.

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
    dense_path = str(tmp_path / "dense.bin")

    sparse.save(source, sparse_path)
    loaded = sparse.read(sparse_path)

    # The sparse round trip is exact, so both conversions start from the same values.
    _same(dn.omat.from_sparse(source), dn.omat.from_sparse(loaded))

    for build in (dn.omat.from_sparse, dn.arro.from_sparse):

        converted = build(loaded)

        dn.save(converted, dense_path)
        back = dn.read(dense_path)

        _same(converted, back)
        _same(build(source), back)

    # end for

    # Coefficient by coefficient against the sparse values, over every base up to the largest.
    soa = dn.read(dense_path)
    assert dn.omat.from_sparse(source).nact == max(bases)

    for i in range(shape[0]):

        for j in range(shape[1]):

            for combo in _combos(list(range(1, max(bases) + 1)), order):

                assert soa[i, j].get_im(combo) == source[i, j].get_im(combo)

            # end for

        # end for

    # end for

    scalar = dn.otinum(loaded[1, 2])

    dn.save(scalar, dense_path)
    _same(scalar, dn.read(dense_path))
    assert dn.read(dense_path).real == source[1, 2].real

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

    arr = dn.zeros((1, 1), bases=[1], order=1)

    with pytest.raises(FileNotFoundError):

        dn.read(tmp_path / "does-not-exist.bin")

    # end with

    with pytest.raises(IsADirectoryError):

        dn.read(tmp_path)

    # end with

    with pytest.raises(ValueError):

        dn.read("")

    # end with

    with pytest.raises(ValueError):

        dn.save(arr, "")

    # end with

    with pytest.raises(ValueError):

        dn.save(arr, "x\0y.bin")

    # end with

    with pytest.raises(OSError):

        dn.save(arr, tmp_path / "no-such-directory" / "x.bin")

    # end with

    with pytest.raises(TypeError):

        dn.save(3.0, tmp_path / "x.bin")

    # end with

    with pytest.raises(TypeError):

        dn.save(sparse.array([[1.0]]), tmp_path / "x.bin")

    # end with

    with pytest.raises(TypeError):

        dn.save(semi.zeros((1, 1)), tmp_path / "x.bin")

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_bad_files(tmp_path):
    """
    Files that are not valid dense files raise ``ValueError``: wrong magic, truncation anywhere,
    trailing bytes, an unknown version, an unknown type, inconsistent orders and a corrupted
    header.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    rng = np.random.default_rng(11)
    path = tmp_path / "bad.bin"
    good = tmp_path / "good.bin"
    dn.save(_make_soa((3, 2), 5, 3, rng), good)
    data = good.read_bytes()

    # ****************************************************************************************************
    def read_bytes(content):
        """
        Write bytes to the scratch file and read it back with ``pyoti.dense.read``.

        Parameters
        ----------
        content : bytes
            File content.

        Returns
        -------
        otinum or arro or omat
            The object read.
        """

        path.write_bytes(content)
        return dn.read(path)

    # end function
    # ----------------------------------------------------------------------------------------------------

    with pytest.raises(ValueError, match="magic"):

        read_bytes(b"")

    # end with

    with pytest.raises(ValueError, match="magic"):

        read_bytes(b"this is not an OTI file" * 10)

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

    # An active order above the truncation order (header bytes 10 and 11).
    with pytest.raises(ValueError, match="corrupt"):

        read_bytes(data[:10] + bytes([3, 4]) + data[12:])

    # end with

    # A nonzero reserved byte.
    with pytest.raises(ValueError):

        read_bytes(data[:50] + b"\1" + data[51:])

    # end with

    # A header claiming a huge array is rejected without trying to allocate it.
    huge = (1 << 40).to_bytes(8, "little")

    with pytest.raises(ValueError):

        read_bytes(data[:16] + huge + huge + data[32:])

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_cross_type_files(tmp_path):
    """
    A sparse or semi-sparse file read with ``pyoti.dense.read`` raises a clear ``ValueError`` that
    names the module to use, and a dense file is rejected by the sparse and semi-sparse readers.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    rng = np.random.default_rng(12)
    path = tmp_path / "other.bin"

    sparse.save(_sparse_matrix((2, 2), [1, 2], 2, rng), str(path))

    with pytest.raises(ValueError, match="magic.*pyoti.sparse"):

        dn.read(path)

    # end with

    for value in (semi.zeros((2, 2), bases=[1, 3], order=2), semi.e(2, order=2),
                  semi.arrss.zeros((1, 2), order=1)):

        semi.save(value, path)

        with pytest.raises(ValueError, match="magic.*pyoti.semisparse"):

            dn.read(path)

        # end with

    # end for

    for value in (_make_soa((2, 2), 3, 2, rng), _make_scalar(2, 2, rng),
                  _make_aos((1, 2), 2, rng)):

        dn.save(value, path)

        with pytest.raises(ValueError, match="magic"):

            semi.read(path)

        # end with

        with pytest.raises(ValueError):

            sparse.read(str(path))

        # end with

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_path_errors(tmp_path):
    """
    Non-regular, unreadable and unwritable paths raise the matching exceptions: a FIFO or a device
    is not read (ValueError), nor written over; an unreadable file gives PermissionError; saving to a
    directory gives IsADirectoryError; an undecodable name gives a printable message.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    arr = dn.zeros((1, 1), bases=[1], order=1)
    fifo = tmp_path / "fifo"
    os.mkfifo(fifo)

    with pytest.raises(ValueError, match="regular"):

        dn.read(fifo)

    # end with

    with pytest.raises(ValueError, match="regular"):

        dn.save(arr, fifo)

    # end with

    assert fifo.exists()

    with pytest.raises(ValueError, match="regular"):

        dn.read(os.devnull)

    # end with

    with pytest.raises(IsADirectoryError):

        dn.save(arr, tmp_path)

    # end with

    with pytest.raises(FileNotFoundError):

        dn.save(arr, tmp_path / "missing" / "x.bin")

    # end with

    if os.geteuid() != 0:

        locked = tmp_path / "locked.bin"
        dn.save(arr, locked)
        locked.chmod(0)

        try:

            with pytest.raises(PermissionError):

                dn.read(locked)

            # end with

            with pytest.raises(PermissionError):

                dn.save(arr, locked)

            # end with

        finally:

            locked.chmod(0o600)

        # end try

        ro_dir = tmp_path / "readonly"
        ro_dir.mkdir()
        ro_dir.chmod(0o500)

        try:

            with pytest.raises(PermissionError):

                dn.save(arr, ro_dir / "x.bin")

            # end with

        finally:

            ro_dir.chmod(0o700)

        # end try

    # end if

    with pytest.raises(FileNotFoundError) as info:

        dn.read(str(tmp_path / "bad") + "\udcff")

    # end with

    str(info.value).encode("utf-8")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_save_failure_leaves_no_file(tmp_path):
    """
    A write failure (file-size limit in a child process) raises OSError and leaves no partial file.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    target = tmp_path / "big.bin"
    code = "\n".join([
        "import resource, signal, sys",
        "import pyoti.dense as dn",
        "signal.signal(signal.SIGXFSZ, signal.SIG_IGN)",
        "resource.setrlimit(resource.RLIMIT_FSIZE, (4096, 4096))",
        "arr = dn.zeros((40, 40), bases=[1, 2, 3], order=2)",
        "try:",
        "    dn.save(arr, sys.argv[1])",
        "except OSError as exc:",
        "    print('OSError', exc)",
        "else:",
        "    print('saved')",
    ])
    run = subprocess.run([sys.executable, "-c", code, str(target)], capture_output=True, text=True)

    assert run.returncode == 0, run.stderr
    assert run.stdout.startswith("OSError"), run.stdout
    assert not target.exists()

# end function
# --------------------------------------------------------------------------------------------------------
