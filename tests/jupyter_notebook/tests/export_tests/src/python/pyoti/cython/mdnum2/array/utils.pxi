
#***************************************************************************************************
def get_active(obj_in):
  """

  """
  

  cdef bases_t  size       = dhl.p_dh[0].Nbasis
  cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
  cdef mdarr2_t SO
  cdef mdnum2_t so
  cdef uint64_t i
  
  # Initialize all elements as zero (deactivated)
  for i in range(size):
    bases_list[i]=0
  # end for 
  
  tobj_in = type(obj_in)

  if tobj_in is list:

    for obj in obj_in:
      
      tobj = type(obj)

      if tobj is mdarr2_t:

        SO = obj
        mdarr2_get_active( &SO.arr, bases_list)

      elif tobj is mdnum2_t:
        
        so = obj
        mdnum2_get_active( &so.num, bases_list) 

      else:

        raise ValueError("Input should be list of mdnum2_t or mdarr2_t.") 

      # end if 

    # end for

  elif tobj_in is mdarr2_t:

    SO = obj_in
    mdarr2_get_active( &SO.arr, bases_list)

  elif tobj_in is mdnum2_t:
    
    so = obj_in
    mdnum2_get_active( &so.num, bases_list)        

  else:

    raise ValueError("Input should be list of mdnum2_t and/or mdarr2_t.") 

  # end if 
  
  res = []

  for i in range(size):

    if bases_list[i] == 1:
    
      res.append(i+1)

    # end if 

  # end for 

  return res

  #---------------------------------------------------------------------------------------------------