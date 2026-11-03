"""
Generate the Cython declarations of the dense C API from its headers (PLAN-dense-update.md).

Writes ``dense.pxi``, ``dense_utils.pxi``, ``dense_io.pxi``, ``dense_gauss.pxi`` and
``dense_csr.pxi`` into the output directory, and (PLAN-ndarray.md, Phase 4) ``real_ndarray.pxi`` from
the ndarray headers under ``include/oti/real/ndarray/`` and ``include/oti/core/{status,exec}.h``.
Re-run it whenever one of those headers changes; never edit the generated files by hand.

Usage::

    python tools/gen_dense_pxi.py include include/pyoti/c_otilib
"""

import re
import sys
from pathlib import Path


# Header groups of each generated file, relative to include/oti/dense/.
GROUPS = {
    "dense.pxi": ["scalar/structures.h", "scalar/base.h", "scalar/algebra.h", "scalar/functions.h",
                  "soa/structures.h", "soa/base.h", "soa/algebra.h", "soa/linalg.h", "aos/aos.h"],
    "dense_utils.pxi": ["scalar/utils.h", "soa/utils.h"],
    "dense_io.pxi": ["io/io.h"],
    "dense_gauss.pxi": ["gauss/gauss.h"],
    "dense_csr.pxi": ["csr/csr.h"],
}

TITLES = {
    "dense.pxi": "structures, status codes, scalar, SoA, linear algebra and AoS",
    "dense_utils.pxi": "order and derivative plumbing, truncated products, rom_eval, interp1d",
    "dense_io.pxi": "save / read",
    "dense_gauss.pxi": "Gauss-point types",
    "dense_csr.pxi": "CSR builder and view",
}

# Headers of real_ndarray.pxi, relative to include/oti/, in declaration order (a Cython type must be
# declared before it is used).
ND_FILE = "real_ndarray.pxi"
ND_HEADERS = ["core/status.h", "core/exec.h",
              "real/ndarray/structures.h", "real/ndarray/buffer.h", "real/ndarray/create.h",
              "real/ndarray/views.h", "real/ndarray/iter.h", "real/ndarray/elementwise.h",
              "real/ndarray/reduce.h", "real/ndarray/blas.h", "real/ndarray/linalg.h",
              "real/ndarray/compat_darr.h"]

# Field types of the dense structs that are declared only later in c_otilib.pxd (real_ndarray.pxi is
# included after the dense files): such fields are written as comments. Cython needs only the fields
# it accesses; the Python layer reads these through the oarr_* accessors (PLAN-ndarray.md, Phase 7a).
DEFERRED_TYPES = ("ndarr_t", "oti_meta_t")

# Python keywords cannot name Cython arguments; they get a trailing underscore.
KEYWORDS = ("in|is|from|lambda|def|class|pass|del|global|not|and|or|with|as|yield|import|print|"
            "exec|async|await|None|True|False")


