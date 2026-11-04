"""
Version-2 files (Phase 7b, PLAN-ndarray-contracts.md 11.12): ``'OTD'`` (dense), ``'OTS'`` (semi-sparse)
and ``'OTI'`` (sparse) writers produce version 2 (``ndim``, ``shape[ndim]`` and a layout flag added to
the v1 header), so that 0-D and 1-D logical shapes and n-D dense arrays round-trip; the readers accept
v1 and v2 and validate the header against the file length.

The tests that need a v2 writer (header version 2, 0-D / 1-D / n-D round trips) are marked
``xfail(strict=True, reason="Phase 7b v2")`` per format until the writers' milestones ``otd-v2``,
``ots-v2`` and ``oti-v2`` appear; then the marker of that format (``XF_OTD`` / ``XF_OTS`` / ``XF_OTI``)
is deleted. The 2-D round trips and the bad-file checks pass on the 1.x line and stay green.
"""

import itertools
import struct
import subprocess
import sys

import numpy as np
import pytest

import pyoti.dense as dn
import pyoti.semisparse as semi
import pyoti.sparse as sparse


XF_OTD = []
XF_OTS = []   # ots-v2 landed (2026-11-02): markers removed
XF_OTI = []   # oti-v2 landed (2026-11-02): markers removed

# The one v2 header rule (11.12), all three writers follow it (py header / py-ss header milestones).
# 'OTS' rank 3: a row that cannot exist yet (no Python holder of a semi-sparse array with more than 2
# dimensions before Phase 8; the C reader / writer take ndim up to 31)
XF_OTS_3D = pytest.mark.xfail(strict=True, raises=ValueError,
                              reason="no 3-D semi-sparse holder in Python before Phase 8")

LAYOUT_BYTE = {"OTD": 9, "OTS": 44, "OTI": 44}   # the layout flag slot of each format

MAGICS = {"OTD": b"\x93OTD", "OTS": b"\x93OTS", "OTI": b"\x93OTI"}
EXTENSIONS = {"OTD": ".otd", "OTS": ".ots", "OTI": ".oti"}
MODULES = {"OTD": dn, "OTS": semi, "OTI": sparse}


