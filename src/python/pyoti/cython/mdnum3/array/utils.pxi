
#***************************************************************************************************
def get_active(obj_in):
  """

  """
  

  cdef bases_t  size       = dhl.p_dh[0].Nbasis
  cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
  cdef mdarr3_t SO
  cdef mdnum3_t so
  cdef uint64_t i
  
  # Initialize all elements as zero (deactivated)
  for i in range(size):
    bases_list[i]=0
  # end for 
  
  tobj_in = type(obj_in)

  if tobj_in is list:

    for obj in obj_in:
      
      tobj = type(obj)

      if tobj is mdarr3_t:

        SO = obj
        mdarr3_get_active( &SO.arr, bases_list)

      elif tobj is mdnum3_t:
        
        so = obj
        mdnum3_get_active( &so.num, bases_list) 

      else:

        raise ValueError("Input should be list of mdnum3_t or mdarr3_t.") 

      # end if 

    # end for

  elif tobj_in is mdarr3_t:

    SO = obj_in
    mdarr3_get_active( &SO.arr, bases_list)

  elif tobj_in is mdnum3_t:
    
    so = obj_in
    mdnum3_get_active( &so.num, bases_list)        

  else:

    raise ValueError("Input should be list of mdnum3_t and/or mdarr3_t.") 

  # end if 
  
  res = []

  for i in range(size):

    if bases_list[i] == 1:
    
      res.append(i+1)

    # end if 

  # end for 

  return res

  #---------------------------------------------------------------------------------------------------