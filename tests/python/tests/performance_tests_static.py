import sys
import timeit
path2oti = '../../../build/'
sys.path.append(path2oti) # Add path to OTI library.

import pyoti.core      as coti

import pyoti.real      as r
import pyoti.sparse    as oti

# Static libraries:
# Dual
import pyoti.onumm1n1  as dual

# Multiduals
import pyoti.mdnum2    as md2
import pyoti.mdnum3    as md3
import pyoti.mdnum4    as md4
import pyoti.mdnum5    as md5

# OTI.
import pyoti.onumm1n2  as om1n2 
import pyoti.onumm1n3  as om1n3 
import pyoti.onumm1n5  as om1n5 
import pyoti.onumm2n2  as om2n2 
import pyoti.onumm3n3  as om3n3 
import pyoti.onumm1n10 as om1n10
import pyoti.onumm10n1 as om10n1
import pyoti.onumm2n5  as om2n5 

np = oti.np


modules = [r, dual, md2, md3, md4, md5, om1n2, om1n3, om1n5, om2n2, om3n3, om1n10, om10n1, om2n5]




report_length = 50
def report_times():
    out = ''
    for i in range(len(modules)):
        mname = modules[i].__name__
        out += mname+" ::::"
        for key1, items1 in times[i].items():
            for key2, items2 in items1.items():
                str_out = key1+" "+key2 + ' '
                str_out += '-'*(int(report_length-len(str_out))) 
                out+= str_out+" {0:15.4f} ns".format((items2)) 
        out += "\n\n\n"
    return out
        
def report_times_comp_real():
    mreal = modules[0]
    treal = times[0]
    out = ''
    for i in range(1,len(modules)):
        mname = modules[i].__name__
        out +=mname+" ::::"
        for key1, items1 in times[i].items():
            for key2, items2 in items1.items():
                item_real = treal[key1][key2]
                str_out = key1+" "+key2 + ' '
                str_out += '-'*(int(report_length-len(str_out))) 
                out += str_out+" {0:15.2f}X".format((items2/item_real)) 
        out += "\n\n\n"
    return out



def main():

    times = []
    niter = int(1e5)
    for module in modules:
        mat_size = 18
        nip      = 27
        print("Analyzing "+module.__name__ + str((mat_size,mat_size)))
        times.append({})
        times[-1]['scalar']={}
        times[-1]['gauss_scalar']={}
        times[-1]['array']={}
        times[-1]['gauss_array']={}

        niter = int(1e3)
        
        x  = module.number(0.5)
        try:
            xout = x.copy()
        except:
            xout=x
        # end try
        
        # Create the objects.
        X  = module.zeros((mat_size,mat_size))
        Xout = X.copy()
        xg = module.number(0.5,  nip=nip)
        xgout = xg.copy()
        Xg = module.zeros((mat_size,mat_size), nip=nip)
        Xgout = Xg.copy()

        vars_to = {}
        vars_to['module'] =module 
        vars_to['x'] = x
        vars_to['xout'] = xout
        vars_to['X'] = X
        vars_to['Xout'] = Xout
        vars_to['xg'] = xg
        vars_to['xgout'] = xgout
        vars_to['Xg'] = Xg
        vars_to['Xgout'] = Xgout 

        print("  -----  Scalar")
        expr = 'x+x';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'x*x';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.sin(x)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.pow(x,100.)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        print("  -----  Array")
        expr = 'X+X';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'X*X';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.dot(X,X)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.sin(X)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['array'][expr.replace('module.','')]=time/float(niter)*1e9
        



        print("  -----  Scalar (out)")
        expr = 'module.sum(x,x,out=xout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.mul(x,x,out=xout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.sin(x, out=xout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.pow(x,100., out=xout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        

        print("  -----  Array (out)")
        expr = 'module.sum(X,X,out=Xout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.mul(X,X,out=Xout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.dot(X,X,out=Xout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.sin(X,out=Xout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        
        
        
        
        niter = int(1e4)
        print("  -----  Gauss Scalar")
        expr = 'xg+xg';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'xg*xg';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.sin(xg)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.gauss_integrate(xg,xg)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        
        print("  -----  Gauss Array")
        expr = 'Xg+Xg';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['gauss_array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'Xg*Xg';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['gauss_array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.dot(Xg,Xg)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['gauss_array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.sin(Xg)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['gauss_array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.gauss_integrate(Xg,xg)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['gauss_array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        
        
        print("  -----  Gauss Scalar (out)")
        expr = 'module.sum(xg,xg,out=xgout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.mul(xg,xg,out=xgout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.sin(xg,out=xgout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.gauss_integrate(xg,xg,out=x)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['scalar'][expr.replace('module.','')]=time/float(niter)*1e9
        
        
        print("  -----  Gauss Array (out)")
        expr = 'module.sum(Xg,Xg,out=Xgout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['gauss_array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.mul(Xg,Xg,out=Xgout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['gauss_array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.dot(Xg,Xg,out=Xgout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['gauss_array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.sin(Xg,out=Xgout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['gauss_array'][expr.replace('module.','')]=time/float(niter)*1e9
        
        expr = 'module.gauss_integrate(Xg,xg,out=Xout)';#print(expr)
        time = timeit.timeit (expr,globals=vars_to, number =niter)
        times[-1]['gauss_array'][expr.replace('module.','')]=time/float(niter)*1e9
    # end for 
    print("Finished")

    f = open("report_times_comp_real.txt",'w')
    f.write(report_times_comp_real())
    f.close()

    f = open("report_times.txt",'w')
    f.write(report_times())
    f.close()





if __name__ == '__main__':
    main()




