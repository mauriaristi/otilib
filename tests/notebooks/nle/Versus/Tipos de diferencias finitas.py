# -*- coding: utf-8 -*-
"""
Created on Wed Jul 17 16:24:26 2019

@author: asus
"""
import numpy as np
import pylab

""" Function f(x) and analytical derivatives """
def f(x):
    return x*np.cos(x) + np.sin(x)/x**2

""" Analytical derivative of f(x)"""
def diff(x):
    df = ((x**3 + x)*np.cos(x) - (x**4 + 2)*np.sin(x))/x**3
    return df

""" Derivatives of f(x) using finite differences """
def FD(x, h):
    df_f = (f(x + h) - f(x))/(h)
    df_b = (f(x) - f(x - h))/(h)
    df_c = (f(x + h) - f(x - h))/(2*h)
    return df_f, df_b, df_c

"""Plot error"""
def e(x, nevals=25):
    pylab.clf() 
    e = np.zeros([nevals,3])
    h = np.zeros(nevals)
    for i in range(nevals):
        h[i] = 10**-i
        e[i,0] = (abs(diff(x) - FD(x, h[i])[0])/abs(diff(x)))
        e[i,1] = (abs(diff(x) - FD(x, h[i])[1])/abs(diff(x)))
        e[i,2] = (abs(diff(x) - FD(x, h[i])[2])/abs(diff(x)))
    
    pylab.plot(h, e[:,0], 'r.-', label = 'DF hacia adelante')
    pylab.plot(h, e[:,1], 'b--' , label='DF hacia atrás')
    pylab.plot(h, e[:,2], 'g.-' , label = 'DF centradas')
    pylab.legend(loc='lower right')
    pylab.xscale('log')
    pylab.yscale('log')
    pylab.xlabel('h')
    pylab.ylabel('Error relativo')
    pylab.title("Error relativo vs h")
    pylab.gca().invert_xaxis()
    pylab.grid()
    pylab.show()
    return 

""" Error substraction in d3f"""
def d3f(x, h):
    d3f = x*np.sin(x) - 3*np.cos(x) - np.cos(x)/x**2 + 6*np.sin(x)/x**3 + 18*np.cos(x)/x**4 - 24*np.sin(x)/x**5 #analytical
    d3f_DFd = (f(x + 1.5*h) - f(x - 1.5*h) - 3*f(x + 0.5*h) + 3*f(x - 0.5*h))/h**3 #d3f_DF disagruped
    d3f_DFa = ((f(x + 1.5*h) - f(x - 1.5*h)) - (3*f(x + 0.5*h) - 3*f(x - 0.5*h)))/h**3 #d3f_DF agruped
    return d3f, d3f_DFd, d3f_DFa

"""Plot error in d3f"""
def ed3f(x, nevals=25):
    pylab.clf() 
    e = np.zeros([nevals,3])
    h = np.zeros(nevals)
    for i in range(nevals):
        h[i] = 10**-i
        e[i,0] = (abs(d3f(x,h[i])[0] - d3f(x, h[i])[1])/abs(d3f(x,h[i])[0]))
        e[i,1] = (abs(d3f(x,h[i])[0] - d3f(x, h[i])[2])/abs(d3f(x,h[i])[0]))  
    pylab.plot(h, e[:,0], 'r.-' , label='Disagruped')
    pylab.plot(h, e[:,1], 'b--', label = 'Agruped')
    pylab.legend(loc='lower right')
    pylab.xscale('log')
    pylab.yscale('log')
    pylab.xlabel('h')
    pylab.ylabel('Relative error')
    pylab.title("Substraction error in d3f-DF")
    pylab.gca().invert_xaxis()
    pylab.grid()
    pylab.show()
    return 