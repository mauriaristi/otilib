


import numpy as np



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::     CLASS  FEM_REAL_MATRIX    :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
class fem_real_matrix:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in fem.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __init__(self,list shape, uint64_t n_int_points = 0): 
  	 """
    PURPOSE:      Python level constructor of the fem_real_matrix class. The porpuse of this class
                  is to provide a high level interface to an array used in the integration process
                  of a Finite Element calculation. In particular a FEM array is an "list of arrays"
                  where each element of the list correspond to an item related with the computations
                  of each integration point.

                  A = fem_real_matrix(n_int_points = 8)

                  Creates a list of 
                 
    """
    #*************************************************************************************************
    self.array   = np.zeros((n_int_points,*shape),dtype=np.float64)
    self.nintpts = n_int_points
    # Weights are not needed

  #---------------------------------------------------------------------------------------------------  

    

  #---------------------------------------------------------------------------------------------------


def det(rhs):

  t_rhs = type(rhs)

  if t_rhs == np.ndarray