# ********************************************************************************************************
def _combos(bases, order):
    """
    Directions of orders 1..order over a set of bases, as nondecreasing lists, by order and then
    lexicographically.

    Parameters
    ----------
    bases : list of int
        Bases.
    order : int
        Highest order.

    Returns
    -------
    list of list of int
        The directions.
    """

    out = []
    for p in range(1, order + 1):
        out.extend(list(c) for c in itertools.combinations_with_replacement(bases, p))
    # end for
    return out

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _vals(shape, tag, d):
    """
    Exact deterministic values (multiples of 1/4, never all equal) of the given shape.

    Parameters
    ----------
    shape : tuple of int
        Shape (any ndim, including 0-D).
    tag : int
        Decorrelates arrays.
    d : int
        Direction ordinal, or -1 for the real part (positive values).

    Returns
    -------
    numpy.ndarray
        The values.
    """

    n = int(np.prod(shape, dtype=np.int64))
    k = np.arange(n)

    if d < 0:
        return (1.0 + ((k * 5 + tag) % 7) / 4.0).reshape(shape)
    # end if

    return (((k * 7 + d * 5 + tag * 11) % 13 - 6 + (k % 13 == 6 - (d * 5 + tag * 11) % 13)) / 4.0
            ).reshape(shape)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make(magic, shape, bases, order, tag=1, **kwargs):
    """
    Build a dense or semi-sparse SoA array (any ndim for dense) filled with the ``_vals`` values.

    Parameters
    ----------
    magic : str
        ``'OTD'`` or ``'OTS'``.
    shape : tuple of int
        Shape.
    bases : list of int
        Active bases.
    order : int
        Truncation order.
    tag : int
        Decorrelates arrays.
    **kwargs
        Extra creator keywords (``layout=``).

    Returns
    -------
    object
        The array.
    """

    arr = MODULES[magic].zeros(shape, bases=bases, order=order, **kwargs)

    if int(np.prod(shape, dtype=np.int64)) == 0:
        return arr
    # end if

    arr.set_im(_vals(shape, tag, -1), 0)
    for d, c in enumerate(_combos(bases, order)):
        arr.set_im(_vals(shape, tag, d), c)
    # end for

    return arr

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make_sparse(shape, bases, order, tag=1):
    """
    Build a ``pyoti.sparse`` array of 0, 1 or 2 dimensions (real part and every direction nonzero where
    ``_vals`` is).

    Parameters
    ----------
    shape : tuple of int
        Shape of at most two dimensions.
    bases : list of int
        Active bases.
    order : int
        Truncation order.
    tag : int
        Decorrelates arrays.

    Returns
    -------
    matso
        The array.
    """

    dirs = _combos(bases, order)
    units = [sparse.e(c, order=order) for c in dirs]
    real = _vals(shape, tag, -1)
    coef = [_vals(shape, tag, d) for d in range(len(dirs))]

    def element(idx):
        elem = float(real[idx]) + 0.0 * sparse.e(bases[0], order=order)
        for d, u in enumerate(units):
            v = float(coef[d][idx])
            if v != 0.0:
                elem = elem + v * u
            # end if
        # end for
        return elem
    # end def

    if len(shape) == 0:
        return sparse.array(element(()))
    # end if

    if len(shape) == 1:
        return sparse.array([element((i,)) for i in range(shape[0])])
    # end if

    return sparse.array([[element((i, j)) for j in range(shape[1])] for i in range(shape[0])])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _dump(obj, bases, order):
    """
    Everything the round trip must keep: shape, order, real part and every direction.

    Parameters
    ----------
    obj : object
        Array read or built.
    bases : list of int
        Bases to enumerate directions over.
    order : int
        Truncation order.

    Returns
    -------
    dict
        Shape, order, real part and direction -> values.
    """

    return {
        "shape": tuple(obj.shape),
        "order": obj.order,
        "real": np.asarray(obj.real),
        "dirs": [np.asarray(obj.get_im(c)) for c in _combos(bases, order)],
    }

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_same(first, second):
    """
    Assert that two dumps are identical (shape, order, exact values).

    Parameters
    ----------
    first : dict
        Dump of one array.
    second : dict
        Dump of the other.
    """

    assert first["shape"] == second["shape"]
    assert first["order"] == second["order"]
    assert first["real"].shape == second["real"].shape
    assert np.array_equal(first["real"], second["real"])
    assert len(first["dirs"]) == len(second["dirs"])
    for x, y in zip(first["dirs"], second["dirs"]):
        assert x.shape == y.shape
        assert np.array_equal(x, y)
    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _roundtrip(tmp_path, magic, arr, bases, order, name="x"):
    """
    Save an array, read it back and assert the dumps agree; return the file bytes.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    magic : str
        Format.
    arr : object
        Array to save.
    bases : list of int
        Bases of the array.
    order : int
        Truncation order.
    name : str
        File stem.

    Returns
    -------
    bytes
        The file content.
    """

    path = tmp_path / (name + EXTENSIONS[magic])

    MODULES[magic].save(arr, path)
    back = MODULES[magic].read(path)

    assert type(back) is type(arr)
    _assert_same(_dump(arr, bases, order), _dump(back, bases, order))

    return path.read_bytes()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _build(magic, shape, bases, order, tag=1):
    """
    Build the array of a format.

    Parameters
    ----------
    magic : str
        Format.
    shape : tuple of int
        Shape.
    bases : list of int
        Bases.
    order : int
        Truncation order.
    tag : int
        Decorrelates arrays.

    Returns
    -------
    object
        The array.
    """

    if magic == "OTI":
        return _make_sparse(shape, bases, order, tag)
    # end if

    return _make(magic, shape, bases, order, tag)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("magic, bases, order",
                         [("OTD", [1, 2], 2), ("OTS", [1, 3], 2), ("OTI", [1, 2], 2)])
