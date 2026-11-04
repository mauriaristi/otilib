#*****************************************************************************************************
cdef sotinum __interp1d_OOo(matso xvals, matso yvals, sotinum x , sotinum out = None):
  """
  PURPOSE:  Interpolation in 1D. xData MUST be in ascending order with no repeated entries.

  INPUTS:
    - xvals: x-values of data.
    - yvals: y-values of data.
    - x:     Value to interpolate.
    - out: (optional) Output element to hold the data.

  OUTPUTS:

    If out is not given, the function returns the interpolated number.

  """
  #***************************************************************************************************
  cdef sotinum    ores
  
  cdef uint8_t res_flag = 1
  cdef sotinum y, ymidm1, xmidm1, ymid, xmid
  cdef uint64_t i, j, start, finish, mid, rang
  cdef coeff_t xr = x.real
  
  if out is None:
    res_flag = 0
  # end if 

  # y is rebound below, so it can not alias `out`; the result is copied into `out` at the end.
  y = zero()
  
  start  = 1
  finish = xvals.arr.nrows

  # evaluate bounds:
  if xr < xvals.arr.p_data[start-1].re:

    y =  _vec_item(yvals, start-1).copy()

  elif xr > xvals.arr.p_data[finish-1].re:

    y =  _vec_item(yvals, finish-1).copy()

  else:

    rang =   finish - start
    mid  = ( finish + start )// 2

    # Find location using binary search
    while rang > 1:
      
      if (xr > xvals.arr.p_data[mid-1].re):
        start  = mid 
      else:
        finish = mid
      # end if

      rang =   finish - start
      mid  = ( finish + start )// 2

    # end while

    ymidm1 = sotinum.create(&yvals.arr.p_data[mid-1],FLAGS=0)
    xmidm1 = sotinum.create(&xvals.arr.p_data[mid-1],FLAGS=0)
    ymid = sotinum.create(&yvals.arr.p_data[mid],FLAGS=0)
    xmid = sotinum.create(&xvals.arr.p_data[mid],FLAGS=0)
    m = ( ymid - ymidm1) / ( xmid - xmidm1 ) # Line region slope.
    y = m * ( x - xmidm1 )  + ymidm1

  # end if 

  if res_flag == 0:
    return y
  else:
    out.set(y)
  # end if 

  return out

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef matso __interp1d_OOO(matso xvals, matso yvals, matso x , matso out = None):
  """
  PURPOSE:  Interpolation in 1D. xData MUST be in ascending order with no repeated entries.

  INPUTS:
    - xvals: x-values of data.
    - yvals: y-values of data.
    - x:     Values to interpolate.
    - out: (optional) Output element to hold the data.

  OUTPUTS:

    If out is not given, the function returns the interpolated number.

  """
  #***************************************************************************************************
  cdef matso y
  cdef uint8_t res_flag = 1
  cdef uint64_t i, j
  cdef sotinum_t ores
  cdef sotinum interp

  
  
  if out is None:
    res_flag = 0
    y = zeros(x.shape)
  else:
    if x.shape != out.shape:
      raise IndexError('"out" array must have the same shape as the interpolated matrix "x"')
    # end if
    y = out
  # end if 

  # Every element of x (the 2-D struct, row-major): a 1-D x is stored as a column.
  for i in range(y.arr.size):
    ores = arrso_get_item_i( &x.arr, i, dhl)
    interp = __interp1d_OOo( xvals, yvals, sotinum.create(&ores, FLAGS=0) )
    arrso_set_item_i_o( &interp.num, i, &y.arr, dhl)
  # end for 

  if res_flag == 0:
    return y
  # end if 

  return out

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef sotife __interp1d_OOf(matso xvals, matso yvals, sotife xfe , sotife out = None):
  """
  PURPOSE:  Interpolation in 1D. xData MUST be in ascending order with no repeated entries.

  INPUTS:
    - xvals: x-values of data.
    - yvals: y-values of data.
    - xfe:   Value to interpolate.
    - out: (optional) Output element to hold the data.

  OUTPUTS:

    If out is not given, the function returns the interpolated number.


  """
  #***************************************************************************************************
  
  cdef uint8_t res_flag = 1
  cdef sotife y
  cdef sotinum x
  cdef uint64_t i, j, ip, start, finish, mid, rang
  cdef coeff_t xr
  
  if out is None:
    res_flag = 0
    y = zero( nip = xfe.nip )
  else:  
    y = out
  # end if
  
  
  for ip in range(xfe.nip):
    
    start  = 1
    finish = xvals.arr.nrows

    x = sotinum.create( &xfe.num.p_data[ip], FLAGS=0 )
    xr = x.real
    
    # evaluate bounds:
    if xr < xvals.arr.p_data[start-1].re:

      y[ip] =  _vec_item(yvals, start-1).copy()

    elif xr > xvals.arr.p_data[finish-1].re:

      y[ip] =  _vec_item(yvals, finish-1).copy()

    else:

      rang =   finish - start
      mid  = ( finish + start )// 2

      # Find location using binary search
      while rang > 1:
        
        if (xr > xvals.arr.p_data[mid-1].re):
          start  = mid 
        else:
          finish = mid
        # end if

        rang =   finish - start
        mid  = ( finish + start )// 2

      # end while

      ymidm1 = sotinum.create(&yvals.arr.p_data[mid-1],FLAGS=0)
      xmidm1 = sotinum.create(&xvals.arr.p_data[mid-1],FLAGS=0)
      ymid = sotinum.create(&yvals.arr.p_data[mid],FLAGS=0)
      xmid = sotinum.create(&xvals.arr.p_data[mid],FLAGS=0)
      m = ( ymid - ymidm1) / ( xmid - xmidm1 ) # Line region slope.
      y[ip] = m * ( x - xmidm1 )  + ymidm1

    # end if 

  # end for

  if res_flag == 0:
    return y
  # end if 

  return out

#-----------------------------------------------------------------------------------------------------