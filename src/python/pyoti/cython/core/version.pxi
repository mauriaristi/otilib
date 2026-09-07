
#*****************************************************************************************************
def c_version():
  """
  Returns the version of the compiled OTIlib C library that this extension is linked against.

  The Python-level ``pyoti.__version__`` reports the version of the Python sources, while this
  function reports the version baked into ``liboti`` at compile time. A mismatch between the two
  means the Python package and the native library came from different builds.

  Returns
  -------
  str
      The C library version as a ``"MAJOR.MINOR.PATCH"`` string.

  Examples
  --------
  >>> import pyoti
  >>> pyoti.core.c_version() == pyoti.__version__
  True
  """

  return oti_version().decode('utf-8')

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def c_version_info():
  """
  Returns the version components of the compiled OTIlib C library.

  Returns
  -------
  tuple of int
      The ``(major, minor, patch)`` components of the linked C library version.

  Examples
  --------
  >>> import pyoti
  >>> pyoti.core.c_version_info() == pyoti.__version_info__
  True
  """

  cdef int major, minor, patch

  oti_version_numbers(&major, &minor, &patch)

  return (major, minor, patch)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def c_version_number():
  """
  Returns the compiled OTIlib C library version packed into a single integer.

  The packing matches ``OTI_VERSION_ENCODE()`` in C, ``OTI_VERSION_NUMBER`` in Fortran and
  ``pyoti.version_number()`` in Python, so all bindings can be compared directly.

  Returns
  -------
  int
      The value ``major * 10000 + minor * 100 + patch``.

  Examples
  --------
  >>> import pyoti
  >>> pyoti.core.c_version_number() >= 10100
  True
  """

  return oti_version_number()

#-----------------------------------------------------------------------------------------------------