# ********************************************************************************************************
def strip_comments(text):
    """
    Remove the C comments of a header.

    Parameters
    ----------
    text : str
        Header source.

    Returns
    -------
    str
        The source without ``/* */`` and ``//`` comments.
    """

    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    text = re.sub(r"//[^\n]*", "", text)

    return text

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def defines(text):
    """
    List the integer ``#define`` constants of a header.

    Parameters
    ----------
    text : str
        Header source (with comments).

    Returns
    -------
    list of str
        Constant names, include guards excluded.
    """

    out = []

    # Integer constants, and aliases of the library-wide statuses (DN_OK -> OTI_OK, Phase 7a).
    pattern = r"^#define\s+([A-Z][A-Z0-9_]+)\s+(?:\(?-?\s*\d+\)?|OTI_(?:OK|ERR_[A-Z]+)\b)"

    for match in re.finditer(pattern, text, flags=re.M):

        if not match.group(1).startswith("OTI_DENSE_"):

            out.append(match.group(1))

        # end if

    # end for

    return out

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def structs(text):
    """
    Translate the ``typedef struct {...} name;`` blocks and typedef aliases of a header.

    Parameters
    ----------
    text : str
        Header source without comments.

    Returns
    -------
    list of str
        Cython ``ctypedef`` lines, indented for a ``cdef extern`` block.
    """

    out = []

    for match in re.finditer(r"typedef\s+struct\s*\{(.*?)\}\s*(\w+)\s*;", text, flags=re.S):

        header = "    ctypedef struct {}:".format(match.group(2))
        out.append(header)

        for field in match.group(1).split(";"):

            field = " ".join(field.split())

            if field:

                field = re.sub(r"\s*\*\s*", "* ", field)

                if field.split()[0].rstrip("*") in DEFERRED_TYPES:

                    field = "# " + field + " (declared later; use the accessors)"

                # end if

                out.append("        " + field)

            # end if

        # end for

        if all(line.lstrip().startswith("#") for line in out[out.index(header) + 1:]):

            out.append("        pass")

        # end if

        out.append("")

    # end for

    for match in re.finditer(r"typedef\s+(\w+)\s+(\w+)\s*;", text):

        out.append("    ctypedef {} {}".format(match.group(1), match.group(2)))
        out.append("")

    # end for

    return out

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def prototypes(text):
    """
    List the function prototypes of a header, including ``static inline`` definitions.

    Parameters
    ----------
    text : str
        Header source without comments.

    Returns
    -------
    list of str
        One ``ret name(args)`` string per function, arguments normalized for Cython.
    """

    text = re.sub(r"typedef\s+struct\s*\{.*?\}\s*\w+\s*;", "", text, flags=re.S)
    text = re.sub(r"typedef\s+\w+\s+\w+\s*;", "", text)
    text = re.sub(r"^#.*$", "", text, flags=re.M)
    out = []
    start = 0
    pattern = re.compile(r"(static\s+inline\s+)?([A-Za-z_][\w\s\*]*?)\b(\w+)\s*\(([^()]*)\)\s*([;{])",
                         flags=re.S)

    while True:

        match = pattern.search(text, start)

        if not match:

            break

        # end if

        ret = re.sub(r"\s*\*\s*$", "*", " ".join(match.group(2).split()))
        args = " ".join(match.group(4).split())

        if args == "void":

            args = ""

        # end if

        args = re.sub(r"\s*\*\s*", "* ", args).replace("* ,", "*,")
        args = re.sub(r"\b(" + KEYWORDS + r")\b(?=\s*(,|$))", r"\1_", args)
        out.append("{} {}({})".format(ret, match.group(3), args))

        if match.group(5) == "{":

            # Skip the body of a static inline function.
            depth, index = 1, match.end()

            while depth:

                depth += {"{": 1, "}": -1}.get(text[index], 0)
                index += 1

            # end while

            start = index

        else:

            start = match.end()

        # end if

    # end while

    return out

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def wrap(line, indent=4, width=106):
    """
    Wrap a declaration at its commas so that it fits the line width.

    Parameters
    ----------
    line : str
        Declaration.
    indent : int
        Indentation of the first line.
    width : int
        Maximum line length.

    Returns
    -------
    list of str
        The wrapped lines; continuation lines align after the opening parenthesis.
    """

    first = " " * indent + line

    if len(first) <= width:

        return [first]

    # end if

    column = first.index("(") + 1
    parts = first.split(", ")
    lines, current = [], parts[0]

    for part in parts[1:]:

        if len(current) + 2 + len(part) <= width:

            current = current + ", " + part

        else:

            lines.append(current + ",")
            current = " " * column + part

        # end if

    # end for

    lines.append(current)

    return lines

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def nd_defines(text):
    """
    List the numeric ``#define`` constants of an ndarray / core header, split by width.

    Parameters
    ----------
    text : str
        Header source (with comments).

    Returns
    -------
    tuple of list of str
        Names of the constants that fit an ``int`` (declared as ``cdef enum`` members) and names of the
        64-bit ones (``ull`` suffix, declared as ``uint64_t`` externs: a Cython enum would truncate them).
    """

    small, wide = [], []

    for match in re.finditer(r"^#define[ \t]+([A-Z][A-Z0-9_]*)[ \t]+([(\d\-][^\n]*)$", text, flags=re.M):

        value = re.sub(r"//.*$", "", match.group(2)).strip()

        if re.search(r"ull\b", value, flags=re.I):

            wide.append(match.group(1))

        else:

            small.append(match.group(1))

        # end if

    # end for

    return small, wide

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def nd_typedefs(text):
    """
    Translate the structs (tagged or not), opaque struct typedefs and function-pointer typedefs of a
    header, and strip them from the source so that ``prototypes`` does not see them.

    Parameters
    ----------
    text : str
        Header source without comments.

    Returns
    -------
    tuple
        The Cython ``ctypedef`` lines (indented for a ``cdef extern`` block) and the stripped source.
    """

    out = []

    for match in re.finditer(r"typedef\s+struct\s+(\w+)\s+(\w+)\s*;", text):

        out.append("    ctypedef struct {}:".format(match.group(1)))
        out.append("        pass")
        out.append("    ctypedef {} {}".format(match.group(1), match.group(2)))
        out.append("")

    # end for

    text = re.sub(r"typedef\s+struct\s+\w+\s+\w+\s*;", "", text)

    for match in re.finditer(r"typedef\s+struct\s*(\w*)\s*\{(.*?)\}\s*(\w+)\s*;", text, flags=re.S):

        out.append("    ctypedef struct {}:".format(match.group(1) or match.group(3)))

        for field in match.group(2).split(";"):

            field = " ".join(field.split())

            if field:

                field = re.sub(r"\s*\*\s*", "* ", field)
                out.append("        " + field)

            # end if

        # end for

        if match.group(1):

            out.append("    ctypedef {} {}".format(match.group(1), match.group(3)))

        # end if

        out.append("")

    # end for

    text = re.sub(r"typedef\s+struct\s*\w*\s*\{.*?\}\s*\w+\s*;", "", text, flags=re.S)

    for match in re.finditer(r"typedef\s+([\w\s\*]+?)\(\s*\*\s*(\w+)\s*\)\s*\(([^()]*)\)\s*;", text):

        ret = re.sub(r"\s*\*\s*$", "*", " ".join(match.group(1).split()))
        args = re.sub(r"\s*\*\s*", "* ", " ".join(match.group(3).split())).replace("* ,", "*,")
        out.append("    ctypedef {} (*{})({})".format(ret, match.group(2), args))
        out.append("")

    # end for

    text = re.sub(r"typedef\s+[\w\s\*]+?\(\s*\*\s*\w+\s*\)\s*\([^()]*\)\s*;", "", text)

    return out, text

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def write_ndarray(root, outdir):
    """
    Write ``real_ndarray.pxi``: the Cython declarations of the ndarray C API.

    Parameters
    ----------
    root : Path
        ``<include root>/oti``.
    outdir : Path
        Output directory.
    """

    lines = ["# Real ndarray C declarations: ndarr_t, buffers, creators, views, elementwise, reductions,",
             "# BLAS and linear algebra, statuses and the execution context.",
             "# GENERATED from include/oti/real/ndarray/*.h and include/oti/core/{status,exec}.h",
             "# (PLAN-ndarray.md, Phase 4) by tools/gen_dense_pxi.py; re-run it when one changes.",
             "# Do not edit by hand.",
             'cdef extern from "oti/real/ndarray.h" nogil:', ""]

    for header in ND_HEADERS:

        raw = (root / header).read_text()
        small, wide = nd_defines(raw)
        lines.append("    # " + header)

        if small:

            lines.append("    cdef enum:")
            lines.extend("        " + name for name in small)
            lines.append("")

        # end if

        lines.extend("    uint64_t " + name for name in wide)

        if wide:

            lines.append("")

        # end if

        typedefs, text = nd_typedefs(strip_comments(raw))
        lines.extend(typedefs)

        for proto in prototypes(text):

            lines.extend(wrap(proto, width=104))

        # end for

        lines.append("")

    # end for

    (outdir / ND_FILE).write_text("\n".join(lines).rstrip() + "\n")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def main():
    """
    Write every generated file from the headers under ``<include root>/oti/dense`` and the ndarray ones.
    """

    root = Path(sys.argv[1]) / "oti" / "dense"
    outdir = Path(sys.argv[2])
    outdir.mkdir(parents=True, exist_ok=True)

    for fname, headers in GROUPS.items():

        lines = ["# Dense C declarations: {}.".format(TITLES[fname]),
                 "# GENERATED from include/oti/dense/**/*.h (PLAN-dense-update.md) by",
                 "# tools/gen_dense_pxi.py; re-run it when a dense header changes.",
                 "# Do not edit by hand.",
                 'cdef extern from "oti/dense.h" nogil:', ""]

        for header in headers:

            raw = (root / header).read_text()
            consts = defines(raw)
            text = strip_comments(raw)
            lines.append("    # " + header)

            if consts:

                lines.append("    cdef enum:")
                lines.extend("        " + name for name in consts)
                lines.append("")

            # end if

            lines.extend(structs(text))

            for proto in prototypes(text):

                lines.extend(wrap(proto))

            # end for

            lines.append("")

        # end for

        (outdir / fname).write_text("\n".join(lines).rstrip() + "\n")

    # end for

    write_ndarray(Path(sys.argv[1]) / "oti", outdir)

# end function
# --------------------------------------------------------------------------------------------------------


if __name__ == "__main__":

    main()

# end if
