













def generateMatrix(,N):



  # allocate memory variables

  x1 = 
  x2 = 
  x3 = 
  y1 = 
  y2 = 
  y3 = 

  # Create Jacobian Matrix
  
  J11 = 
  J12 = 
  J21 = 
  J22 =


  detJ = J11*J22-J12*J21
  Ji11 =  J22/detJ
  Ji12 = -J12/detJ
  Ji21 = -J21/detJ
  Ji22 =  J11/detJ
  f_e1 = f[triang[eli,0]]
  f_e2 = f[triang[eli,1]]
  f_e3 = f[triang[eli,2]]
  A11 =  Ji11*Ji11 + Ji11*Ji21 +
  A12 = -Ji11*Ji11 - Ji11*Ji21 -
  A13 = -Ji11*Ji21 - Ji21*Ji21 -
  A21 = -Ji11*Ji11 - Ji11*Ji21 -
  A22 =  Ji11*Ji11 + Ji12*Ji12
  A23 =  Ji11*Ji21 + Ji12*Ji22
  A31 = -Ji11*Ji21 - Ji21*Ji21 -
  A32 =  Ji11*Ji21 + Ji12*Ji22 
  A33 =  Ji21*Ji21 + Ji22*Ji22
  A =  np.array([[A11,A12,A13],[
  C11 =  1.0/6.0  *otione
  C12 = -1.0/12.0 *otione
  C13 = -1.0/12.0 *otione
  C21 = -1.0/12.0 *otione
  C22 =  1.0/3.0  *otione
  C23 =  1.0/4.0  *otione
  C31 = -1.0/12.0 *otione
  C32 =  1.0/4.0  *otione
  C33 =  1.0/3.0  *otione


  Cp = np.array([[ 1./ 6.,-1./12.,-1./12.],
                 [-1./12., 1./ 3., 1./ 4.],
                 [-1./12., 1./ 4., 1./ 3.] ]) * otione



  # eli = 0
  for eli in range(triang.shape[0]):
      
      x1 = xall[triang[eli,0]]
      x2 = xall[triang[eli,1]]
      x3 = xall[triang[eli,2]]
      y1 = yall[triang[eli,0]]
      y2 = yall[triang[eli,1]]
      y3 = yall[triang[eli,2]]

      # Create Jacobian Matrix
      
      J11 = x2-x1
      J12 = x3-x1
      J21 = y2-y1
      J22 = y3-y1
      
      
      detJ = J11*J22-J12*J21
      
      Ji11 =  J22/detJ
      Ji12 = -J12/detJ
      Ji21 = -J21/detJ
      Ji22 =  J11/detJ
      
      f_e1 = f[triang[eli,0]]
      f_e2 = f[triang[eli,1]]
      f_e3 = f[triang[eli,2]]

      A11 =  Ji11*Ji11 + Ji11*Ji21 + Ji11*Ji21 + Ji21*Ji21 + Ji12*Ji12 + Ji12*Ji22 + Ji12*Ji22 + Ji22*Ji22
      A12 = -Ji11*Ji11 - Ji11*Ji21                         - Ji12*Ji12 - Ji12*Ji22 
      A13 =            - Ji11*Ji21             - Ji21*Ji21             - Ji12*Ji22             - Ji22*Ji22 
      A21 = -Ji11*Ji11 - Ji11*Ji21                         - Ji12*Ji12 - Ji12*Ji22 
      A22 =  Ji11*Ji11                                     + Ji12*Ji12
      A23 =              Ji11*Ji21                                     + Ji12*Ji22
      A31 =            - Ji11*Ji21             - Ji21*Ji21             - Ji12*Ji22             - Ji22*Ji22
      A32 =              Ji11*Ji21                                                 + Ji12*Ji22 
      A33 =                                      Ji21*Ji21                                     + Ji22*Ji22

   
      
      A =  np.array([[A11,A12,A13],[A21,A22,A23],[A31,A32,A33]])*detJ
      

      C11 =  1.0/6.0  *otione
      C12 = -1.0/12.0 *otione
      C13 = -1.0/12.0 *otione
      C21 = -1.0/12.0 *otione
      C22 =  1.0/3.0  *otione
      C23 =  1.0/4.0  *otione
      C31 = -1.0/12.0 *otione
      C32 =  1.0/4.0  *otione
      C33 =  1.0/3.0  *otione

      C =  np.array([[C11,C12,C13],[C21,C22,C23],[C31,C32,C33]])*detJ
      
      K_e = A + C
      
      F_e =np.array([  (C11*f_e1 + C12*f_e2 + C13*f_e3)*detJ,
                       (C21*f_e1 + C22*f_e2 + C23*f_e3)*detJ,
                       (C31*f_e1 + C32*f_e2 + C33*f_e3)*detJ])

      assmSys(K,K_e,F,F_e,triang[eli,:])
            



