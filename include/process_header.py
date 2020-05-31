import os
import re

def comment_replacer(match): 
    start,mid,end = match.group(1,2,3) 
    if mid is None: 
        # single line comment 
        return '' 
    elif start is not None or end is not None: 
        # multi line comment at start or end of a line 
        return '' 
    elif '\n' in mid: 
        # multi line comment with line break 
        return '\n' 
    else: 
        # multi line comment without line break 
        return ' ' 

comment_re = re.compile( 
    r'(^)?[^\S\n]*/(?:\*(.*?)\*/[^\S\n]*|/[^\n]*)($)?', 
    re.DOTALL | re.MULTILINE 
)


def remove_annotations(string):
    str_nocomm=comment_re.sub(comment_replacer, string)
    str_nocomm= re.sub(r'(?m)^ *#.*\n?', '', str_nocomm)
    for i in range(10):
        str_nocomm = str_nocomm.replace("\n\n","\n")

    return str_nocomm


files= ["oti/core.h",
        "oti/dense.h",
        "oti/sparse.h",
        "oti/real.h",
        ]


locations = [ "oti/core",
              "oti/dense",
              "oti/fem",
              "oti/real",
              "oti/sparse"
]

# files_in_dir = []

folders={}
folders['core']=[]
folders['dense']=[]
folders['fem']=[]
folders['real']=[]
folders['sparse']=[]
# r=>root, d=>directories, f=>files
for key, files_in_dir in folders.items():
  location = 'oti/'+ key
  for r, d, f in os.walk(location):
    for item in f:
      if '.h' in item:
        files_in_dir.append(os.path.join(r, item))
      #
    #
  #
#

out_dir = "pyoti/c_otilib/processed_headers/"

InterHeader = """
# =========================================================================================
"""

if __name__=="__main__":
    
  for key, files in folders.items():
    
    header_out = ""
    str_out = "" 

    for file in files:

      f = open(file,"r")
      string = f.read()
      f.close()
      if "structures" in file or "enums" in file:
        header_out += "\n# From "+file+"\n"
        string =  remove_annotations(string).replace("enum", "cdef enum")
        string = string.replace("typedef","ctypedef")
        string = string.replace("}","# }")
        string = string.replace("{",": # {")
        header_out += string
        header_out += "\n"
      else:
        str_out += "\n# From "+file+"\n"
        string = remove_annotations(string).replace("(void)","()").replace("( void )","()")
        for i in range(10):
          string = string.replace(" \n","\n")
        #
        # string = string.replace(",\n",", &\n")
        str_out += string
        str_out += "\n"
      # end if 
    #
    f=open(out_dir+key+".hcx","w")
    f.write(header_out +InterHeader+ str_out)
    f.close()
        