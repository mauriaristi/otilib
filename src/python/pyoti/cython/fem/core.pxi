





























# # # ----------------------------------------------------------------------------------------------------
# # # -------------------------------------    AUX FUNCTIONS    ------------------------------------------
# # # ----------------------------------------------------------------------------------------------------













































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

#*****************************************************************************************************
cpdef int64_t fem_getDataKind(object data):
  """
  PURPOSE:     Get the kind of data 

  """
  cdef int64_t res
  if type(data) == omat:
        
    res = kindFunc      # kind of function.

  elif type(data) == otinum:
        
    res = kindScalar

  elif type(data) in number_types:
        
    res = kindReal

  else:

     raise ValueError("Undefined data kind. ")

  # end if

  return res
#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef list fem_getOffset(list position,list solFunc,list testFunc,np.ndarray eDOF_per_sol):
  """
  PURPOSE:     Get the equivalent offset of the starting position 

  """
  cdef list eqPos = fem_getEqvPosition( position, solFunc, testFunc)
  cdef list res = [0,0]
  cdef uint64_t zero = 0, one = 1
    
  res[zero] = eDOF_per_sol[eqPos[zero]]

  res[one] = eDOF_per_sol[eqPos[one]]

  return res

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef list fem_getEqvPosition(list position,list solFunc,list testFunc):
  """
  PURPOSE:    Convert a position given by function ids, into problem local coordinates.

  """
  cdef int64_t i,j
  cdef uint64_t res, funcId, funcId2
  cdef fefunction func

  if len(position)==1:
    
    funcId = position[0]

    if funcId == 0:
      return [0,0]
    # end if 

    for i in range(len(solFunc)):
      func = solFunc[i]
      if func.funcid == funcId:
        return [i,0]
      # end if 
    # end for

    for i in range(len(testFunc)):
      func = testFunc[i]
      if func.funcid == funcId:
        return [i,0]
      # end if 
    # end for
    print("Position before error: ", position)
    raise ValueError("Position defined with respect to a variable that is not in the problem functions!")

  else:
    
    funcId = position[0]
    funcId2= position[1]

    for j in range(len(solFunc)):
      func = solFunc[j]
      if func.funcid == funcId2:
        break
      # end if 
    # end for

    for i in range(len(testFunc)):
      func = testFunc[i]
      if func.funcid == funcId:
        break
      # end if 
    # end for
    return [i, j]
  # end if


#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef uint64_t fem_getEqvPositionIndx(list position,list solFunc,list testFunc):
  """
  PURPOSE:    Convert a position given by function ids, into problem local coordinates.

  """
  #***************************************************************************************************

  cdef int64_t i,j
  cdef uint64_t res, funcId, funcId2
  cdef fefunction func

  if len(position)==1:
    funcId = position[0]
    for i in range(len(solFunc)):
      func = solFunc[i]
      if func.funcid == funcId:
        return i
      # end if 
    # end for

    for i in range(len(testFunc)):
      func = solFunc[i]
      if func.funcid == funcId:
        return i
      # end if 
    # end for
    
    raise ValueError("Position defined with respect to a variable that is not in the problem functions!")
  else:
    funcId = position[0]
    funcId2= position[1]
    for j in range(len(solFunc)):
      func = solFunc[j]
      if func.funcid == funcId2:
        break
      # end if 
    # end for

    for i in range(len(testFunc)):
      func = testFunc[i]
      if func.funcid == funcId:
        break
      # end if 
    # end for
    return i*len(testFunc)+ j
  # end if


#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef list fem_getOrderedFuncList(list funcList):
  """
  PURPOSE:    Generate a list of operations such that the elements match one-to-one with the 
              function ids of the element's list.

  """
  #***************************************************************************************************

  cdef fefunction func = funcList[len(funcList)-1]
  cdef list res = [None]*int(func.funcid+1)
  cdef int64_t i
  
  for i in range(len(funcList)):
    func = funcList[i]
    res[func.funcid]=func
  # end for

  return res
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











