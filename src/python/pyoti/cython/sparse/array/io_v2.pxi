#-----------------------------------------------------------------------------------------------------
# 'OTI' (sparse array) files, version 2 (PLAN-ndarray-contracts.md 11.12; PLAN-ndarray.md Phase 7b).
#
# The frozen C writer / reader (arrso_save / arrso_read, version 1) are not used for the 2.0.0 files: the
# C reader trusts the header and the payload (it answers corrupt files with exit() or a crash) and cannot
# carry a 1-D or 0-D logical shape. This is a Cython encoder / decoder over the element accessors of the C
# layer (soti_get_memsize_save / soti_save_to_mem / soti_read_from_mem_to). The payload (one record per
# element, row-major over the 2-D struct) is byte for byte the version-1 payload, so the decoder
# reads both versions.
#
# Header (the one v2 header rule, PLAN-ndarray-contracts.md 11.12; little endian like every host).
# The 64 bytes keep the version-1 fields; the slots of the rule that the v1 header already uses move
# (build-orch/w4-header-requests.md, py-1):
#
#    0   4   magic 0x93 'O' 'T' 'I'
#    4   2   format version (uint16): 1 or 2
#    6   1   format: 21 (array of OTI numbers)
#    7   1   zero (both versions)
#    8   8   payload size in bytes (uint64)
#   16   8   nrows of the 2-D struct (uint64)
#   24   8   ncols of the 2-D struct (uint64)
#   40   4   version 2: ndim of the logical shape (uint32; zero in v1)
#   44   1   layout flag, version 2: 1 = F, 2 = C (zero in v1; byte 9 is inside the payload size, so
#            the flag takes byte 44, as in 'OTS')
#   45  19   reserved (zero)
#   64  8*n  version 2: the extents S[0 .. ndim-1] (uint64)
#
# Header length = 64 + 8 * ndim; the file is exactly header + payload bytes long. A 1-D (n,) array is
# stored n x 1 and a 0-D () array 1 x 1, as in memory. A version-1 file has no logical shape: it reads
# back with the 2-D shape it stored (a 1.x (n, 1) column never turns into (n,)). The elements are the
# row-major elements of the 2-D struct, so the writer sets the layout flag to 2 (C); the reader accepts 1
# (F) only for shapes with at most one extent above 1, where F and C order are the same.
#
# One record: re (float64), trc_order (uint8), act_order (uint8), then for each order 1..act_order: nnz
# (uint64), nnz coefficients (float64) and nnz imaginary directions (uint64).
#-----------------------------------------------------------------------------------------------------

cdef extern from "oti/oti.h" nogil:

  void*     soti_read_from_mem_to( void* mem,       sotinum_t* dst, dhelpl_t helper)
  void      soti_save_to_mem(      sotinum_t* num,  void* mem,      dhelpl_t helper)
  uint64_t  soti_get_memsize_save( sotinum_t* num,                  dhelpl_t helper)


