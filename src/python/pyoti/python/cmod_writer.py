
from pyoti.core import get_dHelp
import pyoti.core as coti 
import os
import errno

getpath = coti.whereotilib.getpath

h = get_dHelp()

# Create valid characters
valid_chars = []

# Create chars '0' to '9'
for i in range(48,58):
  valid_chars.append(chr(i))
# end for 


# Create chars 'A' to 'Z'
for i in range(65,91):
  valid_chars.append(chr(i))
# end for 

endl = "\n"
imdir_base_name = 'e'
operators = ['*','-','+','/','**']

class writer:

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __init__(self, nbases, order, tab = "  ", coeff_type = "coeff_t", mdual = False,
    type_name = None ):
    """
    PORPUSE:  The porpuse of this class is to create Modules that allow dense OTI structures
              to be manipulated in languages like Fortran and Cython. 
    """

    global imdir_base_name, h
    
    # Only pre-generated data for up to multidual of 10 imbases.
    if mdual and (nbases <= 10) : 
      self.order   = nbases
    elif not mdual:
      self.order   = order
    else:
      raise ValueError("Multidual with more than 10 bases are not supported.")
    # end if

    self.nbases  = nbases
    self.tab     = tab
    self.coeff_t = coeff_type

    self.get = "."
    self.get_ptr = "->"
    self.comment = "// "
    self.endl = ";\n"
    self.real_str = 'r'
    self.new_line_mark = ''
    self.zero = '0.0'
    imdir_base_name = 'e'
    

    if not mdual:
      
      self.type_name = 'onumm'+str(self.nbases)+"n"+str(self.order)+"_t"
      self.type_name_arr = 'oarrm'+str(self.nbases)+"n"+str(self.order)+"_t"
      self.type_name_fe = 'feonumm'+str(self.nbases)+"n"+str(self.order)+"_t"
      self.type_name_fearr = 'feoarrm'+str(self.nbases)+"n"+str(self.order)+"_t"
      self.func_name = 'onumm'+str(self.nbases)+"n"+str(self.order)
      self.func_name_arr = 'oarrm'+str(self.nbases)+"n"+str(self.order)
      self.func_name_fe = 'feonumm'+str(self.nbases)+"n"+str(self.order)
      self.func_name_fearr = 'feoarrm'+str(self.nbases)+"n"+str(self.order)

      self.type_names={}
      self.type_names['r']=self.coeff_t
      self.type_names['o']=self.type_name
      self.type_names['f']=self.type_name_fe
      self.type_names['R']='darr_t'
      self.type_names['O']=self.type_name_arr
      self.type_names['F']=self.type_name_fearr

    else:

      self.type_name = 'mdnum'+str(self.nbases)+"_t"
      self.type_name_arr = 'mdarr'+str(self.nbases)+"_t"
      self.type_name_fe = 'femdnum'+str(self.nbases)+"_t"
      self.type_name_fearr = 'femdarr'+str(self.nbases)+"_t"
      self.func_name = 'mdnum'+str(self.nbases)
      self.func_name_arr = 'mdarr'+str(self.nbases)
      self.func_name_fe = 'femdnum'+str(self.nbases)
      self.func_name_fearr = 'femdarr'+str(self.nbases)

      self.type_names={}
      self.type_names['r']=self.coeff_t
      self.type_names['o']=self.type_name
      self.type_names['f']=self.type_name_fe
      self.type_names['R']='darr_t'
      self.type_names['O']=self.type_name_arr
      self.type_names['F']=self.type_name_fearr
    # end if 


    self.nimdir = h.get_ndir_total(self.nbases, self.order)
    
    # append imaginary direction.
    self.name_imdir = []
    self.name_imdir.append([])
    self.name_imdir[0].append('0')

    self.idx_imdir = []
    self.idx_imdir.append([])
    self.idx_imdir[0].append(0)
    
    self.use_imdir = []
    self.use_imdir.append([])
    self.use_imdir[0].append(True)

    # generate all imaginary directions
    for ordi in range(1,self.order+1):

      self.name_imdir.append([])
      self.use_imdir.append([])
      self.idx_imdir.append([])
      
      nimdir_i = h.get_ndir_order(self.nbases, ordi)

      for j in range(nimdir_i):
        
        str_out = imdir_base_name

        list_bases = h.get_fulldir(j,ordi)
        
        for i in range(list_bases.size):

          str_out += valid_chars[list_bases[i]]

        # end for        

        
        if not mdual:
          self.name_imdir[ordi].append(str_out)
          self.use_imdir[ordi].append(True)
          self.idx_imdir[ordi].append(j)
        else:
          # Check if it is a valid multidual direction.
          str_test = "".join(dict.fromkeys(str_out))
          if str_test == str_out:
            self.name_imdir[ordi].append(str_out)
            self.use_imdir[ordi].append(True)
            self.idx_imdir[ordi].append(j)
          # end if 
      # end for 
    # end for 

    # Precimpute multiplication
    self.mult_res = []
    for ordi in range(1,self.order+1):

      dirs = self.name_imdir[ordi]
      idxi = self.idx_imdir[ordi]

      self.mult_res.append([])
      mults = self.mult_res[-1]
      for j in range(len(dirs)):
        mults.append([]) 
      # end for

      for ordj in range(1, ordi // 2 + 1):
        
        ordk = ordi - ordj

        dirsj = self.name_imdir[ordj]
        dirsk = self.name_imdir[ordk]

        idxj = self.idx_imdir[ordj]
        idxk = self.idx_imdir[ordk]

        for j in range(len(dirsj)):
          for k in range(len(dirsk)):

            i,iordi = h.mult_dir(idxj[j],ordj,idxk[k],ordk)

            if i in idxi:
              ii = idxi.index(i)
              mults[ii].append([ dirsj[j], dirsk[k] ])
              if  ordj != ordk:
                mults[ii].append([ dirsk[k],dirsj[j] ])
              # end if 
            #end if 
          # end for
        # end for 
      # end for 
    # end for 

    self.function_list = []
    self.function_list_header = {}

    self.function_list_header['base'] = []
    self.function_list_header['algebra'] = []

    # needed for c?
    self.overloads = {}

    self.overloads['*'] = []
    self.overloads['+'] = []
    self.overloads['-'] = []
    self.overloads['/'] = []
    self.overloads['='] = []
    self.overloads['pow'] = []
    self.overloads['print'] = []
    self.overloads['transpose'] = []
    self.overloads['matmul'] = []
    self.overloads['sin']   = []
    self.overloads['cos']   = []
    self.overloads['tan']   = []
    self.overloads['asin']  = []
    self.overloads['acos']  = []
    self.overloads['atan']  = []
    self.overloads['sinh']  = []
    self.overloads['cosh']  = []
    self.overloads['tanh']  = []
    self.overloads['asinh'] = []
    self.overloads['acosh'] = []
    self.overloads['atanh'] = []
    self.overloads['log']   = []
    self.overloads['exp']   = []
    self.overloads['log10'] = []


  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def set_type_c(self, level = ""):
    """
    PORPUSE:  The porpuse of this class is to create Modules that allow dense OTI structures
              to be manipulated in languages like Fortran C, C++ and Cython. 
    """
    global h
    str_out = ""

    # -------------------- Scalar
    
    str_out += level + self.comment + "Scalar" + endl
    
    str_out += level + "typedef struct "+"{"+endl
    # Write real part.
    str_out += level + self.tab + self.comment + "Real" + endl
    str_out += level + self.tab + self.coeff_t + " " + self.real_str + self.endl

    for ordi in range(1,self.order+1):

      str_out += level + self.tab + self.comment + "Order " + str(ordi) + endl
      dirs = self.name_imdir[ordi]

      for j in range(len(dirs)):

        str_out += level + self.tab + self.coeff_t + " " + dirs[j] + self.endl

      # end for 

    # end for 

    str_out += level + "} " + self.type_name + self.endl + endl

    # # -------------------- Array
    # str_out += level + self.comment + "Array" + endl
    
    # str_out += level + "typedef struct "+"{"+endl
    # str_out += level + self.tab + self.comment + "Data" + endl
    # str_out += level + self.tab + self.type_name + "* p_data" + self.endl
    # str_out += level + self.tab + "uint64_t nrows" + self.endl
    # str_out += level + self.tab + "uint64_t ncols" + self.endl
    # str_out += level + self.tab + "uint64_t size " + self.endl
    # str_out += level + "} " + self.type_name_arr + self.endl + endl

    # # -------------------- Gauss Structures
    # str_out += level + self.comment + "Gauss Scalar" + endl
    # str_out += level + "typedef struct "+"{"+endl
    # str_out += level + self.tab + self.comment + "Data" + endl
    # str_out += level + self.tab + self.type_name + "* p_data" + self.endl
    # str_out += level + self.tab + "uint64_t nip" + self.endl
    # str_out += level + "} " + self.type_name_fe + self.endl + endl
    

    # # -------------------- Gauss Array
    # str_out += level + self.comment + "Gauss Array" + endl
    # str_out += level + "typedef struct "+"{"+endl
    # str_out += level + self.tab + self.comment + "Data" + endl
    # str_out += level + self.tab + self.type_name_arr + "* p_data" + self.endl
    # str_out += level + self.tab + "uint64_t nrows" + self.endl
    # str_out += level + self.tab + "uint64_t ncols" + self.endl
    # str_out += level + self.tab + "uint64_t size " + self.endl
    # str_out += level + self.tab + "uint64_t nip  " + self.endl
    # str_out += level + "} " +  self.type_name_fearr + self.endl + endl

    return str_out

  #---------------------------------------------------------------------------------------------------  
  
  #***************************************************************************************************
  def multiplication_like_function_ro(self, level = "", f_name = "FUNCTION", lhs_name= "LHS", lhs_ptr=False,
    rhs_name= "RHS", rhs_ptr=False, res_name = "RES", separator = ",", f_open = "(", f_close = ")", 
    addition = " + ", to=False  ):
    """
    PORPUSE:  multiplication like operation between real and OTIs. (LHS is REAL and RHS is OTI)
    """
    global h

    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if

    if rhs_ptr:
      rhs_getter = self.get_ptr
    else:
      rhs_getter = self.get
    # end if
    
    str_out = ""

    str_out += level + self.comment + "Multiplication like function \'"
    str_out += f_name + f_open + lhs_name + separator + rhs_name + f_close
    str_out += "\'\n"


    # Write real part.
    str_out += level +  self.comment + " Real" + self.endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out += f_name + f_open
    str_out +=         lhs_name + separator
    str_out +=         rhs_name + rhs_getter + self.real_str + f_close + self.endl

    for ordi in range(1,self.order+1):

      str_out += level + self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]

      for j in range(len(dirs)):

        str_out += level  + res_name + res_getter + dirs[j] + " = "
        str_out += f_name + f_open
        str_out +=         lhs_name + separator
        str_out +=         rhs_name + rhs_getter + dirs[j] + f_close + self.endl
        
      # end for 
    # end for 

    return str_out

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def multiplication_like_function_or(self, level = "", f_name = "FUNCTION", lhs_name= "LHS", lhs_ptr=False,
    rhs_name= "RHS", rhs_ptr=False, res_name = "RES", separator = ",", f_open = "(", f_close = ")", 
    addition = " + ", to=False  ):
    """
    PORPUSE:  multiplication like operation between real and OTIs. (LHS is REAL and RHS is OTI)
    """
    global h

    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if

    if rhs_ptr:
      rhs_getter = self.get_ptr
    else:
      rhs_getter = self.get
    # end if
    
    str_out = ""

    str_out += level + self.comment + "Multiplication like function \'"
    str_out += f_name + f_open + lhs_name + separator + rhs_name + f_close
    str_out += "\'" + endl


    # Write real part.
    str_out += level + self.comment + " Real" + self.endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out += f_name + f_open
    str_out +=         lhs_name + lhs_getter + self.real_str + separator
    str_out +=         rhs_name + f_close + self.endl

    for ordi in range(1,self.order+1):

      str_out += level +self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]

      for j in range(len(dirs)):

        str_out += level + res_name + res_getter + dirs[j] + " = "
        str_out += f_name + f_open
        str_out +=         lhs_name + lhs_getter + dirs[j] + separator
        str_out +=         rhs_name + f_close + self.endl
        
      # end for 

    # end for 

    return str_out

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def multiplication_like_function_oo(self, level = "", f_name = "FUNCTION", lhs_name= "LHS", lhs_ptr=False,
    rhs_name= "RHS", rhs_ptr=False, res_name = "RES", separator = ",", f_open = "(", f_close = ")", 
    addition = " + ", to=False  ):
    """
    PORPUSE:  Multiplication like operation between OTI and OTI.
    """
    global h
    
    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if

    if rhs_ptr:
      rhs_getter = self.get_ptr
    else:
      rhs_getter = self.get
    # end if

    str_out = ""

    str_out += level + self.comment + " Multiplication like function \'"
    str_out += f_name + f_open + lhs_name + separator + rhs_name + f_close
    str_out += "\'\n"


    # Write real part.
    str_out += level + self.comment + "Real" + self.endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out += f_name + f_open
    str_out +=         lhs_name + lhs_getter + self.real_str + separator
    str_out +=         rhs_name + rhs_getter + self.real_str + f_close + self.endl

    # res = []

    for ordi in range(1,self.order+1):

      str_out += level +self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]
      idxi = self.idx_imdir[ordi]

      mults = []
      for j in range(len(dirs)):
        mults.append([]) 

      # Multiply the different imaginary directions all togeather such that resulting order is 
      # ordi.
      # print("Order "+str(ordi))

      for ordj in range(1, ordi // 2 + 1):
        ordk = ordi - ordj
        # print("  Multiplying order "+str(ordj)+" x order " + str(ordk) )
        dirsj = self.name_imdir[ordj]
        dirsk = self.name_imdir[ordk]

        idxj = self.idx_imdir[ordj]
        idxk = self.idx_imdir[ordk]

        for j in range(len(dirsj)):
          for k in range(len(dirsk)):

            i,iordi = h.mult_dir(idxj[j],ordj,idxk[k],ordk)

            if i in idxi:
              ii = idxi.index(i)
              mults[ii].append([ dirsj[j], dirsk[k] ])
              if  ordj != ordk:
                mults[ii].append([ dirsk[k],dirsj[j] ])
              # end if 
            #end if 
          # end for
        # end for 
      # end for 


      for j in range(len(dirs)):
        # R X IM
        str_out += level + res_name + res_getter + dirs[j] + " = " 
        str_out += f_name + f_open
        str_out +=         lhs_name + lhs_getter + self.real_str + separator
        str_out +=         rhs_name + rhs_getter + dirs[j] 
        str_out += f_close 

        # IM X R
        # Addition
        str_out += addition
        str_out += f_name + f_open
        str_out +=         lhs_name + lhs_getter + dirs[j] + separator
        str_out +=         rhs_name + rhs_getter + self.real_str 
        str_out += f_close 

        mult = mults[j]
        nterms = len(mult)
        for k in range(nterms):

          str_out += addition
          str_out += f_name + f_open
          str_out +=         lhs_name + lhs_getter + mult[k][0] + separator
          str_out +=         rhs_name + rhs_getter + mult[k][1]
          str_out += f_close 

          if ( (k+3)%3 == 0 ) and ( k != ( nterms-1 ) ) :
            str_out += " " + self.new_line_mark + endl
            str_out += level +' '*(len(res_name)+len(dirs[j])+1)
          # end if 


        # end for 
        str_out += self.endl


        
      # end for 

    # end for 

    return str_out

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def truncmul_like_function_oo(self, level = "", f_name = "FUNCTION", lhs_name= "LHS", lhs_ptr=False,
    rhs_name= "RHS", rhs_ptr=False, res_name = "RES", separator = ",", f_open = "(", f_close = ")", 
    addition = " + ", to=False  ):
    """
    PORPUSE:  Multiplication like operation between OTI and OTI.
    """
    global h
    
    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if

    if rhs_ptr:
      rhs_getter = self.get_ptr
    else:
      rhs_getter = self.get
    # end if

    str_out = ""

    if not to:

      str_out += level + res_name+" = "+self.func_name+"_init()" + self.endl
      str_out += endl

    else:

      str_out += level + " (*" + res_name+") = "+self.func_name+"_init()" + self.endl
      str_out += endl

    
    # end if 
    str_out += level + self.comment + " Truncated multiplication like function \'"
    str_out += f_name + f_open + lhs_name + separator + rhs_name + f_close
    str_out += "\'\n"

    for ordi in range(2,self.order+1):

      str_out += level +self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]
      idxi = self.idx_imdir[ordi]

      mults = []
      for j in range(len(dirs)):
        mults.append([]) 

      # Multiply the different imaginary directions all togeather such that resulting order is 
      # ordi.
      # print("Order "+str(ordi))

      for ordj in range(1, ordi // 2 + 1):
        ordk = ordi - ordj
        # print("  Multiplying order "+str(ordj)+" x order " + str(ordk) )
        dirsj = self.name_imdir[ordj]
        dirsk = self.name_imdir[ordk]

        idxj = self.idx_imdir[ordj]
        idxk = self.idx_imdir[ordk]
        
        for j in range(len(dirsj)):
          for k in range(len(dirsk)):

            i,iordi = h.mult_dir(idxj[j],ordj,idxk[k],ordk)

            if i in idxi:
              ii = idxi.index(i)
              mults[ii].append([ dirsj[j], dirsk[k] ])
              if  ordj != ordk:
                mults[ii].append([ dirsk[k],dirsj[j] ])
              # end if 
            #end if 
          # end for
        # end for 
      # end for 

      # res.append(mults)

      for j in range(len(dirs)):
        # # R X IM
        str_out += level + res_name + res_getter + dirs[j] + " = " 
        

        mult = mults[j]
        nterms = len(mult)
        for k in range(nterms):

          str_out += addition
          str_out += f_name + f_open
          str_out +=         lhs_name + lhs_getter + mult[k][0] + separator
          str_out +=         rhs_name + rhs_getter + mult[k][1]
          str_out += f_close 

          if ( (k+1)%3 == 0 ) and ( k != ( nterms-1 ) ) :
            str_out += " " + self.new_line_mark + endl
            str_out += level +' '*(len(res_name)+len(dirs[j])+1)
          # end if 


        # end for 
        str_out += self.endl


        
      # end for 

    # end for 

    return str_out

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def gem_like_function_oo(self, level = "", f_name = "FUNCTION", a_name= "a", a_ptr=False,
    b_name= "b", b_ptr=False, c_name= "c", c_ptr=False, res_name = "res", separator = ",", 
    f_open = "(", f_close = ")",  addition = " + ", to=False  ):
    """
    PORPUSE:  Multiplication like operation between OTI and OTI.
    """
    global h

    
    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if a_ptr:
      a_getter = self.get_ptr
    else:
      a_getter = self.get
    # end if

    if b_ptr:
      b_getter = self.get_ptr
    else:
      b_getter = self.get
    # end if

    if c_ptr:
      c_getter = self.get_ptr
    else:
      c_getter = self.get
    # end if


    str_out = ""

    str_out += level + self.comment + " General multiplication like function \'"
    str_out += f_name + f_open + a_name + separator + b_name + f_close
    str_out += addition + c_name
    str_out += "\'\n"


    # Write real part.
    str_out += level + self.comment + "Real" + self.endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out +=         c_name + c_getter + self.real_str + addition
    str_out += f_name + f_open
    str_out +=         a_name + a_getter + self.real_str + separator
    str_out +=         b_name + b_getter + self.real_str + f_close + self.endl

    # res = []

    for ordi in range(1,self.order+1):

      str_out += level +self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]
      idxi = self.idx_imdir[ordi]

      mults = []
      for j in range(len(dirs)):
        mults.append([]) 

      # Multiply the different imaginary directions all togeather such that resulting order is 
      # ordi.
      # print("Order "+str(ordi))

      for ordj in range(1, ordi // 2 + 1):
        ordk = ordi - ordj
        # print("  Multiplying order "+str(ordj)+" x order " + str(ordk) )
        dirsj = self.name_imdir[ordj]
        dirsk = self.name_imdir[ordk]

        idxj = self.idx_imdir[ordj]
        idxk = self.idx_imdir[ordk]
        
        for j in range(len(dirsj)):
          for k in range(len(dirsk)):

            i,iordi = h.mult_dir(idxj[j],ordj,idxk[k],ordk)

            if i in idxi:
              ii = idxi.index(i)
              mults[ii].append([ dirsj[j], dirsk[k] ])
              if  ordj != ordk:
                mults[ii].append([ dirsk[k],dirsj[j] ])
              # end if 
            #end if 
          # end for
        # end for 
      # end for 

      # res.append(mults)

      for j in range(len(dirs)):
        # R X IM
        str_out += level + res_name + res_getter + dirs[j] + " = " 
        str_out +=         c_name + c_getter + dirs[j] + addition
        str_out += f_name + f_open
        str_out +=         a_name + a_getter + self.real_str + separator
        str_out +=         b_name + b_getter + dirs[j] 
        str_out += f_close 

        # IM X R
        # Addition
        str_out += addition
        str_out += f_name + f_open
        str_out +=         a_name + a_getter + dirs[j] + separator
        str_out +=         b_name + b_getter + self.real_str 
        str_out += f_close 

        mult = mults[j]
        nterms = len(mult)
        for k in range(nterms):

          str_out += addition
          str_out += f_name + f_open
          str_out +=         a_name + a_getter + mult[k][0] + separator
          str_out +=         b_name + b_getter + mult[k][1]
          str_out += f_close 

          if ( (k+3)%3 == 0 ) and ( k != ( nterms-1 ) ) :
            str_out += " " + self.new_line_mark + endl
            str_out += level +' '*(len(res_name)+len(dirs[j])+1)
          # end if 


        # end for 
        str_out += self.endl


        
      # end for 

    # end for 

    return str_out

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def gem_like_function_ro(self, level = "", f_name = "FUNCTION", a_name= "a", a_ptr=False,
    b_name= "b", b_ptr=False, c_name= "c", c_ptr=False, res_name = "res", separator = ",", 
    f_open = "(", f_close = ")",  addition = " + ", to=False  ):
    """
    PORPUSE:  Multiplication like operation between OTI and OTI.
    """
    global h

    
    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if a_ptr:
      a_getter = self.get_ptr
    else:
      a_getter = self.get
    # end if

    if b_ptr:
      b_getter = self.get_ptr
    else:
      b_getter = self.get
    # end if

    if c_ptr:
      c_getter = self.get_ptr
    else:
      c_getter = self.get
    # end if


    str_out = ""

    str_out += level + self.comment + " General multiplication like function \'"
    str_out += f_name + f_open + a_name + separator + b_name + f_close
    str_out += addition + c_name
    str_out += "\'\n"


    # Write real part.
    str_out += level + self.comment + "Real" + self.endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out +=         c_name + c_getter + self.real_str + addition
    str_out += f_name + f_open
    str_out +=         a_name + separator
    str_out +=         b_name + b_getter + self.real_str + f_close + self.endl

    # res = []

    for ordi in range(1,self.order+1):

      str_out += level +self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]

      for j in range(len(dirs)):

        str_out += level + res_name + res_getter + dirs[j] + " = "
        str_out +=         c_name + c_getter + dirs[j] + addition
        str_out += f_name + f_open
        str_out +=         a_name + separator
        str_out +=         b_name + b_getter + dirs[j] + f_close + self.endl
        
      # end for 

    # end for 

    return str_out

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  def addition_like_function_oo(self, level = "", f_name = "FUNCTION", lhs_name= "LHS", lhs_ptr=False,
    rhs_name= "RHS", rhs_ptr=False, res_name = "RES", separator = ",", f_open = "(", f_close = ")", 
    addition = " + ", to=False  ):
    """
    PORPUSE:  Addition like function between two OTIs.
    """
    global h
    str_out = ""

    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if

    if rhs_ptr:
      rhs_getter = self.get_ptr
    else:
      rhs_getter = self.get
    # end if
    
    str_out += level + self.comment + "Addition like function \'"
    str_out += f_name + f_open + lhs_name + separator + rhs_name + f_close
    str_out += "\'"+ endl


    # Write real part.
    str_out += level + self.comment + " Real" + endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out += f_name + f_open
    str_out +=         lhs_name + lhs_getter + self.real_str + separator
    str_out +=         rhs_name + rhs_getter + self.real_str + f_close + self.endl


    for ordi in range(1,self.order+1):
      
      str_out += level +self.comment + "Order " + str(ordi) + endl
      dirs = self.name_imdir[ordi]

      for j in range(len(dirs)):
        
        str_out += level + res_name + res_getter + dirs[j] + " = "
        str_out += f_name + f_open
        str_out +=         lhs_name + lhs_getter + dirs[j] + separator
        str_out +=         rhs_name + rhs_getter + dirs[j] + f_close + self.endl
        
      # end for 

    # end for 

    return str_out

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def feval_function_o(self, level = "", lhs_name= "x", lhs_ptr=True,
    feval_name= "feval_re", res_name = "res",  to=False  ):
    """
    PORPUSE:  Generic function evaluation of OTI number.
    """
    global h
    str_out = ""

    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if
    
    str_out += level + self.comment + "feval function" +  endl

    # Required variables 
    str_out += level + self.comment + " Definitions" + endl
    str_out += level + self.coeff_t + " factor=1, coef = 0"+self.endl
    str_out += level + self.type_name + " tmp1, tmp2, deltax = (*"+lhs_name+"), deltax_power = (*"+lhs_name+")"+self.endl
    str_out += level +"deltax.r = " + self.zero + self.endl
    str_out += level +"deltax_power.r = " + self.zero + self.endl

    str_out += level + self.func_name + "_set_r("+self.zero+", "
    
    if not to:
      str_out+="&"
    # end if 
    str_out += res_name
    str_out += ")"+self.endl
    
    # Write real part.
    str_out += level + self.comment + " Real" + endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out += feval_name+"[0]" + self.endl
    
    for ordi in range(1,self.order+1):
      
      str_out += level + self.comment + "Order " + str(ordi) + endl
      dirs = self.name_imdir[ordi]

      str_out += level + "factor *="+str(ordi)+self.endl
      str_out += level + "coef    = "+feval_name+"["+str(ordi)+"]/ factor;"+self.endl
      
      str_out += level 
      
      str_out += self.func_name + "_gem_ro_to( coef, &deltax_power, "
      if not to:
        str_out+="&"
      # end if  
      str_out += res_name + ', '
      if not to:
        str_out+="&"
      # end if  
      str_out += res_name  +  ")" + self.endl

      if ordi != self.order:
        str_out += level +"deltax_power = " + self.func_name + "_mul_oo(&deltax_power,&deltax)" + self.endl
      # end if 

    # end for 

    return str_out

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def addition_like_function_ro(self, level = "", f_name = "FUNCTION", lhs_name= "LHS", lhs_ptr=False,
    rhs_name= "RHS", rhs_ptr=False, res_name = "RES", separator = ",", f_open = "(", f_close = ")", 
    addition = " + ", to=False  ):
    """
    PORPUSE:  Addition like function between two OTIs.
    """
    global h
    str_out = ""

    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if

    if rhs_ptr:
      rhs_getter = self.get_ptr
    else:
      rhs_getter = self.get
    # end if

    str_out += level + self.comment + "Addition like function \'"
    str_out += f_name + f_open + lhs_name + separator + rhs_name + f_close
    str_out += "\'\n"


    # Write real part.
    str_out += level + self.comment + "Real" + self.endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out += f_name + f_open
    str_out +=         lhs_name + separator
    str_out +=         rhs_name + rhs_getter + self.real_str + f_close + self.endl


    for ordi in range(1,self.order+1):
      
      str_out += level +self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]

      for j in range(len(dirs)):
        
        str_out += level + res_name + res_getter + dirs[j] + " = "
        str_out += separator + rhs_name + rhs_getter + dirs[j] + self.endl
        
      # end for 

    # end for 

    return str_out

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def addition_like_function_or(self, level = "", f_name = "FUNCTION", lhs_name= "LHS", lhs_ptr=False,
    rhs_name= "RHS", rhs_ptr=False, res_name = "RES", separator = ",", f_open = "(", f_close = ")", 
    addition = " + ", to=False  ):
    """
    PORPUSE:  Addition like function between two OTIs.
    """
    global h
    str_out = ""

    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if

    if rhs_ptr:
      rhs_getter = self.get_ptr
    else:
      rhs_getter = self.get
    # end if

    str_out += level + self.comment + "Addition like function \'"
    str_out += f_name + f_open + lhs_name + separator + rhs_name + f_close
    str_out += "\'\n"


    # Write real part.
    str_out += level + self.comment + "Real" + self.endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out += f_name + f_open
    str_out +=         lhs_name + lhs_getter + self.real_str + separator
    str_out +=         rhs_name + f_close + self.endl


    for ordi in range(1,self.order+1):
      
      str_out += level +self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]

      for j in range(len(dirs)):
        
        str_out += level + res_name + res_getter + dirs[j] + " = "
        str_out +=         lhs_name + lhs_getter + dirs[j] + self.endl
        
      # end for 

    # end for 

    return str_out

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def assignr_like_function(self, level = "", f_name = "FUNCTION", lhs_name= "LHS",lhs_ptr=True,
    res_name = "RES", f_open = "(", f_close = ")", to=False):
    """
    PORPUSE:  Addition like function between two OTIs.
    """
    global h
    str_out = ""

    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if 

    str_out += level + self.comment + "Assign like function \'"
    str_out += f_name + f_open + lhs_name + f_close
    str_out += "\'\n"


    # Write real part.
    str_out += level + self.comment + "Real" + self.endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out += f_name + f_open
    str_out +=         lhs_name + f_close + self.endl


    for ordi in range(1,self.order+1):
      
      str_out += level +self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]

      for j in range(len(dirs)):
        
        str_out += level + res_name + res_getter + dirs[j] + " = "+ self.zero + self.endl
        
      # end for 

    # end for 

    return str_out
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def init_like_function(self, level = "", res_name = "RES"):
    """
    PORPUSE:  Addition like function between two OTIs.
    """
    global h
    res_getter = self.get
    str_out = ""
    str_out += level + self.comment + "Init function\n"

    # Write real part.
    str_out += level + self.comment + "Real" + self.endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out += self.zero + self.endl
    for ordi in range(1,self.order+1):
      
      str_out += level +self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]

      for j in range(len(dirs)):
        
        str_out += level + res_name + res_getter + dirs[j] + " = "+ self.zero + self.endl
        
      # end for 

    # end for 

    return str_out
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def assigno_like_function(self, level = "", f_name = "FUNCTION", lhs_name= "LHS",lhs_ptr=True,
    res_name = "RES", f_open = "(", f_close = ")", to=False, order_specific = False ):
    """
    PORPUSE:  Addition like function between two OTIs.
    """
    global h
    str_out = ""

    if to:
      res_getter = self.get_ptr
      res_prev = '*'
    else:
      res_getter = self.get
      res_prev = ''
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if 

    if order_specific:
      str_out += level + res_prev + res + " = "+self.func_name+"_init()"+self.endl
      str_out += level + "switch( order ){" + endl
      str_out += level + tab + "case 0:" + endl


    str_out += level + self.comment + "Assign like function \'"
    str_out += f_name + f_open + lhs_name + f_close
    str_out += "\'\n"


    # Write real part.
    str_out += level + 2*tab + self.comment + "Real" + self.endl
    str_out += level + 2*tab + res_name + res_getter + self.real_str + " = "
    str_out += f_name + f_open
    str_out +=         lhs_name + lhs_getter + self.real_str + f_close + self.endl


    for ordi in range(1,self.order+1):
      
      str_out += level +self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]

      for j in range(len(dirs)):
        
        str_out += level + res_name + res_getter + dirs[j] + " = "
        str_out += f_name + f_open
        str_out += lhs_name + lhs_getter + dirs[j] 
        str_out += f_close
        str_out += self.endl
        
      # end for 

    # end for 

    return str_out
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def getim_scalar_function(self, tab = "  ",level = "", lhs_name= "lhs", lhs_ptr=True,
    f_name = "FUNCTION", res_name = "res", f_open = "(", f_close = ")", to=False):
    """
    PORPUSE:  getim like function between two OTIs.
    """
    global h
    str_out = ""
    if to:
      res_getter = '*'
    else:
      res_getter = ''
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if 

    str_out += level + self.comment + "Get Imaginary coefficient." + endl
    str_out += level + res_getter + res_name + " = " + self.zero + self.endl

    # Write real part.
    str_out += level + self.comment + "Real" + self.endl
    str_out += level + "switch (order){"+endl
    str_out += level + tab +  "case 0:" +endl
    str_out += level + 2*tab + res_getter + res_name + " = " +lhs_name + lhs_getter + self.real_str + self.endl
    str_out += level + 2*tab + "break" + self.endl
    

    for ordi in range(1,self.order+1):
      str_out += level + tab + "case "+str(ordi)+":"+endl
      
      dirs = self.name_imdir[ordi]
      levelj = level + 2*tab 
      str_out += levelj + "switch (idx){"+endl 
      for j in range(len(dirs)):
        
        str_out += levelj+tab+ "case "+str(j) + ":" + endl
        str_out += levelj+2*tab+res_getter + res_name + " = " + lhs_name + lhs_getter + dirs[j] + self.endl
        str_out += levelj+2*tab+"break"+self.endl
      # end for 
      
      str_out += levelj + "}" + endl
      str_out += levelj + "break"+self.endl
    # end for 

    str_out += level + "}"

    return str_out


  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def setim_scalar_function(self, tab = "  ",level = "", lhs_name= "lhs", lhs_ptr=True,
    f_name = "FUNCTION", res_name = "res", f_open = "(", f_close = ")", to=False):
    """
    PORPUSE:  getim like function between two OTIs.
    """
    global h
    str_out = ""
    
    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if 

    str_out += level + self.comment + "Set Imaginary coefficient." + endl
    # str_out += level + "*" + res_name + " = " + self.zero + self.endl

    # Write real part.
    str_out += level + self.comment + "Real" + self.endl
    str_out += level + "switch (order){"+endl
    str_out += level + tab +  "case 0:" +endl
    str_out += level + 2*tab + lhs_name + lhs_getter + self.real_str + " = " + 'val'  + self.endl
    str_out += level + 2*tab + "break" + self.endl
    

    for ordi in range(1,self.order+1):
      str_out += level + tab + "case "+str(ordi)+":"+endl
      
      dirs = self.name_imdir[ordi]
      levelj = level + 2*tab 
      str_out += levelj + "switch (idx){"+endl 
      for j in range(len(dirs)):
        
        str_out += levelj+tab+ "case "+str(j) + ":" + endl
        str_out += levelj+2*tab+lhs_name + lhs_getter + dirs[j] + " = " +  'val'  + self.endl
        str_out += levelj+2*tab+"break"+self.endl
      # end for 
      
      str_out += levelj + "}" + endl
      str_out += levelj + "break"+self.endl
    # end for 

    str_out += level + "}"

    return str_out


  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def pprint_scalar_function(self, level = "", lhs_name= "lhs", fmt = "%.8g",tab = "  "):
    """
    PORPUSE:  getim like function between two OTIs.
    """

    global h

    str_out = ""
    fmt_im = fmt.replace("%","%+")

    str_out += level + self.comment + "Print function." + endl

    # Write real part.
    str_out += level + self.comment + " Real" + self.endl
    str_out += level + 'printf(\"'+fmt+'\",'
    str_out += lhs_name + self.get_ptr + self.real_str
    str_out += ')'+self.endl
    
    for ordi in range(1,self.order+1):

      str_out += level + self.comment + " Order " + str(ordi)+ self.endl
      dirs = self.name_imdir[ordi]
            
      for j in range(len(dirs)):        
        
        str_out += level + 'printf(\" '+fmt_im+'*' + dirs[j] +'\",'
        str_out += lhs_name + self.get_ptr + dirs[j] 
        str_out += ')'+self.endl
          
      # end for 
    # end for 

    str_out += level + 'printf(\"\\n\")'+self.endl

    return str_out


  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def negation_like_function(self, level = "", f_name = "FUNCTION", lhs_name= "LHS", lhs_ptr=False,
    res_name = "RES", f_open = "(", f_close = ")", to=False):
    """
    PORPUSE:  Negation like function between two OTIs.
    """
    global h
    
    if to:
      res_getter = self.get_ptr
    else:
      res_getter = self.get
    # end if 

    if lhs_ptr:
      lhs_getter = self.get_ptr
    else:
      lhs_getter = self.get
    # end if 


    str_out = ""


    str_out += level + self.comment + "Negation like function \'"
    str_out += f_name + f_open + lhs_name + f_close
    str_out += "\'\n"


    # Write real part.
    str_out += level + self.comment + "Real" + self.endl
    str_out += level + res_name + res_getter + self.real_str + " = "
    str_out += f_name + f_open
    str_out +=         lhs_name + lhs_getter + self.real_str + f_close + self.endl


    for ordi in range(1,self.order+1):
      
      str_out += level +self.comment + "Order " + str(ordi) + self.endl
      dirs = self.name_imdir[ordi]

      for j in range(len(dirs)):
        
        str_out += level + res_name + res_getter + dirs[j] + " = "
        str_out += f_name + f_open
        str_out +=         lhs_name + lhs_getter + dirs[j] + f_close + self.endl
        
      # end for 

    # end for 

    return str_out


  #--------------------------------------------------------------------------------------------------- 

  

  #***************************************************************************************************
  def write_scalar_function_print(self, level = 0, tab = " "):

    str_out = ""
    leveli = level

    
    lhs = "lhs"
  
    f_prev = self.func_name
    
    lhs_t = self.type_name
    
    func_name = f_prev + "_print" 

    # Write function start.
    str_out += leveli*tab
    leveli += 1
    

    
    func_header  = "void " + func_name + "("
    func_header += leveli*tab + lhs_t + "* "+ lhs 
    func_header += ")"

    self.function_list.append(func_header)
    self.function_list_header['base'].append(func_header)

    str_out += func_header +"{"+endl
    str_out += endl

    str_out += self.pprint_scalar_function( tab = tab,level = leveli*tab,  lhs_name = lhs)

    str_out += endl


    # Write function end.
    leveli -= 1
    str_out += leveli*tab + '}' + endl

    return str_out
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def write_scalar_getitem(self, function_name = "get_item", is_elemental = True, level = 0, tab = " ", 
    f_name = "FUNCTION",  separator = ",", lhs_type= "O", lhs_ptr = False,
    f_open = "(", f_close = ")", addition = " + ",generator = None, to = False,
    overload = None, write_charact=True ):
    """
    Write Univariate function.

    This module writes the definition of the function, its inputs and output. The generator defines the
    operations within the function block.

    """

    str_out = ""
    leveli = level

    res = "res"
    lhs = "lhs"

    f_prev = self.func_name
    
    func_name = f_prev + "_" + function_name 
    
    # Write function start.
    str_out += leveli*tab
    leveli += 1
    
    func_header = ''

    func_header += self.coeff_t + " "

    func_header +=  func_name + "(" + "imdir_t idx, ord_t order, "
    func_header +=  self.type_name + "* " + lhs
    func_header += ")"

    self.function_list.append(func_header)
    self.function_list_header['base'].append(func_header)

    str_out += func_header +"{"+endl+endl

    str_out += leveli*tab + self.coeff_t + " " + res + self.endl
    str_out += endl

    str_out += generator(level = leveli*tab, res_name = res, lhs_name=lhs, lhs_ptr=True, tab= tab)
    

    str_out += endl
    # Write function end.

    str_out += leveli*tab + 'return ' + res + self.endl + endl
    leveli -= 1
    str_out += leveli*tab + '}' + endl

    return str_out
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def write_scalar_feval(self, function_name = "feval", is_elemental = True, level = 0, tab = " ", 
    f_name = "FUNCTION",  separator = ",", lhs_type= "O", lhs_ptr = False,
    f_open = "(", f_close = ")", addition = " + ", to = False,
    overload = None, write_charact=True ):
    """
    Write Univariate function.

    This module writes the definition of the function, its inputs and output. The generator defines the
    operations within the function block.

    """

    str_out = ""
    leveli = level

    res = "res"
    lhs = "x"

    lhs_t = self.type_names[lhs_type]
    f_post = lhs_type
   
    if lhs_ptr == True:
      lhs_t += '*'
    # end if

    f_prev = self.func_name
    
    func_name = f_prev + "_" + function_name 
    
    # Write function start.
    str_out += leveli*tab
    leveli += 1
    
    func_header = ''

    if to:
      func_header += 'void '
      func_name += '_to'
    else:
      func_header += self.type_name + " "
    # end if 

    func_header +=  func_name + "(" + self.coeff_t + "* feval_re, "
    func_header +=  lhs_t + " " + lhs

    if to:
      func_header += ", "
      func_header += self.type_name+"* "+res
    # end if 

    func_header += ")"

    self.function_list.append(func_header)
    self.function_list_header['algebra'].append(func_header)

    str_out += func_header +"{"+endl+endl
    
    if not to:

      str_out += leveli*tab + self.type_name + " " + res + self.endl
      str_out += endl
    
    # end if 

    str_out += self.feval_function_o(level = leveli*tab, res_name = res, lhs_name=lhs, lhs_ptr=True, to=to)
    

    str_out += endl
    # Write function end.

    if to:
      
      leveli -= 1
      str_out += leveli*tab + '}' + endl

    else :

      str_out += leveli*tab + 'return ' + res + self.endl + endl
      leveli -= 1
      str_out += leveli*tab + '}' + endl
    # end if

    return str_out
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def write_scalar_setitem(self, function_name = "setim", is_elemental = True, level = 0, tab = " ", 
    f_name = "FUNCTION",  separator = ",", lhs_type= "O", lhs_ptr = False,
    f_open = "(", f_close = ")", addition = " + ", 
    overload = None, write_charact=True ):
    """
    Write Univariate function.

    This module writes the definition of the function, its inputs and output. The generator defines the
    operations within the function block.

    """

    str_out = ""
    leveli = level

    res = "res"
    lhs = "x"

    to = False

    lhs_t = self.type_names[lhs_type]
    f_post = lhs_type
   
    if lhs_ptr == True:
      lhs_t += '*'
    # end if

    f_prev = self.func_name
    
    func_name = f_prev + "_" + function_name 
    
    # Write function start.
    str_out += leveli*tab
    leveli += 1
    
    func_header = ''

    func_header += 'void '

    func_header +=  func_name + "(" +self.coeff_t+ " val, imdir_t idx, ord_t order, "
    func_header +=  self.type_name + "* " + lhs

    func_header += ")"

    self.function_list.append(func_header)
    self.function_list_header['base'].append(func_header)

    str_out += func_header +"{"+endl+endl
    


    str_out += self.setim_scalar_function(level = leveli*tab, res_name = res, lhs_name=lhs, lhs_ptr=True, to=to)

    str_out += endl
    # Write function end.
      
    leveli -= 1
    str_out += leveli*tab + '}' + endl


    return str_out
  #--------------------------------------------------------------------------------------------------- 



  #***************************************************************************************************
  def write_scalar_init(self, function_name = "init", level = 0, tab = " ", generator = None):
    """
    Write Univariate function.

    This module writes the definition of the function, its inputs and output. The generator defines the
    operations within the function block.

    """

    str_out = ""
    leveli = level

    res = "res"
    f_prev = self.func_name
    
    func_name = f_prev + "_" + function_name 
    
    # Write function start.
    str_out += leveli*tab
    leveli += 1
    
    func_header = ''


    func_header += self.type_name + " "


    func_header +=  func_name + "("    
    func_header += ")"

    self.function_list.append(func_header)
    self.function_list_header['base'].append(func_header)

    str_out += func_header +"{"+endl+endl

    str_out += leveli*tab + self.type_name + " " + res + self.endl
    str_out += endl

    str_out += generator(level = leveli*tab, res_name = res)

    str_out += endl
    # Write function end.

    str_out += leveli*tab + 'return ' + res + self.endl + endl
    leveli -= 1
    str_out += leveli*tab + '}' + endl

    return str_out
  #--------------------------------------------------------------------------------------------------- 




  #***************************************************************************************************
  def write_scalar_univar(self, function_name = "NEG", is_elemental = True, level = 0, tab = " ", 
    f_name = "FUNCTION",  separator = ",", lhs_type= "O", lhs_ptr = False,
    f_open = "(", f_close = ")", addition = " + ",generator = None, to = False,
    overload = None, write_charact=True, header = 'base' ):

    """
    Write Univariate function.

    This module writes the definition of the function, its inputs and output. The generator defines the
    operations within the function block.

    """

    str_out = ""
    leveli = level
    f_post = 'o'

    
    lhs = "lhs"
    rhs = "rhs"
    res = "res"
    f_prev = self.func_name
    lhs_t = self.type_names[lhs_type]
    f_post = lhs_type
   
    if lhs_ptr == True:
      lhs_t += '*'
    # end if


    func_name = f_prev + "_" + function_name 
    if write_charact:
      func_name += "_" + f_post
    # end if 


    # Write function start.
    str_out += leveli*tab
    leveli += 1
    
    func_header = ''

    if to:
      func_header += 'void '
      if function_name != 'set':
        func_name += '_to'
      # end if 
    else:
      func_header += self.type_name + " "
    # end if 

    func_header +=  func_name + "("
    func_header += leveli*tab + lhs_t + " "+ lhs 
    
    if to:
      func_header += ", "
      func_header += self.type_name+"* "+res
    # end if 
    
    func_header += ")"

    self.function_list.append(func_header)
    self.function_list_header[header].append(func_header)

    str_out += func_header +"{"+endl+endl

    if not to:

      str_out += leveli*tab + self.type_name + " " + res + self.endl
      str_out += endl
    
    # end if 

    str_out += generator(f_name = f_name, level = leveli*tab, f_open = f_open, 
      f_close =f_close, res_name = res, lhs_name = lhs, lhs_ptr=lhs_ptr, to=to)


    str_out += endl
    # Write function end.

    
    if to:
      
      leveli -= 1
      str_out += leveli*tab + '}' + endl

    else :

      str_out += leveli*tab + 'return ' + res + self.endl + endl
      leveli -= 1
      str_out += leveli*tab + '}' + endl
    # end if

    return str_out
  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def write_scalar_function(self, function_name = "FUNCTION", is_elemental = True, level = 0, tab = " ", 
    f_name = "FUNCTION", lhs_type= "O", lhs_ptr=False, rhs_type= "O", rhs_ptr=False, separator = ",", 
    f_open = "(", f_close = ")", addition = " + ",generator = None, to=False,
    overload = None, write_charact=True, header = 'base' ):

    str_out = ""
    leveli = level

    lhs = "lhs"
    rhs = "rhs"
    res = "res"

    f_prev = self.func_name
    
    lhs_t  = self.type_names[lhs_type]
    f_post = lhs_type
  
    if lhs_ptr == True:
      lhs_t += '*'
    # end if

    rhs_t  = self.type_names[rhs_type]
    f_post += rhs_type
  
    if rhs_ptr == True:
      rhs_t += '*'
    # end if

    func_name = f_prev + "_" + function_name 
    
    if write_charact:
      func_name += "_"+ f_post
    # end if 

    # Write function start.
    str_out += leveli*tab
    leveli += 1
    
    func_header = ''

    if to:
      func_header += 'void '
      func_name += '_to'
    else:
      func_header += self.type_name + " "
    # end if 

    func_header += func_name + "("
    func_header += leveli*tab + lhs_t + " "+ lhs + ','
    func_header += leveli*tab + rhs_t + " "+ rhs 

    if to:
      func_header += ", "
      func_header += self.type_name+"* "+res
    # end if 

    func_header += ")"

    self.function_list.append(func_header)
    self.function_list_header[header].append(func_header)
    
    str_out += func_header +"{"+endl

    if not to:
      str_out += leveli*tab + self.type_name + " " + res + self.endl
      str_out += endl
    # end if 

    str_out += generator(f_name = f_name, separator = separator,  
               level = leveli*tab, f_open = f_open, f_close =f_close, res_name = res,
               lhs_name = lhs, lhs_ptr=lhs_ptr, rhs_name=rhs, rhs_ptr=rhs_ptr, to=to)


    str_out += endl
    # Write function end.

    if not to:  
      str_out += leveli*tab + 'return ' + res + self.endl + endl
    # end if

    leveli -= 1
    str_out += leveli*tab + '}' + endl

    return str_out
  #--------------------------------------------------------------------------------------------------- 









  #***************************************************************************************************
  def write_scalar_trivar(self, function_name = "FUNCTION", is_elemental = True, level = 0, tab = " ", 
    f_name = "FUNCTION", a_type= "o", a_ptr=False, b_type= "o", b_ptr=False, c_type= "o", c_ptr=False,
    separator = ",", f_open = "(", f_close = ")", addition = " + ",generator = None, to=False,
    overload = None, write_charact=True, header = 'base' ):

    str_out = ""
    leveli = level

    a = "a"
    b = "b"
    c = "c"
    res = "res"

    f_prev = self.func_name
    
    a_t  = self.type_names[a_type]
    f_post = a_type
  
    if a_ptr == True:
      a_t += '*'
    # end if

    b_t  = self.type_names[b_type]
    f_post += b_type
  
    if b_ptr == True:
      b_t += '*'
    # end if

    c_t  = self.type_names[c_type]
    # f_post += c_type
  
    if c_ptr == True:
      c_t += '*'
    # end if

    func_name = f_prev + "_" + function_name 
    
    if write_charact:
      func_name += "_"+ f_post
    # end if 

    # Write function start.
    str_out += leveli*tab
    leveli += 1
    
    func_header = ''

    if to:
      func_header += 'void '
      func_name += '_to'
    else:
      func_header += self.type_name + " "
    # end if 

    func_header += func_name + "("
    func_header += leveli*tab + a_t + " "+ a + ','
    func_header += leveli*tab + b_t + " "+ b + ','
    func_header += leveli*tab + c_t + " "+ c 

    if to:
      func_header += ", "
      func_header += self.type_name+"* "+res
    # end if 

    func_header += ")"

    self.function_list.append(func_header)
    self.function_list_header[header].append(func_header)
    
    str_out += func_header +"{"+endl

    if not to:
      str_out += leveli*tab + self.type_name + " " + res + self.endl
      str_out += endl
    # end if 

    str_out += generator(f_name = f_name, separator = separator,  
               level = leveli*tab, f_open = f_open, f_close =f_close, res_name = res,
               a_name = a, a_ptr=a_ptr, b_name=b, b_ptr=b_ptr, c_name=c, c_ptr=c_ptr, to=to)


    str_out += endl
    # Write function end.

    if not to:  
      str_out += leveli*tab + 'return ' + res + self.endl + endl
    # end if

    leveli -= 1
    str_out += leveli*tab + '}' + endl

    return str_out
  #--------------------------------------------------------------------------------------------------- 












  #***************************************************************************************************
  def write_files(self, modulename = None, tab = '  ', base_dir=''):
    """
    PORPUSE:  Write file of module containing OTI operations.
    """
    
    str_out = ""

    if modulename is not None:
      mname = modulename
    else:
      mname = self.func_name.lower()
    # end if 


    src_path = getpath()+"source_conv/"
    
    print(src_path)

    files=[]
    
    supp_ext = ['h','pxd','pxi','c','pyx']

    # r=>root, d=>directories, f=>files
    
    for r, d, f in os.walk(src_path):
      for item in f:
        ext = item.split('.')[-1]
        if ext in supp_ext:
          files.append(os.path.join(r.replace(src_path,""), item))
        #
      #
    #

    

    # 1. Write module name if in fortran ...
    level = 0

    # Define parameters
    # str_out += self.set_constant_parameters( level = level*tab ) + endl
    dependencies  = ""
    dependencies += self.comment + " Dependencies"+endl
    dependencies += "#include<stdlib.h>"   + endl
    dependencies += "#include<string.h>"   + endl
    dependencies += "#include<stdio.h>"    + endl
    dependencies += "#include<stdint.h>"   + endl
    # dependencies += "#include<stdbool.h>"  + endl
    dependencies += "#include<inttypes.h>" + endl
    dependencies += "#include<math.h>"     + endl + endl

    header_file = ""
    header_file += "#ifndef " + mname.upper() + "__H" + endl
    header_file += "#define " + mname.upper() + "__H" + endl + endl
    header_file += dependencies
    header_file += "typedef uint8_t ord_t;\n"
    header_file += "typedef uint64_t imdir_t ;\n"
    header_file += "typedef double coeff_t ;\n"
    code_file   = '#include\"' + mname + '.h' + '\"' + endl + endl

    # Define type
    header_file += self.set_type_c( level = level*tab ) + endl
    num_struct = self.set_type_c( level = level*tab ) + endl
    # Start writing functions
    

    contents = ""

    contents += self.gen_base_file( level = level, tab = tab)
    contents += self.gen_algebra_file( level = level, tab = tab)
    
    base_str = self.gen_base_file( level = level, tab = tab)
    base_include = self.write_header( header = 'base')
    
    algebra_str = self.gen_algebra_file( level = level, tab = tab)

    algebra_include = self.write_header( header = 'algebra')

    for file in files:
      # Write the header file
      src_file = src_path+file
      print("Processing: ",file)
      f = open(src_file, "r" )
      f_str=f.read()
      f.close()

      exp_file = base_dir+'/'+file.replace("number",mname)
      os.makedirs(os.path.dirname(exp_file), exist_ok=True)
      
      f_exp = f_str.format(  num_type   = self.type_name,       num_func   = self.func_name,       num_pytype   = self.type_name,       num_pyfunc   = self.func_name,       
                   fenum_type = self.type_name_fe,    fenum_func = self.func_name_fe,    fenum_pytype = self.type_name_fe,    fenum_pyfunc = self.func_name_fe,    
                   arr_type   = self.type_name_arr,   arr_func   = self.func_name_arr,   arr_pytype   = self.type_name_arr,   arr_pyfunc   = self.func_name_arr,   
                   fearr_type = self.type_name_fearr, fearr_func = self.func_name_fearr, fearr_pytype = self.type_name_fearr, fearr_pyfunc = self.func_name_fearr, 
                   oti_order=self.order, real_str=self.real_str, module_name = mname, module_name_upper = mname.upper(), base_src = base_str, algebra_src = algebra_str,
                   base_include = base_include, algebra_include = algebra_include, utils_include="",  num_struct=num_struct)

      f = open(exp_file, "w" )

      
      f.write(f_exp)
      f.close()
    

    # Define Overloads

    code_file += contents

    file_name_str = os.path.join(base_dir,mname)+"/base.c"
    # self.check_file_and_dirs(file_name_str)

    # # Write the code file
    # f = open(file_name_str, "w" )

    # f.write(code_file)

    # f.close()


    for funct in self.function_list:
      header_file += funct+";"+endl
    # end for 

    header_file += endl
    header_file += "#endif"



    # file_name_str = os.path.join(base_dir,mname)+"/base.h"
    # self.check_file_and_dirs(file_name_str)

    # # Write the header file
    # f = open(file_name_str, "w" )
    # f.write(header_file)

    # f.close()

    # return str_out
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def write_header(self, header = ''):
    
    header_file = ''
    for funct in self.function_list_header[header]:
      header_file += funct+";"+endl
    # end for 

    return header_file
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def check_file_and_dirs(self, filename):
    dir_name = os.path.dirname(filename)
    if dir_name is not '':
      if not os.path.exists(dir_name):
        try:
          os.makedirs(dir_name)
        except OSError as exc: # Guard against race condition
          if exc.errno != errno.EEXIST:
              raise

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def gen_base_file(self, level = 0, tab = ' '):
    

    contents = ""
    
    # Init function
    contents+=self.write_scalar_init(function_name = "init", level = level, tab = tab, 
      generator = self.init_like_function)
    contents += endl

    # Standard assignment
    contents += self.write_scalar_univar(function_name = "create", is_elemental = True, level = level, 
      tab = tab, lhs_type = 'r', f_name = "",   f_open = "", header = 'base',
      f_close = "", overload = "=",generator = self.assignr_like_function)
    contents += endl

    contents += self.write_scalar_univar(function_name = "set", is_elemental = True, level = level, 
      tab = tab, lhs_type = 'r', f_name = "",   f_open = "", to=True, header = 'base',
      f_close = "", overload = "=",generator = self.assignr_like_function)
    contents += endl

    contents += self.write_scalar_univar(function_name = "set", is_elemental = True, level = level, 
      tab = tab, lhs_type = 'o', lhs_ptr = True, f_name = "",   f_open = "", to=True, header = 'base',
      f_close = "", overload = "=",generator = self.assigno_like_function)
    contents += endl

    # Get item
    contents += self.write_scalar_getitem(function_name = "get_item",level = level, tab = tab, 
      lhs_type = 'o', lhs_ptr=True, generator = self.getim_scalar_function)
    contents += endl 

    # Set item
    contents += self.write_scalar_setitem(function_name = "set_item",level = level, tab = tab, 
      lhs_type = 'o', lhs_ptr=True)
    contents += endl 

    # Copy functions
    contents += self.write_scalar_univar(function_name = "copy", is_elemental = True, level = level, 
      tab = tab, lhs_type = 'o',lhs_ptr=True, f_name = "",   f_open = "",  to=False,header = 'base',
      f_close = "", overload = "=",generator = self.assigno_like_function, write_charact=False)
    contents += endl
    contents += self.write_scalar_univar(function_name = "copy", is_elemental = True, level = level, 
      tab = tab, lhs_type = 'o',lhs_ptr=True, f_name = "",   f_open = "", to=True,header = 'base',
      f_close = "", overload = "=",generator = self.assigno_like_function, write_charact=False)
    contents += endl

    # Print scalar
    contents += self.write_scalar_function_print( level = level, tab = tab)
    contents += endl  

    return contents

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def gen_algebra_file(self, level = 0, tab = ' '):
    

    append_header = 'algebra'

    contents = ""

    # Standard NEGATION
    contents += self.write_scalar_univar(function_name = "neg", is_elemental = True, level = level, 
      tab = tab, f_name = "",   f_open = "-", lhs_type='o', lhs_ptr=True, to=False, write_charact=False,
      f_close = "", overload = "-",generator = self.negation_like_function,header = 'algebra')
    contents += endl

    contents += self.write_scalar_univar(function_name = "neg", is_elemental = True, level = level, 
      tab = tab, f_name = "",   f_open = "-", lhs_type='o', lhs_ptr=True, to=True, write_charact=False,
      f_close = "", overload = "-",generator = self.negation_like_function,header = 'algebra')
    contents += endl


    # Standard ADDITION
    contents += self.write_scalar_function(function_name = "add", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "o", rhs_type= "o", separator = " + ", f_open = "", 
      lhs_ptr=True,rhs_ptr=True,header = 'algebra',
      f_close = "", generator = self.addition_like_function_oo, overload = "+")
    contents += endl

    contents += self.write_scalar_function(function_name = "add", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "o", rhs_type= "o", separator = " + ", f_open = "", 
      lhs_ptr=True,rhs_ptr=True,header = 'algebra',
      f_close = "", generator = self.addition_like_function_oo, overload = "+", to=True)
    contents += endl

    contents += self.write_scalar_function(function_name = "add", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= self.real_str, rhs_type= "o", separator = " + ", f_open = "", 
      lhs_ptr=False, rhs_ptr=True,header = 'algebra',
      f_close = "", generator = self.addition_like_function_ro, overload = "+" )
    contents += endl

    contents += self.write_scalar_function(function_name = "add", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= self.real_str, rhs_type= "o", separator = " + ", f_open = "", 
      lhs_ptr=False, rhs_ptr=True,header = 'algebra',
      f_close = "", generator = self.addition_like_function_ro, overload = "+" , to=True)
    contents += endl


    # Standard SUBTRACTION
    contents += self.write_scalar_function(function_name = "sub", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "o", rhs_type= "o", separator = " - ", f_open = "", 
      lhs_ptr=False, rhs_ptr= True, to=False,header = 'algebra',
      f_close = "", generator = self.addition_like_function_oo, overload = "-" )
    contents += endl

    contents += self.write_scalar_function(function_name = "sub", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "o", rhs_type= "o", separator = " - ", f_open = "", 
      lhs_ptr=False, rhs_ptr= True, to=True,header = 'algebra',
      f_close = "", generator = self.addition_like_function_oo, overload = "-" )
    contents += endl

    contents += self.write_scalar_function(function_name = "sub", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type=  "r", rhs_type= "o", separator = " - ", 
      lhs_ptr=False, rhs_ptr= True, to=False,header = 'algebra',
      f_open = "", f_close = "", generator = self.addition_like_function_ro, overload = "-" )
    contents += endl

    contents += self.write_scalar_function(function_name = "sub", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type=  "r", rhs_type= "o", separator = " - ", 
      lhs_ptr=False, rhs_ptr= True, to=True,header = 'algebra',
      f_open = "", f_close = "", generator = self.addition_like_function_ro, overload = "-" )
    contents += endl

    contents += self.write_scalar_function(function_name = "sub", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "o", rhs_type=  "r", separator = " - ", f_open = "", 
      lhs_ptr=True, rhs_ptr= False, to=False,header = 'algebra',
      f_close = "", generator = self.addition_like_function_or, overload = "-")
    contents += endl

    contents += self.write_scalar_function(function_name = "sub", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "o", rhs_type=  "r", separator = " - ", f_open = "", 
      lhs_ptr=True, rhs_ptr= False, to=True,header = 'algebra',
      f_close = "", generator = self.addition_like_function_or, overload = "-")
    contents += endl












    # Standard MULTIPLICATION
    contents += self.write_scalar_function(function_name = "mul", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "o", rhs_type= "o", separator = " * ", f_open = "", 
      lhs_ptr=True, rhs_ptr= True, to=False,header = 'algebra',
      f_close = "", generator = self.multiplication_like_function_oo, overload = "*" )
    contents += endl

    contents += self.write_scalar_function(function_name = "mul", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "o", rhs_type= "o", separator = " * ", f_open = "", 
      lhs_ptr=True, rhs_ptr= True, to=True,header = 'algebra',
      f_close = "", generator = self.multiplication_like_function_oo, overload = "*" )
    contents += endl

    contents += self.write_scalar_function(function_name = "mul", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "r", rhs_type= "o", separator = " * ", f_open = "", 
      lhs_ptr=False, rhs_ptr= True, to=False,header = 'algebra',
      f_close = "", generator = self.multiplication_like_function_ro, overload = "*" )
    contents += endl

    contents += self.write_scalar_function(function_name = "mul", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "r", rhs_type= "o", separator = " * ", f_open = "", 
      lhs_ptr=False, rhs_ptr= True, to=True,header = 'algebra',
      f_close = "", generator = self.multiplication_like_function_ro, overload = "*" )
    contents += endl

      

    # Truncated MULTIPLICATION
    contents += self.write_scalar_function(function_name = "trunc_mul", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "o", rhs_type= "o", separator = " * ", f_open = "", 
      lhs_ptr=True, rhs_ptr= True, to=False,header = 'algebra',
      f_close = "", generator = self.truncmul_like_function_oo, overload = "*" )
    contents += endl

    contents += self.write_scalar_function(function_name = "trunc_mul", is_elemental = True, level = level, 
      tab = tab, f_name = "", lhs_type= "o", rhs_type= "o", separator = " * ", f_open = "", 
      lhs_ptr=True, rhs_ptr= True, to=True,header = 'algebra',
      f_close = "", generator = self.truncmul_like_function_oo, overload = "*" )
    contents += endl





    # General multiplication a * b + c
    contents += self.write_scalar_trivar(function_name = "gem", is_elemental = True, level = level, 
      tab = tab, f_name = "", a_type= "o", b_type= "o", c_type = "o", 
      a_ptr = True, b_ptr = True, c_ptr = True, to=False, 
      separator = " * ", f_open = "",header = 'algebra', 
      f_close = "", generator = self.gem_like_function_oo, overload = "*", write_charact=True )
    contents += endl

    contents += self.write_scalar_trivar(function_name = "gem", is_elemental = True, level = level, 
      tab = tab, f_name = "", a_type= "o", b_type= "o", c_type = "o", 
      a_ptr = True, b_ptr = True, c_ptr = True, to=True, 
      separator = " * ", f_open = "",header = 'algebra', 
      f_close = "", generator = self.gem_like_function_oo, overload = "*", write_charact=True )
    contents += endl

    contents += self.write_scalar_trivar(function_name = "gem", is_elemental = True, level = level, 
      tab = tab, f_name = "", a_type= "r", b_type= "o", c_type = "o", 
      a_ptr = False, b_ptr = True, c_ptr = True, to=False, 
      separator = " * ", f_open = "",header = 'algebra', 
      f_close = "", generator = self.gem_like_function_ro, overload = "*", write_charact=True )
    contents += endl

    contents += self.write_scalar_trivar(function_name = "gem", is_elemental = True, level = level, 
      tab = tab, f_name = "", a_type= "r", b_type= "o", c_type = "o", 
      a_ptr = False, b_ptr = True, c_ptr = True, to=True, 
      separator = " * ", f_open = "",header = 'algebra', 
      f_close = "", generator = self.gem_like_function_ro, overload = "*", write_charact=True )
    contents += endl
  
    

    #Function EVALuation
    contents += self.write_scalar_feval(function_name = "feval", is_elemental = True, level = level, tab = tab, 
      lhs_type= "o", lhs_ptr = True, to = False )
    contents += endl

    contents += self.write_scalar_feval(function_name = "feval", is_elemental = True, level = level, tab = tab, 
      lhs_type= "o", lhs_ptr = True, to = True )
    contents += endl

    return contents
  #--------------------------------------------------------------------------------------------------- 


