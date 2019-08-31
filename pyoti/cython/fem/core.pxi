





# ----------------------------------------------------------------------------------------------------
# ---------------------------------------    CONSTANTS    --------------------------------------------
# ----------------------------------------------------------------------------------------------------


opNames = [ "None  ","   +  ","   -  ","   *  ","   /  ","  **  ","int1d ","int2d ",
            "int3d ","  dx  ","  dy  ","  dz  ","  dxx ","  dyy ",
            "  dzz ","  dxy ","  dxz ","  dyz ","  def "]

basisNames = ["N  ","Nx ","Ny ","Nz ","Nxx",
              "Nyy","Nzz","Nxy","Nxz","Nyz"]

kindNames = ["OTIARR","OTINUM","REAL  "]

elTypeNames = ["point","line","triangle","quadrangle","tetrahedra","hexahedra"]



PntP0 = elBase.createNewElement(1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elNode,       # Geometric type
                                elkindIso,    # Kind of element 
                                0,            # Number of dimensions
                                &fem_basisFunctions_N_PntP0_0Diso, # Basis functions.
                                [] ) # List of boundary element interpolators

LineP1 = elBase.createNewElement(2,            # Number of basis 
                                 1,            # Characteristic order of the polynomials
                                 elLine,       # Geometric type
                                 elkindIso,    # Kind of element 
                                 1,            # Number of dimensions
                                 &fem_basisFunctions_N_LineP1_1Diso, # Basis functions.
                                 [PntP0] ) # List of boundary element interpolators


LineP2 = elBase.createNewElement(3,            # Number of basis 
                                 2,            # Characteristic order of the polynomials
                                 elLine,       # Geometric type
                                 elkindIso,    # Kind of element 
                                 1,            # Number of dimensions
                                 &fem_basisFunctions_N_LineP2_1Diso, # Basis functions.
                                 [PntP0] ) # List of boundary element interpolators


# TriP0 = elBase.createNewElement(1,            # Number of basis 
#                                 0,            # Characteristic order of the polynomials
#                                 elTriangle,   # Geometric type
#                                 elkindIso,    # Kind of element 
#                                 2,            # Number of dimensions
#                                 &fem_basisFunctions_N_TriangP0_2Diso , # Basis functions.
#                                  [PntP0] ) # List of boundary element interpolators


TriP1 = elBase.createNewElement(3,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                &fem_basisFunctions_N_TriangP1_2Diso, # Basis functions.
                                [PntP0,LineP1] ) # List of boundary element interpolators


TriP2 = elBase.createNewElement(6,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                &fem_basisFunctions_N_TriangP2_2Diso, # Basis functions.
                                [PntP0,LineP2] ) # List of boundary element interpolators


QuadP1 = elBase.createNewElement(4,            # Number of basis 
                                 1,            # Characteristic order of the polynomials
                                 elQuadrangle, # Geometric type
                                 elkindIso,    # Kind of element 
                                 2,            # Number of dimensions
                                 &fem_basisFunctions_N_QuadP1_2Diso, # Basis functions.
                                 [PntP0,LineP1] ) # List of boundary element interpolators


QuadSerP2 = elBase.createNewElement(8,            # Number of basis 
                                    2,            # Characteristic order of the polynomials or 2?
                                    elQuadrangle, # Geometric type
                                    elkindIso,    # Kind of element 
                                    2,            # Number of dimensions
                                    &fem_basisFunctions_N_QuadSerendP2_2Diso, # Basis functions.
                                    [PntP0,LineP2] ) # List of boundary element interpolators


# ----------------------------------------------------------------------------------------------------





























# # ----------------------------------------------------------------------------------------------------
# # -------------------------------------    AUX FUNCTIONS    ------------------------------------------
# # ----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef intOmega(fefunction func1, region = -1):
#   """ 
#   PURPOSE: Domain integral

#   """

#   cdef fefunction res 
#   cdef fefunction func2 =  <fefunction> fefunction.__new__(fefunction)
#   cdef int64_t regionIdNum