#*****************************************************************************************************
cdef uint64_t _io_u64(const unsigned char* p):
  """
  PURPOSE:  A little endian uint64 from 8 bytes (no alignment assumed).
  """
  #***************************************************************************************************

  cdef uint64_t value
  cdef int k

  value = 0

  for k in range(8):

    value |= (<uint64_t>p[k]) << (8*k)

  # end for

  return value

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef void _io_put_u64(unsigned char* p, uint64_t value):
  """
  PURPOSE:  Write a uint64 as 8 little endian bytes.
  """
  #***************************************************************************************************

  cdef int k

  for k in range(8):

    p[k] = <unsigned char>((value >> (8*k)) & 0xFF)

  # end for

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def _io_write_v2( matso arr, path ):
  """
  PURPOSE:  Write a matso as a version-2 'OTI' file.

  INPUTS:
    - arr:  matso array to write.
    - path: file name (str, bytes or path-like).
  """
  #***************************************************************************************************

  global dhl

  cdef uint64_t i, mem_size = 0, off, hlen
  cdef bytearray raw
  cdef unsigned char[::1] buf
  cdef int ndim = 2 - arr._lk
  cdef int k
  cdef object shape = arr.shape

  for i in range(arr.arr.size):

    mem_size += soti_get_memsize_save( &arr.arr.p_data[i], dhl)

  # end for

  hlen = 64 + 8*ndim
  raw = bytearray(hlen + mem_size)
  buf = raw

  buf[0] = 0x93
  buf[1] = ord('O')
  buf[2] = ord('T')
  buf[3] = ord('I')
  buf[4] = 2                  # version 2 (uint16, little endian)
  buf[5] = 0
  buf[6] = 21                 # array of OTI numbers
  buf[44] = 2                 # layout flag: 2 = C order (the row-major elements of the 2-D struct)

  _io_put_u64(&buf[8],  mem_size)
  _io_put_u64(&buf[16], arr.arr.nrows)
  _io_put_u64(&buf[24], arr.arr.ncols)
  buf[40] = ndim              # ndim, uint32 at 40-43 (bytes 41-63 stay zero)

  for k in range(ndim):

    _io_put_u64(&buf[64 + 8*k], shape[k])

  # end for

  off = hlen

  for i in range(arr.arr.size):

    soti_save_to_mem( &arr.arr.p_data[i], <void*>&buf[off], dhl)
    off += soti_get_memsize_save( &arr.arr.p_data[i], dhl)

  # end for

  with open(path, "wb") as handle:

    handle.write(raw)

  # end with

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def _io_read_any( path, str display ):
  """
  PURPOSE:  Read a version-1 or version-2 'OTI' file into a matso, validating the header against the file
            length and every record against the bytes that are left (a corrupt file raises ValueError, it
            never reads outside the buffer or asks for a huge allocation).

  INPUTS:
    - path:    file name (bytes or str path).
    - display: name used in the messages.
  """
  #***************************************************************************************************

  global dhl

  cdef bytearray raw
  cdef unsigned char[::1] buf
  cdef uint64_t size, end, off, nrows, ncols, mem_size, count, i, nnz, idx, prev, ndim, hlen
  cdef uint64_t ext0 = 0, ext1 = 0
  cdef int k
  cdef uint64_t cnt, o, ndirs
  cdef uint8_t trc, act, ordi
  cdef int version
  cdef arrso_t res
  cdef matso out
  cdef unsigned char* tail

  with open(path, "rb") as handle:

    raw = bytearray(handle.read())

  # end with

  size = len(raw)

  if size < 64 or raw[0] != 0x93 or raw[1] != ord('O') or raw[2] != ord('T') or raw[3] != ord('I'):

    raise ValueError("not an OTI array file: '%s'" % display)

  # end if

  buf = raw
  version = buf[4] | (buf[5] << 8)

  if version != 1 and version != 2:

    raise ValueError("unsupported OTI file version %d: '%s'" % (version, display))

  # end if

  if buf[6] != 21:

    raise ValueError("not a matso array file (format %d): '%s'" % (buf[6], display))

  # end if

  hlen = 64
  ndim = 2
  out_lk = 0

  if version == 2:

    # The one v2 header rule: ndim uint32 at 40-43, layout flag at 44, bytes 45-63 zero, extents at 64.
    ndim = buf[40] | (buf[41] << 8) | (buf[42] << 16) | ((<uint64_t>buf[43]) << 24)

    # Byte 7 is zero in both versions; bytes 45-63 are reserved.
    if buf[7] != 0:

      raise ValueError("corrupt matso file (header): '%s'" % display)

    # end if

    for k in range(45, 64):

      if buf[k] != 0:

        raise ValueError("corrupt matso file (header): '%s'" % display)

      # end if

    # end for

    if ndim > 2:

      raise ValueError("matso files have at most 2 dimensions (the file has %d): '%s'" % (ndim, display))

    # end if

    hlen = 64 + 8*ndim

    if size < hlen:

      raise ValueError("truncated or corrupt matso file (header): '%s'" % display)

    # end if

    if buf[44] != 1 and buf[44] != 2:

      raise ValueError("unsupported layout flag in matso file: '%s'" % display)

    # end if

    if ndim >= 1:

      ext0 = _io_u64(&buf[64])

    # end if

    if ndim >= 2:

      ext1 = _io_u64(&buf[72])

    # end if

    # F and C order differ only for shapes with two extents above 1.
    if buf[44] == 1 and ndim == 2 and ext0 > 1 and ext1 > 1:

      raise ValueError("unsupported layout flag in matso file (F order): '%s'" % display)

    # end if

  # end if

  mem_size = _io_u64(&buf[8])

  if mem_size != size - hlen:

    raise ValueError("truncated or corrupt matso file: '%s'" % display)

  # end if

  nrows = _io_u64(&buf[16])
  ncols = _io_u64(&buf[24])

  # Every record takes at least 10 bytes: the element count is bounded by the file length. An empty
  # array (a zero extent) has no records; its extents only have to stay sane.
  if nrows > 0xFFFFFFFFFF or ncols > 0xFFFFFFFFFF:

    raise ValueError("corrupt matso file (shape): '%s'" % display)

  # end if

  if nrows != 0 and ncols != 0 and (nrows > mem_size or ncols > (mem_size // 10) // nrows):

    raise ValueError("corrupt matso file (shape): '%s'" % display)

  # end if

  count = nrows * ncols

  if version == 2:

    if ndim == 0 and (nrows != 1 or ncols != 1):

      raise ValueError("corrupt matso file (shape): '%s'" % display)

    elif ndim == 1 and (ncols != 1 or ext0 != nrows):

      raise ValueError("corrupt matso file (shape): '%s'" % display)

    elif ndim == 2 and (ext0 != nrows or ext1 != ncols):

      raise ValueError("corrupt matso file (shape): '%s'" % display)

    # end if

    out_lk = 2 - ndim

  # end if

  # Validate every record before anything is allocated or read.
  off = hlen
  end = size

  for i in range(count):

    if end - off < 10:

      raise ValueError("truncated or corrupt matso file (records): '%s'" % display)

    # end if

    trc = buf[off + 8]
    act = buf[off + 9]
    off += 10

    if trc > dhl.ndh or act > trc:

      raise ValueError("corrupt matso file (orders): '%s'" % display)

    # end if

    for ordi in range(act):

      if end - off < 8:

        raise ValueError("truncated or corrupt matso file (records): '%s'" % display)

      # end if

      nnz = _io_u64(&buf[off])
      off += 8
      ndirs = dhl.p_dh[ordi].Ndir

      if nnz > ndirs or nnz > (end - off) // 16:

        raise ValueError("corrupt matso file (record sizes): '%s'" % display)

      # end if

      # The directions are strictly increasing and inside the helper of this order.
      o = off + 8*nnz
      prev = 0

      for cnt in range(nnz):

        idx = _io_u64(&buf[o + 8*cnt])

        if idx >= ndirs or (cnt > 0 and idx <= prev):

          raise ValueError("corrupt matso file (directions): '%s'" % display)

        # end if

        prev = idx

      # end for

      off += 16*nnz

    # end for

  # end for

  if off != end:

    raise ValueError("truncated or corrupt matso file (trailing bytes): '%s'" % display)

  # end if

  res = arrso_zeros_bases( nrows, ncols, 0, 0, dhl)

  off = hlen

  for i in range(count):

    tail = <unsigned char*>soti_read_from_mem_to( <void*>&buf[off], &res.p_data[i], dhl)
    off  = <uint64_t>(tail - &buf[0])

  # end for

  out = matso.create(&res)
  out._lk = out_lk

  return out

#-----------------------------------------------------------------------------------------------------
