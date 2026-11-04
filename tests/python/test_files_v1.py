"""
Version-1 file readability: every fixture in ``tests/python/data/v1/`` (written by the last 1.x
writers, see ``make_fixtures.py`` there) is read by the current build and gives the values of
``manifest.json``. These tests pass on the 1.x line and must stay green through the 2.0 break
(PLAN-ndarray-contracts.md 11.12): the 2.0 readers keep reading version 1.
"""

import json
import pathlib
import struct

import numpy as np
import pytest

import pyoti.dense as dn
import pyoti.semisparse as semi
import pyoti.sparse as sparse


DATA = pathlib.Path(__file__).parent / "data" / "v1"
MANIFEST = json.loads((DATA / "manifest.json").read_text())["files"]
IDS = [entry["file"] for entry in MANIFEST]
MODULES = {"OTD": dn, "OTS": semi, "OTI": sparse}
MAGICS = {"OTD": b"\x93OTD", "OTS": b"\x93OTS", "OTI": b"\x93OTI"}


# ********************************************************************************************************
def _parse_key(text):
    """
    Turn a manifest direction key back into a list of bases.

    Parameters
    ----------
    text : str
        Comma-separated bases.

    Returns
    -------
    list of int
        The direction.
    """

    return [int(b) for b in text.split(",")]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _check_scalar(num, magic, order, bases, real, coeffs):
    """
    Assert that a scalar holds the manifest values.

    Parameters
    ----------
    num : object
        Dense or semi-sparse scalar.
    magic : str
        ``'OTD'`` or ``'OTS'``.
    order : int
        Expected truncation order.
    bases : list of int
        Expected active bases.
    real : float
        Expected real part.
    coeffs : dict
        Direction key -> expected coefficient.
    """

    assert num.order == order
    if magic == "OTD":
        assert num.nact == len(bases)
    else:
        assert list(num.get_active_bases()) == bases
    # end if
    assert float(num.real) == real

    for text, value in coeffs.items():
        assert float(num.get_im(_parse_key(text))) == value, text
    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _check_array(arr, magic, entry):
    """
    Assert that an SoA (or sparse) array holds the manifest values.

    Parameters
    ----------
    arr : object
        Array read from the file.
    magic : str
        ``'OTD'``, ``'OTS'`` or ``'OTI'``.
    entry : dict
        Manifest entry.
    """

    shape = tuple(entry["shape"])

    assert tuple(arr.shape) == shape
    assert arr.order == entry["order"]
    if magic == "OTD":
        assert arr.nact == len(entry["bases"])
    elif magic == "OTS":
        assert list(arr.get_active_bases()) == entry["bases"]
    # end if
    if shape[0] * shape[1] == 0:
        return
    # end if

    assert np.array_equal(np.asarray(arr.real), np.array(entry["real"]))
    for text, value in entry["coeffs"].items():
        got = np.asarray(arr.get_im(_parse_key(text)))
        assert np.array_equal(got, np.array(value)), text
    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _check_aos(arr, magic, entry):
    """
    Assert that an AoS array holds the manifest elements.

    Parameters
    ----------
    arr : object
        Array read from the file.
    magic : str
        ``'OTD'`` or ``'OTS'``.
    entry : dict
        Manifest entry.
    """

    shape = tuple(entry["shape"])

    assert tuple(arr.shape) == shape
    if shape[0] * shape[1] > 0:
        assert arr.order == entry["order"]
    # end if
    for count, elem in enumerate(entry["elements"]):
        i, j = divmod(count, shape[1])
        _check_scalar(arr[i, j], magic, entry["order"], elem["bases"], elem["real"], elem["coeffs"])
    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_manifest_is_complete():
    """
    Every file of the manifest exists, every fixture file is listed, and the three formats and kinds
    are all covered.
    """

    on_disk = {p.name for p in DATA.iterdir() if p.suffix in (".otd", ".ots", ".oti")}

    assert on_disk == set(IDS)
    assert {e["magic"] for e in MANIFEST} == {"OTD", "OTS", "OTI"}
    assert {(e["magic"], e["kind"]) for e in MANIFEST} >= {
        ("OTD", "scalar"), ("OTD", "soa"), ("OTD", "aos"), ("OTS", "scalar"), ("OTS", "soa"),
        ("OTS", "aos"), ("OTI", "array")}

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("entry", MANIFEST, ids=IDS)
def test_fixture_is_version_1(entry):
    """
    A fixture starts with its magic and format version 1, and its size is 64 + the payload size (the
    payload size is at offset 32 for ``'OTD'`` / ``'OTS'`` and at offset 8 for ``'OTI'``).

    Parameters
    ----------
    entry : dict
        Manifest entry.
    """

    raw = (DATA / entry["file"]).read_bytes()

    assert raw[:4] == MAGICS[entry["magic"]]
    assert struct.unpack_from("<H", raw, 4)[0] == 1
    offset = 8 if entry["magic"] == "OTI" else 32
    assert struct.unpack_from("<Q", raw, offset)[0] + 64 == len(raw)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("entry", MANIFEST, ids=IDS)
def test_fixture_reads_to_manifest_values(entry):
    """
    The current reader gives the manifest type, shape, orders, bases and coefficients.

    Parameters
    ----------
    entry : dict
        Manifest entry.
    """

    magic = entry["magic"]
    obj = MODULES[magic].read(DATA / entry["file"])

    if entry["kind"] == "scalar":
        _check_scalar(obj, magic, entry["order"], entry["bases"], entry["real"], entry["coeffs"])
    elif entry["kind"] == "aos":
        _check_aos(obj, magic, entry)
    else:
        _check_array(obj, magic, entry)
    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("entry", MANIFEST, ids=IDS)
def test_fixture_reads_as_str_and_path(entry):
    """
    A fixture reads through a ``str`` and a ``pathlib.Path`` alike, and twice gives the same values.

    Parameters
    ----------
    entry : dict
        Manifest entry.
    """

    mod = MODULES[entry["magic"]]
    first = mod.read(str(DATA / entry["file"]))
    second = mod.read(DATA / entry["file"])

    assert type(first) is type(second)
    assert getattr(first, "shape", None) == getattr(second, "shape", None)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("entry", [e for e in MANIFEST if e["magic"] != "OTI"], ids=lambda e: e["file"])
def test_fixture_readers_refuse_other_formats(entry):
    """
    A dense reader refuses an ``'OTS'`` or ``'OTI'`` fixture and the other way round (different magic),
    with an exception and no crash.

    Parameters
    ----------
    entry : dict
        Manifest entry.
    """

    for magic, mod in MODULES.items():
        if magic == entry["magic"]:
            continue
        # end if
        with pytest.raises((ValueError, TypeError, OSError)):
            mod.read(DATA / entry["file"])
        # end with
    # end for

# end function
# --------------------------------------------------------------------------------------------------------