#   res   = fefunction.newFromOperation(opInt3d,func1,func2)

#   type1 = type(region)

#   if type1 == str:
#     regionIdNum = res.baseSpace.mesh.nameIds[region]
#   else:
#     regionIdNum = region
#   # end if 

#   res.data = region

#   return res
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef intGamma( boundaryId, fefunction func1 ):
#   """ 
#   PURPOSE: Boundary integral

#   """

#   cdef fefunction res 
#   cdef fefunction func2 =  <fefunction> fefunction.__new__(fefunction)
#   cdef int64_t boundIdNum
  
#   res   = fefunction.newFromOperation(opInt2d,func1,func2)

#   type1 = type(boundaryId)
  
#   if type1 == str:
#     boundIdNum = res.baseSpace.mesh.nameIds[boundaryId]
#   else:
#     boundIdNum = boundaryId
#   # end if 

#   res.data = boundIdNum

#   return res
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef on(boundaryId, fefunction func1, in2): # define Dirichlet boundary conditions.
#   """
#   PURPOSE: Define essential (Dirichlet) boundary conditions for a finite element problem.

#   INPUTS: 

#     -> func1:   Undefined variable that will be set in the boundaries

#     -> in2:   Value at the boundary. This, for now, is only defined by defined FE function class.


#   """

#   cdef fefunction res, func2
#   cdef int64_t boundIdNum 

#   type1 = type(boundaryId)
#   type2 = type(in2)

#   if type2 == fefunction:
#     func2 = in2
#   else:
#     func2 = func1.baseSpace.newFunction(in2)
#   # end if 

#   res   = fefunction.newFromOperation(opOn,func2,func1)
    
#   if type1 == str:
#     boundIdNum = res.baseSpace.mesh.nameIds[boundaryId]
#   else:
#     boundIdNum = boundaryId
#   # end if 

#   res.data = boundIdNum

#   return res

# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef dx(fefunction func1):
#   """
#   PURPOSE: Define derivative of a Finite Element function.

#   INPUTS:  

#     -> func1:   Finite element function that will be derived.

#   """ 

#   cdef fefunction res 

#   res   = fefunction.newFromOperation(opDx,func1,None)

#   return res
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef dy(fefunction func1):
#   """
#   PURPOSE: Define derivative of a Finite Element function.

#   INPUTS: 

#     -> func1:   Finite element function that will be derived.

#   """ 

#   cdef fefunction res 

#   res   = fefunction.newFromOperation(opDy,func1,None)

#   return res
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef dz(fefunction func1):
#   """
#   PURPOSE: Define derivative of a Finite Element function.

#   INPUTS: 

#     -> func1:   Finite element function that will be derived.

#   """ 

#   cdef fefunction res 

#   res   = fefunction.newFromOperation(opDz,func1,None)

#   return res
# #-----------------------------------------------------------------------------------------------------





























































# #*****************************************************************************************************
# def fem_integrationPointsWeights(uint64_t order, int64_t elementType):
#   """
#   PURPOSE:     Test to check if the integration points and weights are good.
#   """
#   cdef darray_t coords, weights
#   cdef np.ndarray np_coords, np_weights
#   c_fem_integrationPoints(order, elementType, &coords, &weights)
#   np_coords = darray_2_numpyArray(&coords )
#   np_weights = darray_2_numpyArray(&weights )


#   # Free arrays
#   c_darray_free(&coords)
#   c_darray_free(&weights)

#   return (np_coords, np_weights)
# #-----------------------------------------------------------------------------------------------------






# #*****************************************************************************************************
# def fem_readOperMat(mesh meshObj, np.ndarray mat):
#   """
#   DESCRIPTION:  Function to convert to a human readable format the operation stack produced 
#                 by operating finite element Variables.



#   """
#   cdef uint64_t i,j
#   cdef uint64_t shape0 = mat.shape[0]
#   out = ""
#   space = " "
#   # opNames
#   for i in range(shape0):

#     out += opNames[mat[i,0]]
#     out += space
    
#     if mat[i,0] <= np.uint64(opTruediv):
      