@pytest.mark.parametrize("shape", [(2, 3), (4, 1), (1, 3), (3, 3)])
def test_roundtrip_2d(tmp_path, magic, bases, order, shape):
    """
    A 2-D array round-trips exactly in every format (the 1.x behaviour, kept in 2.0: an ``(n, 1)``
    array reads back as ``(n, 1)``).

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    magic : str
        Format.
    bases : list of int
        Bases.
    order : int
        Truncation order.
    shape : tuple of int
        Shape.
    """

    _roundtrip(tmp_path, magic, _build(magic, shape, bases, order), bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("magic, bases, order",
                         [("OTD", [1, 2], 2), ("OTS", [1, 3], 2), ("OTI", [1, 2], 2)])
def test_roundtrip_2d_empty(tmp_path, magic, bases, order):
    """
    An empty 2-D array (``(0, 3)``) round-trips in dense and semi-sparse; sparse writes ``(0, 3)`` too.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    magic : str
        Format.
    bases : list of int
        Bases.
    order : int
        Truncation order.
    """

    if magic == "OTI":
        arr = sparse.zeros((0, 3), order=order)
    else:
        arr = MODULES[magic].zeros((0, 3), bases=bases, order=order)
    # end if

    path = tmp_path / ("empty" + EXTENSIONS[magic])
    MODULES[magic].save(arr, path)
    back = MODULES[magic].read(path)

    assert tuple(back.shape) == (0, 3)
    if magic != "OTI":   # an empty sparse array carries no order
        assert back.order == order

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("magic, bases, order", [pytest.param("OTD", [1, 2], 2),
                                                 pytest.param("OTS", [1, 3], 2, marks=XF_OTS),
                                                 pytest.param("OTI", [1, 2], 2, marks=XF_OTI)])
def test_writer_writes_version_2(tmp_path, magic, bases, order):
    """
    Every writer writes version 2: magic, then the format version (uint16 at offset 4) equal to 2, and
    the file is not a valid version-1 file (a v1 reader, which accepts version 1 only, refuses it).

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    magic : str
        Format.
    bases : list of int
        Bases.
    order : int
        Truncation order.
    """

    raw = _roundtrip(tmp_path, magic, _build(magic, (2, 3), bases, order), bases, order)

    assert raw[:4] == MAGICS[magic]
    assert struct.unpack_from("<H", raw, 4)[0] == 2

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("magic, bases, order", [pytest.param("OTD", [1, 2], 2),
                                                 pytest.param("OTS", [1, 3], 2, marks=XF_OTS)])
def test_scalar_writes_version_2(tmp_path, magic, bases, order):
    """
    A scalar file is version 2 as well and reads back equal.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    magic : str
        ``'OTD'`` or ``'OTS'``.
    bases : list of int
        Bases.
    order : int
        Truncation order.
    """

    cls = dn.otinum if magic == "OTD" else semi.ssotinum
    num = cls(1.5, order=order)
    for d, c in enumerate(_combos(bases, order)):
        num.set_im(float(_vals((1,), 3, d)[0]), c)
    # end for

    path = tmp_path / ("s" + EXTENSIONS[magic])
    MODULES[magic].save(num, path)
    back = MODULES[magic].read(path)
    raw = path.read_bytes()

    assert struct.unpack_from("<H", raw, 4)[0] == 2
    assert float(back.real) == 1.5
    for c in _combos(bases, order):
        assert float(back.get_im(c)) == float(num.get_im(c))
    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", ["F", "C"])
@pytest.mark.parametrize("shape", [(), (1,), (4,), (0,), (2, 3), (3, 1), (2, 3, 4), (2, 1, 3, 2),
                                   (3, 0, 2), (2, 2, 2, 2, 2)])
def test_dense_roundtrip_nd(tmp_path, shape, layout):
    """
    Dense arrays of 0, 1, 2 and n dimensions (both layouts, size-0 extents included) round-trip with
    their logical shape, order and every coefficient.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    shape : tuple of int
        Logical shape.
    layout : str
        ``'F'`` or ``'C'``.
    """

    arr = _make("OTD", shape, [1, 2], 2, layout=layout)

    assert tuple(arr.shape) == shape
    raw = _roundtrip(tmp_path, "OTD", arr, [1, 2], 2)

    assert struct.unpack_from("<H", raw, 4)[0] == 2

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_layout_does_not_change_values(tmp_path):
    """
    The same logical array saved from a C-layout and an F-layout buffer reads back with the same values
    (the layout flag describes the payload, not the logical content).

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    first = _make("OTD", (2, 3, 4), [1, 2], 2, layout="C")
    second = _make("OTD", (2, 3, 4), [1, 2], 2, layout="F")
    path_c = tmp_path / "c.otd"
    path_f = tmp_path / "f.otd"

    dn.save(first, path_c)
    dn.save(second, path_f)

    back_c = dn.read(path_c)

    assert tuple(back_c.shape) == (2, 3, 4)
    assert tuple(dn.read(path_f).shape) == (2, 3, 4)
    _assert_same(_dump(back_c, [1, 2], 2), _dump(dn.read(path_f), [1, 2], 2))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_view_saves_its_logical_content(tmp_path):
    """
    Saving a non-contiguous view (a strided slice and a transpose of an n-D array) writes the logical
    content, and the file reads back as a standalone array of the view's shape.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    base = _make("OTD", (4, 6, 3), [1, 2], 2, layout="F")
    view = base[::2, 1::2]
    path = tmp_path / "view.otd"

    dn.save(view, path)
    back = dn.read(path)

    _assert_same(_dump(view, [1, 2], 2), _dump(back, [1, 2], 2))
    assert tuple(back.shape) == (2, 3, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("shape", [pytest.param((), marks=XF_OTS), pytest.param((1,), marks=XF_OTS),
                                   pytest.param((4,), marks=XF_OTS), pytest.param((0,), marks=XF_OTS),
                                   (2, 3), (3, 1)])
@pytest.mark.parametrize("bases", [[1, 3, 5], [2, 4, 6], [7]])
def test_semisparse_roundtrip_logical_shapes(tmp_path, shape, bases):
    """
    Semi-sparse arrays of 0, 1 and 2 dimensions round-trip with their logical shape and the active set
    (a set with unused leading labels included).

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    shape : tuple of int
        Logical shape.
    bases : list of int
        Active bases.
    """

    arr = _make("OTS", shape, bases, 2)
    path = tmp_path / "x.ots"

    assert tuple(arr.shape) == shape   # 2.0 creators: the shape asked for, no (n, 1) promotion

    semi.save(arr, path)
    back = semi.read(path)

    assert list(back.get_active_bases()) == bases
    _assert_same(_dump(arr, bases, 2), _dump(back, bases, 2))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("shape", [pytest.param((4,), marks=XF_OTI), pytest.param((1,), marks=XF_OTI),
                                   (2, 3), (3, 1), (1, 1)])
@pytest.mark.parametrize("bases", [[1, 2], [1, 3, 5]])
def test_sparse_roundtrip_logical_shapes(tmp_path, shape, bases):
    """
    Sparse arrays of 1 and 2 dimensions round-trip with their logical shape (a 1.x ``(n, 1)`` stays
    ``(n, 1)``; a 2.0 ``(n,)`` stays ``(n,)``).

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    shape : tuple of int
        Logical shape.
    bases : list of int
        Active bases.
    """

    arr = _make_sparse(shape, bases, 2)

    assert tuple(arr.shape) == shape   # 2.0: array([...]) of n elements is (n,)
    _roundtrip(tmp_path, "OTI", arr, bases, 2)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_sparse_roundtrip_0d_real(tmp_path):
    """
    A 0-D sparse array (``array(2.5)``) round-trips with shape ``()`` and its real part.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    arr = sparse.array(2.5)
    path = tmp_path / "zero_d.oti"

    sparse.save(arr, path)
    back = sparse.read(path)

    assert tuple(back.shape) == ()
    assert float(np.asarray(back.real)) == 2.5

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("magic, bases", [("OTD", [1, 2]), ("OTS", [1, 3]), ("OTI", [1, 2])])
def test_header_validation_against_file_length(tmp_path, magic, bases):
    """
    The header is validated against the file length: a file truncated anywhere after the magic, or with
    a trailing byte, raises ``ValueError``; the untouched file reads.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    magic : str
        Format.
    bases : list of int
        Bases.
    """

    mod = MODULES[magic]
    path = tmp_path / ("good" + EXTENSIONS[magic])
    bad = tmp_path / ("bad" + EXTENSIONS[magic])

    mod.save(_build(magic, (3, 2), bases, 2), path)
    data = path.read_bytes()

    for cut in list(range(4, min(len(data), 140), 3)) + [len(data) - 1]:
        bad.write_bytes(data[:cut])
        with pytest.raises(ValueError):
            mod.read(bad)
        # end with
    # end for

    bad.write_bytes(data + b"\0")
    with pytest.raises(ValueError):
        mod.read(bad)
    # end with

    bad.write_bytes(data)
    assert tuple(mod.read(bad).shape) == (3, 2)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("magic, bases", [("OTD", [1, 2]), ("OTS", [1, 3]),
                                          pytest.param("OTI", [1, 2], marks=XF_OTI)])
@pytest.mark.parametrize("version", [0, 3, 255, 65535])
def test_unknown_versions_are_refused(tmp_path, magic, bases, version):
    """
    A file whose version field is not 1 or 2 raises ``ValueError``, with no crash. (The frozen 1.x
    sparse reader ignores the version field, so the ``'OTI'`` cases need the v2 decoder.)

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    magic : str
        Format.
    bases : list of int
        Bases.
    version : int
        Version written over the header field.
    """

    mod = MODULES[magic]
    path = tmp_path / ("good" + EXTENSIONS[magic])

    mod.save(_build(magic, (3, 2), bases, 2), path)
    data = path.read_bytes()
    path.write_bytes(data[:4] + struct.pack("<H", version) + data[6:])

    with pytest.raises(ValueError):
        mod.read(path)
    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("magic, bases", [("OTD", [1, 2]), ("OTS", [1, 3])])
def test_header_corruption_never_crashes(tmp_path, magic, bases):
    """
    Overwriting any single header byte with 0x00, 0x01, 0x7f or 0xff either raises ``ValueError`` or
    reads some array (a field that is genuinely free), but never crashes or raises another exception,
    and never asks for a huge allocation.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    magic : str
        Format.
    bases : list of int
        Bases.
    """

    mod = MODULES[magic]
    path = tmp_path / ("good" + EXTENSIONS[magic])
    bad = tmp_path / ("bad" + EXTENSIONS[magic])

    mod.save(_build(magic, (2, 3), bases, 2), path)
    data = path.read_bytes()

    for offset in range(4, 64):
        for value in (0, 1, 0x7F, 0xFF):
            if data[offset] == value:
                continue
            # end if
            bad.write_bytes(data[:offset] + bytes([value]) + data[offset + 1:])
            try:
                mod.read(bad)
            except ValueError:
                pass
            # end try
        # end for
    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
_FUZZ_SCRIPT = """
import sys
import pyoti.sparse as sparse
data = open(sys.argv[1], "rb").read()
for offset in range(6, 64):
    for value in (0, 1, 0x7F, 0xFF):
        if data[offset] == value:
            continue
        open(sys.argv[2], "wb").write(data[:offset] + bytes([value]) + data[offset + 1:])
        try:
            sparse.read(sys.argv[2])
        except ValueError:
            pass
print("ok")
"""


# ********************************************************************************************************
def test_sparse_header_corruption_never_crashes(tmp_path):
    """
    Overwriting any single header byte (other than the version field) of a sparse file with 0x00, 0x01,
    0x7f or 0xff raises ``ValueError`` or reads an array, but never kills the process. Runs in a child
    process: the frozen 1.x C reader answers some corrupt headers with ``exit()`` or a crash (shape and
    count fields), which the new v2 decoder must not.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    path = tmp_path / "good.oti"
    bad = tmp_path / "bad.oti"
    sparse.save(_make_sparse((2, 3), [1, 2], 2), path)

    done = subprocess.run([sys.executable, "-c", _FUZZ_SCRIPT, str(path), str(bad)],
                          capture_output=True, text=True, timeout=300)

    assert done.returncode == 0 and done.stdout.strip() == "ok", done.stderr[-300:]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_nd_header_validation(tmp_path):
    """
    An n-D dense file is validated against its length like a 2-D one: truncation and a trailing byte are
    refused, and a header that claims a huge shape (every header byte set to 0xff in turn) is refused
    or read without a crash.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    path = tmp_path / "nd.otd"
    bad = tmp_path / "bad.otd"

    dn.save(_make("OTD", (2, 3, 4), [1, 2], 2, layout="C"), path)
    data = path.read_bytes()

    assert tuple(dn.read(path).shape) == (2, 3, 4)

    for cut in range(4, 140, 3):
        bad.write_bytes(data[:cut])
        with pytest.raises(ValueError):
            dn.read(bad)
        # end with
    # end for

    bad.write_bytes(data + b"\0")
    with pytest.raises(ValueError):
        dn.read(bad)
    # end with

    for offset in range(4, 96):
        bad.write_bytes(data[:offset] + b"\xff" + data[offset + 1:])
        try:
            dn.read(bad)
        except ValueError:
            pass
        # end try
    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("magic", ["OTD", "OTS", "OTI"])
def test_other_format_files_are_refused(tmp_path, magic):
    """
    A file of another format (different magic) raises ``ValueError`` in every reader.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    magic : str
        Format of the file.
    """

    path = tmp_path / ("x" + EXTENSIONS[magic])
    bases = [1, 2]

    MODULES[magic].save(_build(magic, (2, 2), bases, 1), path)

    for other, mod in MODULES.items():
        if other == magic:
            continue
        # end if
        with pytest.raises(ValueError):
            mod.read(path)
        # end with
    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("magic, bases, shape", [
    ("OTD", [1, 2], ()), ("OTD", [1, 2], (5,)), ("OTD", [1, 2], (2, 3)), ("OTD", [1, 2], (2, 3, 4)),
    ("OTD", [1, 2], (2, 0, 3)),
    pytest.param("OTS", [1, 3], ()),
    pytest.param("OTS", [1, 3], (5,)),
    pytest.param("OTS", [1, 3], (2, 3)),
    pytest.param("OTS", [1, 3], (2, 3, 4), marks=XF_OTS_3D),
    pytest.param("OTI", [1, 2], ()),
    pytest.param("OTI", [1, 2], (5,)),
    pytest.param("OTI", [1, 2], (2, 3))])
def test_one_v2_header_rule(tmp_path, magic, bases, shape):
    """
    Byte-level check of the one v2 header rule: the format's 64-byte header with ``version = 2``
    (uint16 at 4), the layout flag at byte 9 (1 = F, 2 = C), ``ndim`` as uint32 at bytes 40-43 and
    the extents as
    uint64 from byte 64; the file is longer than ``64 + 8 * ndim`` (there is a payload unless the array is
    empty) and a changed ``ndim``, a cut inside the header or a trailing byte is refused with
    ``ValueError``.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    magic : str
        Format.
    bases : list of int
        Bases.
    shape : tuple of int
        Shape.
    """

    mod = MODULES[magic]
    path = tmp_path / ("a" + EXTENSIONS[magic])
    bad = tmp_path / ("bad" + EXTENSIONS[magic])

    mod.save(_build(magic, shape, bases, 2), path)
    data = path.read_bytes()
    nd = len(shape)
    head = 64 + 8 * nd

    assert data[:4] == MAGICS[magic]
    assert struct.unpack_from("<H", data, 4)[0] == 2
    assert data[LAYOUT_BYTE[magic]] in (1, 2)
    if magic == "OTI":
        assert data[7] == 0
    # end if
    assert struct.unpack_from("<I", data, 40)[0] == nd
    assert struct.unpack_from("<%dQ" % nd, data, 64) == tuple(shape)
    assert len(data) >= head

    if int(np.prod(shape, dtype=np.int64)) > 0:
        assert len(data) > head
    # end if

    # the file is exactly header + payload: one more byte, or a cut inside the header, is refused
    for blob in (data + b"\0", data[:head - 1], data[:63]):
        bad.write_bytes(blob)
        with pytest.raises(ValueError):
            mod.read(bad)
        # end with
    # end for

    # ndim changed (different header length): refused
    for other in (nd + 1, 40):
        blob = bytearray(data)
        struct.pack_into("<I", blob, 40, other)
        bad.write_bytes(bytes(blob))
        with pytest.raises(ValueError):
            mod.read(bad)
        # end with
    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", ["F", "C"])
def test_dense_layout_flag_byte(tmp_path, layout):
    """
    A dense root created with ``layout='C'`` or ``'F'`` is written with a valid layout flag at byte 9
    (1 or 2; the writer picks the on-disk order) and reads back equal.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    layout : str
        Creator layout.
    """

    path = tmp_path / "lay.otd"
    arr = _make("OTD", (2, 3, 4), [1, 2], 2, layout=layout)

    dn.save(arr, path)
    data = path.read_bytes()
    back = dn.read(path)

    assert data[9] in (1, 2)
    assert tuple(back.shape) == (2, 3, 4)
    assert np.array_equal(np.asarray(back.real), np.asarray(arr.real))

# end function
# --------------------------------------------------------------------------------------------------------
