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
    y = zero()
  else:  
    y = out
  # end if 
  
  start  = 1
  finish = xvals.shape[0]

  # evaluate bounds:
  if xr < xvals.arr.p_data[start-1].re:

    y =  yvals[start-1,0].copy()

  elif xr > xvals.arr.p_data[finish-1].re:

    y =  yvals[finish-1,0].copy()

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
  # end if 

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
  cdef uint64_t i, j, 
  
  
  if out is None:
    res_flag = 0
    y = zeros(x.shape)
  else:
    if x.shape[0] != out.shape[0] and x.shape[1] != out.shape[1]:
      raise IndexError('"out" array must have the same shape as the interpolated matrix "x"')
    # end if
    y = out
  # end if 
  
  for i in range(y.shape[0]):
    for j in range(y.shape[1]):
      y[i,j] = __interp1d_OOo( xvals, yvals, x[i,j] )
    # end for 
  # end for 

  if res_flag == 0:
    return y
  # end if 

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
    finish = xvals.shape[0]

    x = sotinum.create( &xfe.num.p_data[ip], FLAGS=0 )
    xr = x.real
    
    # evaluate bounds:
    if xr < xvals.arr.p_data[start-1].re:

      y[ip] =  yvals[start-1,0].copy()

    elif xr > xvals.arr.p_data[finish-1].re:

      y[ip] =  yvals[finish-1,0].copy()

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

#-----------------------------------------------------------------------------------------------------