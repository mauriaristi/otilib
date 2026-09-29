
#***************************************************************************************************
def get_active_bases(obj_in):
  """

  """
  global dhl

  cdef bases_t  size       = dhl.p_dh[0].Nbasis
  cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
  cdef matso SO
  cdef sotinum so
  cdef uint64_t i
  
  # Initialize all elements as zero (deactivated)
  for i in range(size):
    bases_list[i]=0
  # end for 
  
  tobj_in = type(obj_in)

  if tobj_in is list:

    for obj in obj_in:
      
      tobj = type(obj)

      if tobj is matso:

        SO = obj
        arrso_get_active_bases( &SO.arr, bases_list, dhl)

      elif tobj is sotinum:
        
        so = obj
        soti_get_active_bases( &so.num, bases_list, dhl) 

      else:

        raise ValueError("Input should be list of sotinum or matso.") 

      # end if 

    # end for

  elif tobj_in is matso:

    SO = obj_in
    arrso_get_active_bases( &SO.arr, bases_list, dhl)

  elif tobj_in is sotinum:
    
    so = obj_in
    soti_get_active_bases( &so.num, bases_list, dhl)        

  else:

    raise ValueError("Input should be list of sotinum and/or matso.") 

  # end if 
  
  res = []

  for i in range(size):

    if bases_list[i] == 1:
    
      res.append(i+1)

    # end if 

  # end for 

  return res

#---------------------------------------------------------------------------------------------------



#***************************************************************************************************
def _io_filename( filename ):
  """
  Encode a file name for the C layer.

  INPUTS:
  - filename: str, bytes or os.PathLike with the name of the file.

  OUTPUTS:
  - path: bytes with the name in the file system encoding.

  Raises ValueError if the name is empty or has a NUL character.

  """
  import os as _os

  path = _os.fsencode(filename)

  if len(path) == 0:

    raise ValueError("the file name is empty")

  # end if

  if b"\0" in path:

    raise ValueError("the file name contains a NUL character")

  # end if

  return path

#---------------------------------------------------------------------------------------------------


#***************************************************************************************************
def save( matso arr, filename ): 
  """
  PURPOSE: Export array into a binary proprietary format.

  USAGE:
  >>> save( arr, filename )

  INPUTS:
  - arr: matso array to be saved.
  - filename: String object with the name of file to be used. 

  """
  global dhl
  
  cdef bytes path = _io_filename( filename )

  # A bytes object converts to the char* argument, with its terminating '\0'.
  arrso_save( path, &arr.arr, dhl )

#---------------------------------------------------------------------------------------------------

#***************************************************************************************************
def read( filename ): 
  """
  PURPOSE: Load array from a binary format (See documentation of binary format).

  USAGE:
  >>> load( filename )

  INPUTS:
  
  - filename: String object with the name of file to be used. 

  OUTPUTS:
  - arr: matso array loaded from memory.

  Raises FileNotFoundError if the file does not exist and ValueError if it is not a saved matso array
  (the C reader would exit the interpreter on both).

  """
  import os as _os
  import sys as _sys
  global dhl
  
  cdef bytes path = _io_filename( filename )
  cdef arrso_t res
  cdef uint64_t mem_size

  if not _os.path.isfile( _os.fsdecode(filename) ):

    raise FileNotFoundError("no such file: '%s'" % _os.fsdecode(filename))

  # end if

  # Checks the C reader would answer with exit(): 64-byte header, magic, array format, data size.
  with open( path, "rb" ) as handle:

    header = handle.read(64)

  # end with

  if len(header) < 64 or header[:4] != b"\x93OTI":

    raise ValueError("not an OTI array file: '%s'" % _os.fsdecode(filename))

  # end if

  if header[6] != 21:

    raise ValueError("not a matso array file (format %d): '%s'" % ( header[6], _os.fsdecode(filename) ))

  # end if

  mem_size = int.from_bytes( header[8:16], _sys.byteorder )

  if mem_size != _os.path.getsize( path ) - 64:

    raise ValueError("truncated or corrupt matso file: '%s'" % _os.fsdecode(filename))

  # end if

  res = arrso_read( path, dhl )

  return matso.create(&res)

#---------------------------------------------------------------------------------------------------