#       # print(" In basic operations")

#       # out += str(meshObj.elements[mat[i,1]])
#       out += kindNames[mat[i,2]]
#       out += space+str(mat[i,3])
#       out += ' with '
#       # out += str(meshObj.elements[mat[i,4]])
#       out += kindNames[mat[i,5]]
#       out += space+str(mat[i,6])
#       out += ' in '
#       # out += str(meshObj.elements[mat[i,7]])
#       out += kindNames[mat[i,8]]
#       out += space+str(mat[i,9])

#     elif mat[i,0] == opDef:
      
#       # print(" In definition operation")
#       # out += kindNames[mat[i,5]]
#       # out += space+str(mat[i,6])
#       out += kindNames[mat[i,3]]
#       out += space+str(mat[i,4])
#       out += " as "
#       j = mat[i,1]-basisN
#       out += basisNames[j]
      
      

#     elif mat[i,0] == opPowr: # Power function

#       # print(" In power operation")
#       # out += str(meshObj.elements[mat[i,1]])
#       out += kindNames[mat[i,2]]
#       out += space+str(mat[i,3])
#       out += " by exp "
#       out += str(meshObj.constObj[mat[i,5]][mat[i,4]])

#     elif mat[i,0] <= opInt3d: # integrals

#       # print(" In Integration operation")
#       # out += "variable "
#       # out += str(meshObj.elements[mat[i,2]])
#       out += kindNames[mat[i,3]]
#       out += space+str(mat[i,4])
#       out += ' in '
#       # out += str(meshObj.elements[mat[i,5]])
#       out += kindNames[mat[i,6]]
#       out += space+str(mat[i,7])

#     out += '\n'

#   print(out)
#   # return out
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef int64_t fem_getDataKind(object data):
#   """
#   PURPOSE:     Get the kind of data 

#   """
#   cdef int64_t res
#   if type(data) == sndarray:
        
#     res = kindFunc      # kind of function.

#   elif type(data) == sotinum:
        
#     res = kindScalar

#   elif type(data) in number_types:
        
#     res = kindReal

#   else:

#      raise ValueError("Undefined data kind. ")

#   # end if

#   return res
# #-----------------------------------------------------------------------------------------------------




# #*****************************************************************************************************
# cpdef list fem_getOffset(list position,list solFunc,list testFunc,np.ndarray eDOF_per_sol):
#   """
#   PURPOSE:     Get the equivalent offset of the starting position 

#   """
#   cdef list eqPos = fem_getEqvPosition( position, solFunc, testFunc)
#   cdef list res = [0,0]
#   cdef uint64_t zero = 0, one = 1
    
#   res[zero] = eDOF_per_sol[eqPos[zero]]

#   res[one] = eDOF_per_sol[eqPos[one]]

#   return res

# #-----------------------------------------------------------------------------------------------------




# #*****************************************************************************************************
# cpdef list fem_getEqvPosition(list position,list solFunc,list testFunc):
#   """
#   PURPOSE:    Convert a position given by function ids, into problem local coordinates.

#   """
#   cdef int64_t i,j
#   cdef uint64_t res, funcId, funcId2
#   cdef fefunction func

#   if len(position)==1:
    
#     funcId = position[0]

#     if funcId == 0:
#       return [0,0]
#     # end if 

#     for i in range(len(solFunc)):
#       func = solFunc[i]
#       if func.funcid == funcId:
#         return [i,0]
#       # end if 
#     # end for

#     for i in range(len(testFunc)):
#       func = testFunc[i]
#       if func.funcid == funcId:
#         return [i,0]
#       # end if 
#     # end for
#     print("Position before error: ", position)
#     raise ValueError("Position defined with respect to a variable that is not in the problem functions!")

#   else:
    
#     funcId = position[0]
#     funcId2= position[1]

#     for j in range(len(solFunc)):
#       func = solFunc[j]
#       if func.funcid == funcId2:
#         break
#       # end if 
#     # end for

