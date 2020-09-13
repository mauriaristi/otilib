
#***************************************************************************************************
def get_active_bases(obj_in):
  """

  """
  

  cdef bases_t  size       = dhl.p_dh[0].Nbasis
  cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
  cdef mdmat9 SO
  cdef mdnum9 so
  cdef uint64_t i
  
  # Initialize all elements as zero (deactivated)
  for i in range(size):
    bases_list[i]=0
  # end for 
  
  tobj_in = type(obj_in)

  if tobj_in is list:

    for obj in obj_in:
      
      tobj = type(obj)

      if tobj is mdmat9:

        SO = obj
        mdarr9_get_active_bases( &SO.arr, bases_list)

      elif tobj is mdnum9:
        
        so = obj
        mdnum9_get_active_bases( &so.num, bases_list) 

      else:

        raise ValueError("Input should be list of mdnum9 or mdmat9.") 

      # end if 

    # end for

  elif tobj_in is mdmat9:

    SO = obj_in
    mdarr9_get_active_bases( &SO.arr, bases_list)

  elif tobj_in is mdnum9:
    
    so = obj_in
    mdnum9_get_active_bases( &so.num, bases_list)        

  else:

    raise ValueError("Input should be list of mdnum9 and/or mdmat9.") 

  # end if 
  
  res = []

  for i in range(size):

    if bases_list[i] == 1:
    
      res.append(i+1)

    # end if 

  # end for 

  return res

  #---------------------------------------------------------------------------------------------------