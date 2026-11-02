# Direction parsing, raw directions and native status helpers.

import builtins as _builtins
from libc.stdlib cimport malloc, calloc, free
from math import factorial as _factorial
from math import log as _math_log
import pyoti.sparse as _sparse_module
from pyoti.sparse import set_printoptions as _sparse_set_printoptions


# ********************************************************************************************************
def _unrank(index, order):
    """
    Return the sorted global base labels of a global direction (index, order).

    Inverse of the colex rank sum(comb(label - 1 + i, i + 1)). It does not read the dhelp tables,
    so it covers every label.

    Parameters
    ----------
    index : int
        Global direction index within its order.
    order : int
        Direction order.

    Returns
    -------
    list of int
        Nondecreasing labels, one per unit of order.

    Examples
    --------
    >>> _unrank(11, 2)
    [2, 5]
    """

    labels = [0] * order
    rest = index

    for i in range(order - 1, -1, -1):

        # Largest c with comb(c, i + 1) <= rest; comb(c, m) >= c - m + 1 bounds c by rest + i.
        low, high = i, i + rest

        while low < high:

            mid = (low + high + 1) // 2

            if comb(mid, i + 1) <= rest:

                low = mid

            else:

                high = mid - 1

            # end if

        # end while

        rest -= comb(low, i + 1)
        labels[i] = low - i + 1

    # end for

    return labels

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
class rawdir:
    """
    A direction given by its raw global (index, order) pair.

    Every function of this module that takes a direction also accepts a ``rawdir``. Use it when
    the index comes from C, from ``pyoti.core.imdir`` or from another numbering step. A plain
    list or tuple always means a list of bases, as in ``pyoti.sparse``, so ``(4, 2)`` is
    ``e([2, 4])`` while ``rawdir(4, 2)`` is the order-2 direction with global index 4, ``e([2, 3])``.

    Parameters
    ----------
    index : int
        Global direction index within its order (the numbering of ``sotinum`` and ``ssotinum``).
    order : int
        Direction order, 0 to 255. Order 0 is the real part and needs index 0.

    Examples
    --------
    >>> d = rawdir(4, 2)
    >>> d.bases
    (2, 3)
    >>> rawdir.from_direction([2, 3]) == d
    True
    """

    __slots__ = ("_index", "_order")

    # ****************************************************************************************************
    def __init__(self, index, order):
        """
        Validate and store the pair.

        Parameters
        ----------
        index : int
            Global direction index within its order.
        order : int
            Direction order.
        """

        if not isinstance(index, (int, np.integer)) or not isinstance(order, (int, np.integer)):

            raise TypeError("rawdir index and order must be integers")

        # end if

        index, order = int(index), int(order)

        if not 0 <= order <= 255:

            raise ValueError("rawdir order must be between 0 and 255")

        # end if

        if not 0 <= index <= 2**64 - 1 or (order == 0 and index != 0):

            raise ValueError("rawdir index out of range for its order")

        # end if

        if order > 0 and _unrank(index, order)[-1] > 65535:

            raise ValueError("rawdir index needs a base label above 65535")

        # end if

        self._index = index
        self._order = order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def from_direction(cls, direction):
        """
        Build the raw pair of a direction written in any pyoti.sparse format.

        Parameters
        ----------
        direction : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        rawdir
            The same direction as a raw pair.

        Examples
        --------
        >>> rawdir.from_direction([[1, 2]])
        rawdir(0, 2)
        """

        return cls(*_direction(direction))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def index(self):
        """
        Return the global direction index.

        Returns
        -------
        int
            Index within the direction's order.

        Examples
        --------
        >>> rawdir(4, 2).index
        4
        """

        return self._index

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def order(self):
        """
        Return the direction order.

        Returns
        -------
        int
            Order.

        Examples
        --------
        >>> rawdir(4, 2).order
        2
        """

        return self._order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def bases(self):
        """
        Return the sorted base labels of the direction.

        Returns
        -------
        tuple of int
            One label per unit of order; empty for the real part.

        Examples
        --------
        >>> rawdir(0, 2).bases
        (1, 1)
        """

        return tuple(_unrank(self._index, self._order))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __eq__(self, other):
        """
        Compare two raw directions.

        Parameters
        ----------
        other : object
            Object to compare.

        Returns
        -------
        bool
            True when both index and order match.

        Examples
        --------
        >>> rawdir(1, 2) == rawdir(1, 2)
        True
        """

        if not isinstance(other, rawdir):

            return NotImplemented

        # end if

        return self._index == other._index and self._order == other._order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __hash__(self):
        """
        Hash the pair.

        Returns
        -------
        int
            Hash of (index, order).

        Examples
        --------
        >>> hash(rawdir(1, 2)) == hash((1, 2))
        True
        """

        return hash((self._index, self._order))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __repr__(self):
        """
        Show the pair.

        Returns
        -------
        str
            For example ``rawdir(4, 2)``.

        Examples
        --------
        >>> rawdir(4, 2)
        rawdir(4, 2)
        """

        return f"rawdir({self._index}, {self._order})"

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _direction(object direction):
    """
    Resolve a human direction exactly as pyoti.sparse does (a tuple is a list of bases), or a rawdir.

    Parameters
    ----------
    direction : object
        Base label, list or tuple of bases (including exponent pairs such as [[1, 2]]), or a
        rawdir holding a raw (index, order) pair.

    Returns
    -------
    tuple
        Global direction index and order.
    """

    cdef object pair
    cdef list expanded

    # A raw (index, order) pair was validated when the rawdir was built.
    if isinstance(direction, rawdir):

        return direction.index, direction.order

    # end if

    expanded = _expand_direction(direction)

    if len(expanded) > 255 or any(base < 1 or base > 65535 for base in expanded):

        raise ValueError("direction order or basis label out of range")

    # end if

    pair = (_builtins.sum(comb(base - 1 + i, i + 1) for i, base in enumerate(expanded)),
            len(expanded))

    if not (0 <= pair[0] <= 2**64 - 1):

        raise ValueError("direction index out of range")

    # end if

    return int(pair[0]), int(pair[1])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef list _bases(object bases):
    """
    Validate sorted active base labels without silently changing their order.

    Parameters
    ----------
    bases : object
        Iterable of distinct one-based global base labels.

    Returns
    -------
    list
        Validated labels.
    """

    cdef list labels = list(bases)

    if len(labels) > 65535 or any(not isinstance(x, int) or x < 1 or x > 65535
                                 for x in labels):

        raise ValueError("bases must contain labels from 1 through 65535")

    # end if

    if labels != sorted(set(labels)):

        raise ValueError("bases must be strictly increasing and unique")

    # end if

    return labels

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _status(str operation, int status) except *:
    """
    Translate native linear algebra statuses into Python exceptions.

    Parameters
    ----------
    operation : str
        Name of the failing operation.
    status : int
        Native LAPACK or OTI error code.
    """

    if status == 0:

        return

    elif status > 0:

        raise np.linalg.LinAlgError("{}: singular real part at pivot {}".format(
            operation, status))

    elif status == OTI_LINALG_ERR_SIZE:

        raise ValueError("{}: incompatible shape or LAPACK dimension overflow".format(operation))

    elif status == OTI_LINALG_ERR_MEMORY:

        raise MemoryError("{}: allocation failed".format(operation))

    elif status == OTI_LINALG_ERR_PIVOT:

        raise ValueError("{}: invalid pivot index".format(operation))

    # end if

    raise RuntimeError("{}: native status {}".format(operation, status))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def imdir(hum_dir):
    """
    Resolve a human direction into its raw global pair, as ``pyoti.sparse.imdir`` does.

    Parameters
    ----------
    hum_dir : int or list or tuple or rawdir
        Direction in any pyoti.sparse format, or a rawdir.

    Returns
    -------
    list
        Global direction index and order, ``[index, order]``.
    """

    cdef tuple pair = _direction(hum_dir)
    return [pair[0], pair[1]]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef double _deriv_factor(uint64_t index, ord_t order):
    """
    Return the factor that turns a coefficient into a derivative (product of exponent factorials).

    Parameters
    ----------
    index : int
        Global direction index within its order.
    order : int
        Direction order.

    Returns
    -------
    float
        Product over the bases of the direction of the factorial of their exponent.
    """

    cdef double result = 1.0
    cdef int run = 0
    cdef object previous = None

    for label in _unrank(index, order):

        if label == previous:

            run += 1

        else:

            run = 1
            previous = label

        # end if

        result *= run

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _soa_blocks(oarrss value):
    """
    Return all coefficient blocks of a SoA array as one writable (nblocks, size) NumPy view.

    The view keeps the array alive. Growing the array afterwards may reallocate its buffer and
    invalidates outstanding views.

    Parameters
    ----------
    value : oarrss
        Source array.

    Returns
    -------
    numpy.ndarray
        Shape (1 + number of imaginary directions, nrows * ncols), sharing native memory.
    """

    cdef np.npy_intp dims[2]
    cdef np.ndarray flat
    cdef uint64_t nblocks = 1 + sshelp_ndir_total(value.arr.nbases, value.arr.trc_order)

    if value.arr.size == 0 or value.arr.p_data == NULL:

        return np.zeros((nblocks, value.arr.size), dtype=np.float64)

    # end if

    dims[0] = nblocks
    dims[1] = value.arr.size
    flat = np.PyArray_SimpleNewFromData(2, dims, np.NPY_DOUBLE, <void *>value.arr.p_data)
    np.set_array_base(flat, value)
    return flat

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _base_positions(const bases_t *big, bases_t nbig, const bases_t *small, bases_t nsmall):
    """
    Locate every base of a sorted subset inside a sorted superset.

    Parameters
    ----------
    big : bases_t *
        Sorted superset labels.
    nbig : int
        Superset size.
    small : bases_t *
        Sorted subset labels; every one must appear in the superset.
    nsmall : int
        Subset size.

    Returns
    -------
    numpy.ndarray
        uint16 positions of the subset labels inside the superset.
    """

    cdef np.ndarray[np.uint16_t, ndim=1] pos = np.zeros(nsmall, dtype=np.uint16)
    cdef bases_t i, j = 0

    for i in range(nsmall):

        while j < nbig and big[j] < small[i]:

            j += 1

        # end while

        pos[i] = j

    # end for

    return pos

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _raise_soa_order(oarrss value, ord_t order) except *:
    """
    Raise the truncation order of a SoA array in place, zero-extending every entry.

    Parameters
    ----------
    value : oarrss
        Array to grow.
    order : int
        Requested truncation order; nothing happens when the array already has it.
    """

    if order > value.arr.trc_order:

        oarrss_reserve(&value.arr, value.arr.cap_bases, value.arr.nrows, value.arr.ncols, order)

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _assign_out(object out, object result):
    """
    Move a freshly computed result into a caller-provided ``out`` holder.

    The native structures of both objects are swapped, so ``out`` keeps its identity and takes the
    result; the temporary result releases the old buffers.

    Parameters
    ----------
    out : ssotinum or oarrss or arrss
        Result holder. Views of its old buffers become invalid.
    result : ssotinum or oarrss or arrss
        Computed result.

    Returns
    -------
    ssotinum or oarrss or arrss
        The holder ``out``.
    """

    cdef ssotinum_t stmp
    cdef oarrss_t atmp
    cdef arrss_t btmp

    if isinstance(out, ssotinum) and isinstance(result, ssotinum):

        stmp = (<ssotinum>out).num
        (<ssotinum>out).num = (<ssotinum>result).num
        (<ssotinum>result).num = stmp
        return out

    # end if

    if isinstance(out, oarrss) and isinstance(result, arrss):

        result = result.to_soa()

    elif isinstance(out, arrss) and isinstance(result, oarrss):

        result = result.to_aos()

    # end if

    if isinstance(out, oarrss) and isinstance(result, oarrss):

        if out.shape != result.shape:

            raise ValueError("out has shape {}, expected {}".format(out.shape, result.shape))

        # end if

        atmp = (<oarrss>out).arr
        (<oarrss>out).arr = (<oarrss>result).arr
        (<oarrss>result).arr = atmp
        return out

    # end if

    if isinstance(out, arrss) and isinstance(result, arrss):

        if out.shape != result.shape:

            raise ValueError("out has shape {}, expected {}".format(out.shape, result.shape))

        # end if

        btmp = (<arrss>out).arr
        (<arrss>out).arr = (<arrss>result).arr
        (<arrss>result).arr = btmp
        return out

    # end if

    raise TypeError("out must be a semi-sparse holder of the same kind as the result")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _finish(object result, object out):
    """
    Return a result, or store it in ``out`` when a holder was given.

    Parameters
    ----------
    result : object
        Computed result.
    out : object
        Optional holder.

    Returns
    -------
    object
        ``result`` when ``out`` is None, otherwise None (the result went into ``out``).
    """

    if out is None:

        return result

    # end if

    if isinstance(out, _ssfe) or isinstance(result, _ssfe):

        _fe_store(result, out)
        return None

    # end if

    _assign_out(out, result)
    return None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _process_shape(object shape):
    """
    Turn a shape argument into (rows, columns) the way pyoti.sparse does; an int is a column.

    Parameters
    ----------
    shape : int or tuple of int
        Length of a column vector, or one or two dimensions.

    Returns
    -------
    tuple
        Number of rows and columns.
    """

    cdef object dims

    if isinstance(shape, (int, np.integer)):

        dims = (int(shape), 1)

    elif len(shape) == 1:

        dims = (int(shape[0]), 1)

    elif len(shape) == 2:

        dims = (int(shape[0]), int(shape[1]))

    else:

        raise ValueError("Can't create a matrix with more than 2 dimensions.")

    # end if

    if dims[0] < 0 or dims[1] < 0:

        raise ValueError("shape must contain nonnegative rows and columns")

    # end if

    return dims

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef ssotinum _as_scalar(object value, ord_t order):
    """
    Convert a real, sparse scalar or semi-sparse scalar into an ssotinum.

    Parameters
    ----------
    value : float or sotinum or ssotinum
        Source value.
    order : int
        Truncation order used when ``value`` is real.

    Returns
    -------
    ssotinum
        The scalar itself when it already is one, otherwise a new scalar.
    """

    if isinstance(value, ssotinum):

        return value

    # end if

    return ssotinum(value, order=order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef ssotinum _soa_sum_all(oarrss value):
    """
    Add every element of a SoA array into one semi-sparse scalar.

    Parameters
    ----------
    value : oarrss
        Array to reduce.

    Returns
    -------
    ssotinum
        Sum of all elements, over the array's active set.
    """

    cdef np.ndarray[np.float64_t, ndim=1] sums = _soa_blocks(value).sum(axis=1)
    cdef ssotinum_t total = ssoti_create_empty(value.arr.p_bases, value.arr.nbases,
                                               value.arr.trc_order)
    cdef ndir_t i
    cdef ndir_t nimag = sshelp_ndir_total(value.arr.nbases, value.arr.trc_order)

    total.re = sums[0]

    for i in range(nimag):

        total.p_im[i] = sums[i + 1]

    # end for

    total.act_order = value.arr.act_order
    return ssotinum.wrap(total)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef ssotinum _extract_scalar(ssotinum value, uint64_t index, ord_t order, bint deriv):
    """
    Collect the coefficients of a scalar that are multiples of a direction.

    Every direction ``d + r`` of the scalar becomes direction ``r`` of the result, so the result has
    the truncation order of the scalar minus ``order``. With ``deriv`` the coefficients are scaled
    so that the result holds the derivatives of the scalar along ``d + r`` divided by those of
    ``r``, like ``pyoti.sparse``.

    Parameters
    ----------
    value : ssotinum
        Source scalar.
    index : int
        Global index of the direction ``d``.
    order : int
        Order of the direction ``d``.
    deriv : bool
        Scale the coefficients as derivatives instead of raw coefficients.

    Returns
    -------
    ssotinum
        Extracted scalar.
    """

    cdef ssotinum_t *num = &value.num
    cdef bases_t k = num.nbases
    cdef ssotinum_t res
    cdef list labels
    cdef bases_t *dirs
    cdef bases_t *residual
    cdef int *counts
    cdef int *dcounts
    cdef sshelp_rank_tab_t tab
    cdef ord_t q, r, t
    cdef ndir_t nq, j, off
    cdef bases_t u
    cdef int position
    cdef bint found, divisible
    cdef int used
    cdef double coef, factor_full, factor_res

    if order == 0:

        return ssotinum.wrap(ssoti_copy(num))

    # end if

    if order > num.act_order:

        return ssotinum.wrap(ssoti_create_r(0.0, 0))

    # end if

    res = ssoti_create_empty(num.p_bases, k, num.trc_order - order)
    res.act_order = num.act_order - order
    dcounts = <int *>calloc(k + 1, sizeof(int))
    counts = <int *>calloc(k + 1, sizeof(int))
    residual = <bases_t *>calloc(num.trc_order + 1, sizeof(bases_t))
    tab.p_c = NULL
    tab.k = 0
    tab.n = 0
    found = True
    labels = _unrank(index, order)

    for label in labels:

        position = k

        for u in range(k):

            if num.p_bases[u] == label:

                position = u
                break

            # end if

        # end for

        if position == k:

            found = False
            break

        # end if

        dcounts[position] += 1

    # end for

    try:

        if not found:

            res.act_order = 0
            return ssotinum.wrap(res)

        # end if

        res.re = ssoti_get_item(index, order, num)

        if deriv:

            res.re *= _deriv_factor(index, order)

        # end if

        if sshelp_rank_tab_init(&tab, k, num.trc_order) != 0:

            raise MemoryError("extract: could not build the rank table")

        # end if

        for q in range(order + 1, num.act_order + 1):

            nq = sshelp_ndir_order(k, q)
            off = sshelp_order_offset(k, q)
            r = q - order
            dirs = <bases_t *>malloc(<size_t>nq * q * sizeof(bases_t))
            sshelp_local_dirs(k, q, dirs)

            for j in range(nq):

                coef = num.p_im[off + j]

                if coef == 0.0:

                    continue

                # end if

                for u in range(k):

                    counts[u] = 0

                # end for

                for t in range(q):

                    counts[dirs[j * q + t]] += 1

                # end for

                divisible = True

                for u in range(k):

                    if counts[u] < dcounts[u]:

                        divisible = False
                        break

                    # end if

                # end for

                if not divisible:

                    continue

                # end if

                used = 0
                factor_full = 1.0
                factor_res = 1.0

                for u in range(k):

                    for t in range(counts[u]):

                        factor_full *= (t + 1)

                    # end for

                    for t in range(counts[u] - dcounts[u]):

                        residual[used] = u
                        used += 1
                        factor_res *= (t + 1)

                    # end for

                # end for

                if deriv:

                    coef *= factor_full / factor_res

                # end if

                res.p_im[sshelp_order_offset(k, r) + sshelp_rank(residual, r, &tab)] = coef

            # end for

            free(dirs)

        # end for

        return ssotinum.wrap(res)

    finally:

        free(dcounts)
        free(counts)
        free(residual)
        sshelp_rank_tab_free(&tab)

    # end try

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _raw_key(object key):
    """
    Read a raw (index, order) direction key the way ``pyoti.sparse`` scalars do.

    Parameters
    ----------
    key : list or tuple or rawdir
        Global direction index and order, or a rawdir.

    Returns
    -------
    tuple
        Global index and order.
    """

    if isinstance(key, rawdir):

        return key.index, key.order

    # end if

    if isinstance(key, (list, tuple)) and len(key) == 2 and all(
        isinstance(x, (int, np.integer)) for x in key
    ):

        return rawdir(key[0], key[1]).index, rawdir(key[0], key[1]).order

    # end if

    raise TypeError("expected a raw direction [index, order] or a rawdir")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def set_printoptions(float_format="g", terms_print=4):
    """
    Set how OTI numbers are printed, with the arguments of ``pyoti.sparse.set_printoptions``.

    Semi-sparse numbers and arrays print through their sparse representation, so this forwards to
    the sparse setting (and changes it for ``pyoti.sparse`` as well). Call it with no arguments to
    restore the defaults.

    Parameters
    ----------
    float_format : str
        Format specification of the coefficients.
    terms_print : int
        Number of terms printed; -1 prints all of them.
    """

    _sparse_set_printoptions(float_format, terms_print)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef str _scalar_text(ssotinum value):
    """
    Format a scalar the way ``str(pyoti.sparse.sotinum)`` does, with plain Python integers.

    The float format and the number of printed terms are those of ``set_printoptions``; terms are
    the nonzero coefficients in increasing order and direction, and the real part counts as one.

    Parameters
    ----------
    value : ssotinum
        Scalar to format.

    Returns
    -------
    str
        Text such as ``2 + 1 * e([1]) + 3 * e([[1,2],3])``.
    """

    cdef ssotinum_t *num = &value.num
    cdef str float_format = _sparse_module.floatFormat
    cdef object limit = _sparse_module.termsPrint
    cdef bases_t local[256]
    cdef list terms = []
    cdef list labels
    cdef ord_t p, u
    cdef ndir_t j, size, offset
    cdef double coefficient
    cdef int printed = 0
    cdef int position
    cdef bint dots = False
    cdef str body = ""
    cdef str text
    cdef object base
    cdef object previous
    cdef int run

    if num.re != 0:

        body += ("%" + float_format) % num.re
        printed += 1

    # end if

    for p in range(1, num.act_order + 1):

        size = sshelp_ndir_order(num.nbases, p)
        offset = sshelp_order_offset(num.nbases, p)

        for j in range(size):

            if num.p_im[offset + j] != 0.0:

                terms.append((p, j, num.p_im[offset + j]))

            # end if

        # end for

    # end for

    for position in range(len(terms)):

        p, j, coefficient = terms[position]
        sshelp_unrank(j, p, local)
        labels = []
        previous = None
        run = 0

        for u in range(p):

            base = int(num.p_bases[local[u]])

            if base == previous:

                run += 1
                labels[len(labels) - 1] = [base, run]

            else:

                run = 1
                previous = base
                labels.append(base)

            # end if

        # end for

        text = ("%+" + float_format) % coefficient
        body += " " + text[0] + " " + text[1:] + " * e(" + str(labels).replace(" ", "") + ")"
        printed += 1

        if printed == limit:

            dots = position < len(terms) - 1
            break

        # end if

    # end for

    if dots:

        body += " + ... "

    # end if

    if printed == 0:

        body += ("%" + float_format) % num.re

    # end if

    return body

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef str _array_text(object value):
    """
    Format an array the way ``str(pyoti.sparse.matso)`` does: one line per element, by columns.

    Parameters
    ----------
    value : oarrss or arrss
        Array to format.

    Returns
    -------
    str
        Text with the header ``matso< shape: (r, c),`` and ``(i,j) element`` lines.
    """

    cdef uint64_t nrows = value.shape[0]
    cdef uint64_t ncols = value.shape[1]
    cdef uint64_t i, j
    cdef str out = "matso< shape: " + str(value.shape) + ", \n"

    for j in range(ncols):

        out += " - Column " + str(j) + "\n"

        for i in range(nrows):

            out += "({0:d},{1:d}) ".format(i, j) + str(value[i, j]) + "\n"

        # end for

    # end for

    return out + ">"

# end function
# --------------------------------------------------------------------------------------------------------