#     for i in range(len(testFunc)):
#       func = testFunc[i]
#       if func.funcid == funcId:
#         break
#       # end if 
#     # end for
#     return [i, j]
#   # end if


# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef uint64_t fem_getEqvPositionIndx(list position,list solFunc,list testFunc):
#   """
#   PURPOSE:    Convert a position given by function ids, into problem local coordinates.

#   """
#   #***************************************************************************************************

#   cdef int64_t i,j
#   cdef uint64_t res, funcId, funcId2
#   cdef fefunction func

#   if len(position)==1:
#     funcId = position[0]
#     for i in range(len(solFunc)):
#       func = solFunc[i]
#       if func.funcid == funcId:
#         return i
#       # end if 
#     # end for

#     for i in range(len(testFunc)):
#       func = solFunc[i]
#       if func.funcid == funcId:
#         return i
#       # end if 
#     # end for
    
#     raise ValueError("Position defined with respect to a variable that is not in the problem functions!")
#   else:
#     funcId = position[0]
#     funcId2= position[1]
#     for j in range(len(solFunc)):
#       func = solFunc[j]
#       if func.funcid == funcId2:
#         break
#       # end if 
#     # end for

#     for i in range(len(testFunc)):
#       func = testFunc[i]
#       if func.funcid == funcId:
#         break
#       # end if 
#     # end for
#     return i*len(testFunc)+ j
#   # end if


# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef list fem_getOrderedFuncList(list funcList):
#   """
#   PURPOSE:    Generate a list of operations such that the elements match one-to-one with the 
#               function ids of the element's list.

#   """
#   #***************************************************************************************************

#   cdef fefunction func = funcList[len(funcList)-1]
#   cdef list res = [None]*int(func.funcid+1)
#   cdef int64_t i
  
#   for i in range(len(funcList)):
#     func = funcList[i]
#     res[func.funcid]=func
#   # end for

#   return res
# #-----------------------------------------------------------------------------------------------------







