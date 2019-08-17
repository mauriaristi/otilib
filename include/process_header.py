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


if __name__=="__main__":

    for file in files:
        f = open(file,"r")
        string = f.read()
        f.close()
        string = remove_annotations(string)
        f=open(file+"cx","w")
        f.write(string)
        f.close()
        