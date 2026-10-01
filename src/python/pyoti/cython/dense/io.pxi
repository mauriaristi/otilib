# Save and read: binary files of dense scalars and arrays (magic 0x93 'O' 'T' 'D'; format:
# include/oti/dense/io/io.h). Owner: WP9.

import os as _os


# ********************************************************************************************************
def _io_path(filename):
    """
    Encode a file name for the C layer.

    Parameters
    ----------
    filename : str or bytes or os.PathLike
        Path of the file.

    Returns
    -------
    bytes
        The path in the file system encoding, without a terminating NUL.

    Raises
    ------
    ValueError
        If the name is empty or contains a NUL character.
    """

    path = _os.fsencode(filename)

    if len(path) == 0:

        raise ValueError("the file name is empty")

    # end if

    if b"\0" in path:

        raise ValueError("the file name contains a NUL character")

    # end if

    return path

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _io_name(filename):
    """
    Printable form of a file name for exception messages.

    Parameters
    ----------
    filename : str or bytes or os.PathLike
        Path of the file.

    Returns
    -------
    str
        The decoded name, with undecodable bytes (lone surrogates) shown as backslash escapes, so
        that printing the message cannot raise UnicodeEncodeError.
    """

    return _os.fsdecode(filename).encode("utf-8", "backslashreplace").decode("utf-8")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _io_check_read(filename):
    """
    Check that a path names a readable regular file, raising the matching exception otherwise.

    Parameters
    ----------
    filename : str or bytes or os.PathLike
        Path of the file.

    Raises
    ------
    IsADirectoryError
        If the path is a directory.
    FileNotFoundError
        If nothing exists at the path.
    ValueError
        If the path is not a regular file (a FIFO, a device, ...).
    PermissionError
        If the file cannot be read.
    """

    name = _os.fsdecode(filename)

    if _os.path.isdir(name):

        raise IsADirectoryError("'%s' is a directory" % _io_name(filename))

    # end if

    if not _os.path.exists(name):

        raise FileNotFoundError("no such file: '%s'" % _io_name(filename))

    # end if

    if not _os.path.isfile(name):

        raise ValueError("not a regular file: '%s'" % _io_name(filename))

    # end if

    if not _os.access(name, _os.R_OK):

        raise PermissionError("permission denied: '%s'" % _io_name(filename))

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _io_check_write(filename):
    """
    Check that a path can receive a new regular file, raising the matching exception otherwise.

    Parameters
    ----------
    filename : str or bytes or os.PathLike
        Path of the file to create or overwrite.

    Raises
    ------
    IsADirectoryError
        If the path is a directory.
    FileNotFoundError
        If the parent directory does not exist.
    ValueError
        If the path exists and is not a regular file (never written over, nor removed on failure).
    PermissionError
        If the file or its directory is not writable.
    """

    name = _os.fsdecode(filename)
    parent = _os.path.dirname(_os.path.abspath(name))

    if _os.path.isdir(name):

        raise IsADirectoryError("'%s' is a directory" % _io_name(filename))

    # end if

    if not _os.path.isdir(parent):

        raise FileNotFoundError("no such directory: '%s'" % _io_name(parent))

    # end if

    if _os.path.lexists(name):

        if not _os.path.isfile(name):

            raise ValueError("not a regular file: '%s'" % _io_name(filename))

        # end if

        if not _os.access(name, _os.W_OK):

            raise PermissionError("permission denied: '%s'" % _io_name(filename))

        # end if

    elif not _os.access(parent, _os.W_OK | _os.X_OK):

        raise PermissionError("permission denied: '%s'" % _io_name(filename))

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _io_other_kind(path):
    """
    Name the OTI module that wrote a file with another magic, if any.

    Parameters
    ----------
    path : bytes
        Encoded path of the file.

    Returns
    -------
    str or None
        ``"pyoti.semisparse"`` or ``"pyoti.sparse"`` when the file starts with their magic,
        otherwise None.
    """

    try:

        with open(path, "rb") as handle:

            magic = handle.read(4)

        # end with

    except OSError:

        return None

    # end try

    if magic == b"\x93OTS":

        return "pyoti.semisparse"

    # end if

    if magic == b"\x93OTI":

        return "pyoti.sparse"

    # end if

    return None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _io_raise(status, filename, reading):
    """
    Raise the Python exception that matches a native save/read status.

    Parameters
    ----------
    status : int
        A nonzero ``DNIO_ERR_*`` code.
    filename : str or bytes or os.PathLike
        The file involved, for the message.
    reading : bool
        True when reading, so that a missing file raises ``FileNotFoundError``.

    Raises
    ------
    FileNotFoundError
        Reading a file that does not exist.
    MemoryError
        An allocation failed while reading.
    OSError
        The file cannot be opened, read or written.
    ValueError
        The file is not a valid dense file (a semi-sparse or sparse file included), holds another
        type, or the object cannot be saved.
    """

    message = (<bytes> dnio_strerror(status)).decode()
    name = _io_name(filename)

    if status == DNIO_ERR_OPEN:

        if reading and not _os.path.exists(_os.fsdecode(filename)):

            raise FileNotFoundError("no such file: '%s'" % name)

        # end if

        raise OSError("%s: '%s'" % (message, name))

    # end if

    if status == DNIO_ERR_IO:

        raise OSError("%s: '%s'" % (message, name))

    # end if

    if status == DNIO_ERR_MEMORY:

        raise MemoryError("%s: '%s'" % (message, name))

    # end if

    if status == DNIO_ERR_MAGIC:

        other = _io_other_kind(_os.fsencode(filename))

        if other is not None:

            raise ValueError("%s: '%s' was written by %s; read it with %s.read" % (
                message, name, other, other))

        # end if

    # end if

    raise ValueError("%s: '%s'" % (message, name))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def save(arr, filename):
    """
    Save a dense scalar or array to a binary file.

    The file keeps everything needed to rebuild the object exactly: type, shape, truncation and
    active orders, nact (including trailing bases whose coefficients are zero) and every
    coefficient. Read it back with ``read``.

    Parameters
    ----------
    arr : otinum or arro or omat
        The object to save.
    filename : str or os.PathLike
        Path of the file to create; an existing file is overwritten.

    Raises
    ------
    TypeError
        If ``arr`` is not a dense scalar or array.
    ValueError
        If the file name is empty, the path exists and is not a regular file, or the object cannot
        be represented in the format.
    IsADirectoryError
        If the path is a directory.
    FileNotFoundError
        If the parent directory does not exist.
    PermissionError
        If the file or its directory is not writable.
    OSError
        If the file cannot be created or written (a partial file is removed).

    Examples
    --------
    >>> x = e([1, 2], order=2)
    >>> save(x, "x.doti")
    >>> read("x.doti").nact
    2
    """

    cdef bytes path = _io_path(filename)
    cdef int status

    if not isinstance(arr, (otinum, omat, arro)):

        raise TypeError("cannot save an object of type %s" % type(arr).__name__)

    # end if

    _io_check_write(filename)

    if isinstance(arr, otinum):

        status = oti_save(path, &(<otinum> arr).num)

    elif isinstance(arr, omat):

        status = oarr_save(path, &(<omat> arr).arr)

    else:

        status = arro_save(path, &(<arro> arr).arr)

    # end if

    if status != DNIO_OK:

        _io_raise(status, filename, False)

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def read(filename):
    """
    Read a dense scalar or array saved with ``save``.

    Parameters
    ----------
    filename : str or os.PathLike
        Path of the file.

    Returns
    -------
    otinum or arro or omat
        The object the file holds, with the same type, shape, orders, nact and coefficients that
        were saved.

    Raises
    ------
    FileNotFoundError
        If the file does not exist.
    IsADirectoryError
        If the path is a directory.
    ValueError
        If the file name is empty, the path is not a regular file, or the file is not a dense file
        (for example a semi-sparse or sparse one), is truncated or corrupt.
    PermissionError
        If the file cannot be read.
    OSError
        If the file cannot be opened or read.
    MemoryError
        If the object cannot be allocated.

    Examples
    --------
    >>> x = read("x.doti")
    >>> x.order
    2
    """

    cdef bytes path = _io_path(filename)
    cdef dnio_info_t info
    cdef otinum_t num = oti_init()
    cdef arro_t aos = arro_init()
    cdef oarr_t soa = oarr_init()
    cdef int status

    _io_check_read(filename)
    status = dnio_peek(path, &info)

    if status != DNIO_OK:

        _io_raise(status, filename, True)

    # end if

    if info.type == DNIO_TYPE_SCALAR:

        status = oti_read(path, &num)

        if status != DNIO_OK:

            oti_free(&num)
            _io_raise(status, filename, True)

        # end if

        return otinum.wrap(num)

    # end if

    if info.type == DNIO_TYPE_AOS:

        status = arro_read(path, &aos)

        if status != DNIO_OK:

            arro_free(&aos)
            _io_raise(status, filename, True)

        # end if

        return arro.wrap(aos)

    # end if

    status = oarr_read(path, &soa)

    if status != DNIO_OK:

        oarr_free(&soa)
        _io_raise(status, filename, True)

    # end if

    return omat.wrap(soa)

# end function
# --------------------------------------------------------------------------------------------------------
