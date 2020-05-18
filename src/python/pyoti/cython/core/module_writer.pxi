



class writer:


  def __init__(self, order, nbases, language = 'fortran', tab = "  ", coeff_type = "REAL*8" ):

    global h
    self.order   = order
    self.nbases  = nbases
    self.tab     = tab
    self.coeff_t = coeff_type

    self.nimdir = dhelp_ndirTotal(self.nbases, self.order)
    
    # append imaginary direction.
    self.name_imdir = []
    self.name_imdir.append([])
    self.name_imdir[0].append('0')

    for ordi in range(1,self.order+1):

      self.name_imdir.append([])
      
      nimdir_i = dhelp_ndirOrder(self.nbases, ordi)

      for j in range(nimdir_i):
        str_out = ""
        list_bases = h.get_str_fulldir(j,ordi)
        str_out = list_bases[1:-1].replace(",","")
        self.name_imdir[ordi].append(str_out)  

      # end for 






  def set_type_fortran(self):

    global h
    str_out = ""

    str_out += "TYPE ONUM_M"+str(self.nbases)+"N"+str(self.order)+"\n"
    str_out += self.tab + self.coeff_t + " :: " + "R" + "\n"

    # end for 
    str_out += "END TYPE ONUM_M"+str(self.nbases)+"N"+str(self.order)+"\n"

    return str_out