#*****************************************************************************************************
cdef object c_fem_get_enum_string(int64_t enumId):
  """
  PURPOSE:    Returns a string with the name of the corresponding enum value given.

  """
  #***************************************************************************************************

  if enumId == opAdd        :
    return "opAdd        "
  elif enumId == opSub        :
    return "opSub        "
  elif enumId == opMul        :
    return "opMul        "
  elif enumId == opTruediv    :
    return "opTruediv    "
  elif enumId == opPowr       :
    return "opPowr       "
  elif enumId == opInt1d      :
    return "opInt1d      "
  elif enumId == opInt2d      :
    return "opInt2d      "
  elif enumId == opInt3d      :
    return "opInt3d      "
  elif enumId == opDx         :
    return "opDx         "
  elif enumId == opDxx        :
    return "opDxx        "
  elif enumId == opDy         :
    return "opDy         "
  elif enumId == opDxy        :
    return "opDxy        "
  elif enumId == opDyy        :
    return "opDyy        "
  elif enumId == opDz         :
    return "opDz         "
  elif enumId == opDxz        :
    return "opDxz        "
  elif enumId == opDyz        :
    return "opDyz        "
  elif enumId == opDzz        :
    return "opDzz        "
  elif enumId == opDef        :
    return "opDef        "
  elif enumId == opOn         :
    return "opOn         "
  elif enumId == opNeg        :
    return "opNeg        "
  elif enumId == subOpDefBasis:
    return "subOpDefBasis"
  elif enumId == subOpDefKnown:
    return "subOpDefKnown"
  elif enumId == subOpInt     :
    return "subOpInt     "
  elif enumId == subOpNeg     :
    return "subOpNeg     "
  elif enumId == subOpMulRes  :
    return "subOpMulRes  "
  elif enumId == subOpMulKnown:
    return "subOpMulKnown"
  elif enumId == subOpOn      :
    return "subOpOn      "
  elif enumId == basisN       :
    return "basisN       "
  elif enumId == basisNx      :
    return "basisNx      "
  elif enumId == basisNxx     :
    return "basisNxx     "
  elif enumId == basisNy      :
    return "basisNy      "
  elif enumId == basisNxy     :
    return "basisNxy     "
  elif enumId == basisNyy     :
    return "basisNyy     "
  elif enumId == basisNz      :
    return "basisNz      "
  elif enumId == basisNxz     :
    return "basisNxz     "
  elif enumId == basisNyz     :
    return "basisNyz     "
  elif enumId == basisNzz     :
    return "basisNzz     "
  elif enumId == kindOtiArr   :
    return "kindOtiArr   "
  elif enumId == kindOtiNum   :
    return "kindOtiNum   "
  elif enumId == kindReal     :
    return "kindReal     "
  elif enumId == kindScalar   :
    return "kindScalar   "
  elif enumId == kindFunc     :
    return "kindFunc     "
  elif enumId == constant     :
    return "constant     "
  elif enumId == variable     :
    return "variable     "
  elif enumId == elNode       :
    return "elNode       "
  elif enumId == elLine       :
    return "elLine       "
  elif enumId == elTriangle   :
    return "elTriangle   "
  elif enumId == elQuadrangle :
    return "elQuadrangle "
  elif enumId == elTetrahedra :
    return "elTetrahedra "
  elif enumId == elHexahedra  :
    return "elHexahedra  "
  elif enumId == elkindIso    :
    return "elkindIso    "
  elif enumId == elkindAff    :
    return "elkindAff    "
  elif enumId == derN         :
    return "derN         "
  elif enumId == derNa        :
    return "derNa        "
  elif enumId == derNaa       :
    return "derNaa       "
  elif enumId == derNb        :
    return "derNb        "
  elif enumId == derNab       :
    return "derNab       "
  elif enumId == derNbb       :
    return "derNbb       "
  elif enumId == derNc        :
    return "derNc        "
  elif enumId == derNac       :
    return "derNac       "
  elif enumId == derNbc       :
    return "derNbc       "
  elif enumId == derNcc       :
    return "derNcc       "
  elif enumId == feNatTest    :
    return "feNatTest    "
  elif enumId == feNatUndef   :
    return "feNatUndef   "
  elif enumId == feNatDef     :
    return "feNatDef     "
  elif enumId == feNatDefConst:
    return "feNatDefConst"
  elif enumId == feNatOperRes :
    return "feNatOperRes "
  elif enumId == feNatPostIntK:
    return "feNatPostIntK"
  elif enumId == feNatPostIntF:
    return "feNatPostIntF"
  elif enumId == feNatBoundary:
    return "feNatBoundary"

#-----------------------------------------------------------------------------------------------------


# #***************************************************************************************************** 
# cdef object c_darray_print(darray_t* array):
#   """
#   PURPOSE:  To print a representation of the sotiarray object that could be
#             used to create new dualnum objects, in a compact form.

  
#   """
#   #***************************************************************************************************
  
#   cdef uint64_t i,j
#   cdef double tmp
#   cdef str coef, head, body, tail

#   head = 'darray('
#   body = '['

#   for i in range(array[0].nrows):
#     if i!=0:
#       body+="        "
#     # end if 
#     body+='['

#     for j in range(array[0].ncols):
      
#       body += " "
      

#       c_darray_getItem(array,i,j,&tmp)
      
#       coef = "%+.4f"%tmp
      
#       if coef[0] == '+':
        
#         body+= " "+coef[1:]

#       else:

#         body += coef

#       # end if 
      
#       body+=","
    
#     # end for 
#     body = body[:len(body)-1]
#     body += "],\n"

#   # end for 
      
#   body  = body[:len(body)-2]
#   body += "]"
#   body += ' shape = ('+str(array[0].nrows)+','+str(array[0].ncols)+") "

#   tail = " )\n"

#   return (head + body + tail)

# #-----------------------------------------------------------------------------------------------------

# #***************************************************************************************************** 
# cdef object c_elemprops_print(elemProps_t* array,style = 1):
#   """
#   PURPOSE:  To print a representation of the sotiarray object that could be
#             used to create new dualnum objects, in a compact form.

  
#   """
#   #***************************************************************************************************
  
