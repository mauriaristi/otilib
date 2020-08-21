
#***************************************************************************************************
def get_active_bases(obj_in):
  """

  """
  

  cdef bases_t  size       = dhl.p_dh[0].Nbasis
  cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
  cdef {arr_pytype} SO
  cdef {num_pytype} so
  cdef uint64_t i
  
  # Initialize all elements as zero (deactivated)
  for i in range(size):
    bases_list[i]=0
  # end for 
  
  tobj_in = type(obj_in)

  if tobj_in is list:

    for obj in obj_in:
      
      tobj = type(obj)

      if tobj is {arr_pytype}:

        SO = obj
        {arr_func}_get_active_bases( &SO.arr, bases_list)

      elif tobj is {num_pytype}:
        
        so = obj
        {num_func}_get_active_bases( &so.num, bases_list) 

      else:

        raise ValueError("Input should be list of {num_pytype} or {arr_pytype}.") 

      # end if 

    # end for

  elif tobj_in is {arr_pytype}:

    SO = obj_in
    {arr_func}_get_active_bases( &SO.arr, bases_list)

  elif tobj_in is {num_pytype}:
    
    so = obj_in
    {num_func}_get_active_bases( &so.num, bases_list)        

  else:

    raise ValueError("Input should be list of {num_pytype} and/or {arr_pytype}.") 

  # end if 
  
  res = []

  for i in range(size):

    if bases_list[i] == 1:
    
      res.append(i+1)

    # end if 

  # end for 

  return res

  #---------------------------------------------------------------------------------------------------