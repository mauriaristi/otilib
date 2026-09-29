# Save and read: binary files of semi-sparse scalars and arrays (format: semisparse/io/io.h).

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
def _io_raise(status, filename, reading):
    """
    Raise the Python exception that matches a native save/read status.

    Parameters
    ----------
    status : int
        A nonzero ``SSIO_ERR_*`` code.
    filename : str or bytes or os.PathLike
        The file involved, for the message.
    reading : bool
        True when reading, so that a missing file raises ``FileNotFoundError``.

    Raises
    ------
    FileNotFoundError
        Reading a file that does not exist.
    OSError
        The file cannot be opened, read or written.
    ValueError
        The file is not a valid semi-sparse file, holds another type, or the object cannot be saved.
    """

    message = (<bytes> ssio_strerror(status)).decode()
    name = _os.fsdecode(filename)

    if status == SSIO_ERR_OPEN:

        if reading and not _os.path.exists(name):

            raise FileNotFoundError("no such file: '%s'" % name)

        # end if

        raise OSError("%s: '%s'" % (message, name))

    # end if

    if status == SSIO_ERR_IO:

        raise OSError("%s: '%s'" % (message, name))

    # end if

    raise ValueError("%s: '%s'" % (message, name))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def save(arr, filename):
    """
    Save a semi-sparse scalar or array to a binary file.

    The file keeps everything needed to rebuild the object exactly: type, shape, truncation and
    active orders, the active bases (including bases whose coefficients are zero) and every
    coefficient. Read it back with ``read``.

    Parameters
    ----------
    arr : ssotinum or arrss or oarrss
        The object to save.
    filename : str or os.PathLike
        Path of the file to create; an existing file is overwritten.

    Raises
    ------
    TypeError
        If ``arr`` is not a semi-sparse scalar or array.
    ValueError
        If the file name is empty, or the object cannot be represented in the format.
    OSError
        If the file cannot be created or written.

    Examples
    --------
    >>> x = e([1, 2], order=2)
    >>> save(x, "x.ssoti")
    >>> read("x.ssoti").active_bases
    (1, 2)
    """

    cdef bytes path = _io_path(filename)
    cdef int status

    if isinstance(arr, ssotinum):

        status = ssoti_save(path, &(<ssotinum> arr).num)

    elif isinstance(arr, oarrss):

        status = oarrss_save(path, &(<oarrss> arr).arr)

    elif isinstance(arr, arrss):

        status = arrss_save(path, &(<arrss> arr).arr)

    else:

        raise TypeError("cannot save an object of type %s" % type(arr).__name__)

    # end if

    if status != SSIO_OK:

        _io_raise(status, filename, False)

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def read(filename):
    """
    Read a semi-sparse scalar or array saved with ``save``.

    Parameters
    ----------
    filename : str or os.PathLike
        Path of the file.

    Returns
    -------
    ssotinum or arrss or oarrss
        The object the file holds, with the same type, shape, orders, active bases and coefficients
        that were saved.

    Raises
    ------
    FileNotFoundError
        If the file does not exist.
    IsADirectoryError
        If the path is a directory.
    ValueError
        If the file name is empty, or the file is not a semi-sparse file, is truncated or corrupt.
    OSError
        If the file cannot be opened or read.

    Examples
    --------
    >>> x = read("x.ssoti")
    >>> x.order
    2
    """

    cdef bytes path = _io_path(filename)
    cdef ssio_info_t info
    cdef ssotinum_t num
    cdef arrss_t aos
    cdef oarrss_t soa
    cdef int status

    if _os.path.isdir(_os.fsdecode(filename)):

        raise IsADirectoryError("'%s' is a directory" % _os.fsdecode(filename))

    # end if

    if not _os.path.isfile(_os.fsdecode(filename)):

        raise FileNotFoundError("no such file: '%s'" % _os.fsdecode(filename))

    # end if

    status = ssio_peek(path, &info)

    if status != SSIO_OK:

        _io_raise(status, filename, True)

    # end if

    if info.type == SSIO_TYPE_SCALAR:

        status = ssoti_read(path, &num)

        if status != SSIO_OK:

            _io_raise(status, filename, True)

        # end if

        return ssotinum.wrap(num)

    # end if

    if info.type == SSIO_TYPE_AOS:

        status = arrss_read(path, &aos)

        if status != SSIO_OK:

            _io_raise(status, filename, True)

        # end if

        return arrss.wrap(aos)

    # end if

    status = oarrss_read(path, &soa)

    if status != SSIO_OK:

        _io_raise(status, filename, True)

    # end if

    return oarrss.wrap(soa)

# end function
# --------------------------------------------------------------------------------------------------------