#   cdef uint64_t i


#   head   ='Element Definition:\n'
#   body  = "   - nbasis:       "+str(array[0].nbasis  )+ ",\n"
#   body += "   - order:        "+str(array[0].order   )+ ",\n"
#   body += "   - geomBase:     "+c_fem_get_enum_string(array[0].geomBase)+ ",\n"
#   body += "   - kind:         "+c_fem_get_enum_string(array[0].kind    )+ ",\n"
#   body += "   - ndim:         "+str(array[0].ndim    )+ ",\n"
#   body += "   - nIntPts:      "+str(array[0].nIntPts )+ ",\n"
#   body += "   - nder:         "+str(array[0].nder    )+ ",\n"
#   body += "   - isInit:       "+str(array[0].isInit  )+ ",\n"
#   body += "   - otiorder:     "+str(array[0].otiorder )+ ",\n"
#   body += "   - nDimAnalysis: "+str(array[0].nDimAnalysis )+ ",\n"
  
#   body += "   - integration points:"+ "\n"
  
#   body += c_darray_print(&array[0].p_intPoints)

#   body += "   - Integration weights:"+ "\n"

#   body += c_darray_print(&array[0].p_intWeights)
  

#   body += "   - Evaluated basis functions: "+ "\n"

#   for i in range(array[0].nder):

#     body += "    "+ c_fem_get_enum_string(derN+i)+":\n"
#     body += c_darray_print(&array[0].p_evalBasis[i])
#     body += "\n"  

#   # end for   
  
#   tail = ""
#   return (head + body + tail)

# #-----------------------------------------------------------------------------------------------------

# #***************************************************************************************************** 
# cdef object c_femarray_print(femarray_t* array,style = 1):
#   """
#   PURPOSE:  To print a representation of the sotiarray object that could be
#             used to create new dualnum objects, in a compact form.

  
#   """
#   #***************************************************************************************************
  
#   cdef uint64_t i


#   head   = 'femarray( order = '+str(array[0].order)+ ", "
  
#   body   = 'shape = ('+str(array[0].nrows)+','+str(array[0].ncols)+"), "
#   body  += 'offset = ('+str(array[0].offsetx)+','+str(array[0].offsety)+"), "
#   body  += 'data:\n'

#   for i in range(array[0].nIntPts):
#     body += "int point "+ str(i)+"\n"
#     body += c_sotiarray_print(&array[0].p_data[i])
#     body += "\n"  
#   # end for 
  
#   tail = " )"
#   return (head + body + tail)

# #-----------------------------------------------------------------------------------------------------

# #***************************************************************************************************** 
# cdef object c_elemprops_print_perElement(elemProps_t* array,style = 1):
#   """
#   PURPOSE:  To print a representation of the sotiarray object that could be
#             used to create new dualnum objects, in a compact form.

  
#   """
#   #***************************************************************************************************
  
#   cdef uint64_t i


#   head   ='Per Element Properties of '+c_fem_get_enum_string(array[0].geomBase)
#   head  +=" of order " + str(array[0].order)+'\n'  
#   body = "   - Jacobian:"+ "\n"
#   body += c_femarray_print(&array[0].J)

#   body += "\n   - Jacobian Inverse:"+ "\n"  
#   body += c_femarray_print(&array[0].Jinv)

#   body += "\n   - Jacobian Determinant:"+ "\n"
#   body += c_femarray_print(&array[0].Jdet)

#   body += "\n   - Integration weights times Jacobian:"+ "\n"
#   body += c_femarray_print(&array[0].p_detWeights)
  

#   body += "\n   - spacial defined basis functions: "+ "\n"

#   for i in range(array[0].nder):

#     body += "    "+ c_fem_get_enum_string(basisN+i)+" at "+hex(<uint64_t>&array[0].p_basis[i])+":\n"
#     body += c_femarray_print(&array[0].p_basis[i])
#     body += "\n"  

#   # end for   
  
#   tail = ""
#   return (head + body + tail)

# #-----------------------------------------------------------------------------------------------------











