
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
  
  cdef char * filename_c 
  cdef int64_t i, nchars

  nchars = len(filename)+1

  filename_c=<char *>malloc(nchars*sizeof(char))
  
  for i in range(len(filename)):
    filename_c[i] = ord(filename[i])
  # end for
  
  filename_c[i+1] = ord('\0')
  
  arrso_save( filename_c, &arr.arr, dhl )

  free(filename_c)

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

  """
  global dhl
  
  cdef char * filename_c 
  cdef int64_t i
  cdef arrso_t res

  filename_c=<char *>malloc(len(filename)*sizeof(char))

  for i in range(len(filename)):
    filename_c[i] = ord(filename[i])
  # end for

  filename_c[i+1] = ord('\0')

  res = arrso_read( filename_c, dhl)

  return matso.create(&res)

#---------------------------------------------------------------------------------------------------