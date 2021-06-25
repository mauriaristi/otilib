# -*- coding: utf-8 -*-
"""
Created on Wed Jun 26 17:03:14 2019

@author: asus
"""
import numpy as np
import pylab


""" Function f(x) and analytical derivatives """
def f(x):
    return x*np.cos(x) + np.sin(x)/x**2

""" Analytical derivatives of f(x)"""
def diff(x):
    df = ((x**3 + x)*np.cos(x) - (x**4 + 2)*np.sin(x))/x**3
    d2f = -((x**5 + 4*x)*np.cos(x) + (2*x**4 + x**2 - 6)*np.sin(x))/x**4
    d3f = x*np.sin(x) - 3*np.cos(x) - np.cos(x)/x**2 + 6*np.sin(x)/x**3 + 18*np.cos(x)/x**4 - 24*np.sin(x)/x**5
    return df, d2f, d3f

""" Derivatives of f(x) using centered finite differences """
def FD(x, h):
    df = (f(x + h) - f(x - h))/(2*h)
    d2f = (f(x + h) - 2*f(x) + f(x - h))/h**2
    d3f = ((f(x + 1.5*h) - f(x - 1.5*h)) - (3*f(x + 0.5*h) - 3*f(x - 0.5*h)))/h**3
    return df, d2f, d3f

""" Derivatives of f(x) using Complex Taylor series expansion """
def CTSE(x,h):
    F = np.real(f(x + h*1j))
    df = np.imag(f(x + h*1j))/h
    d2f = -2*(np.real(f(x + h*1j)) - f(x))/h**2
    d3f = -6*(np.imag(f(x + h*1j)) - (np.imag(f(x + (1e-9)*1j))/(1e-9))*h)/h**3    
    return F, df, d2f, d3f

"""Plot error"""
def e(x, nevals=25): 
    pylab.clf() 
    eDF = np.zeros([nevals,3])
    eCTSE = np.zeros([nevals,4])
    h = np.zeros(nevals)
    for i in range(nevals):
        h[i] = 10**-i
        eDF[i,0] = (abs(diff(x)[0] - FD(x, h[i])[0])/abs(diff(x)[0]))
        eDF[i,1] = (abs(diff(x)[1] - FD(x, h[i])[1])/abs(diff(x)[1]))
        eDF[i,2] = (abs(diff(x)[2] - FD(x, h[i])[2])/abs(diff(x)[2]))
        
        eCTSE[i,0] = abs(f(x) - CTSE(x, h[i])[0]) / abs(f(x)) # error f(x) with CTSE
        eCTSE[i,1] = (abs(diff(x)[0] - CTSE(x, h[i])[1])/abs(diff(x)[0]))
        eCTSE[i,2] = (abs(diff(x)[1] - CTSE(x, h[i])[2])/abs(diff(x)[1]))
        eCTSE[i,3] = (abs(diff(x)[2] - CTSE(x, h[i])[3])/abs(diff(x)[2]))
    
#    pylab.subplot(1,2,1)
#    pylab.plot(h, eDF[:,0], 'r.-', label = 'df/dx')
#    pylab.plot(h, eDF[:,1], 'b--' , label='d2f/dx2')
#    pylab.plot(h, eDF[:,2], 'g.-' , label = 'd3f/dx3')
#    pylab.legend(loc='upper left')
#    pylab.xscale('log')
#    pylab.yscale('log')
#    pylab.xlabel('h')
#    pylab.ylabel('Error relativo')
#    pylab.title("Error relativo vs h")
#    pylab.gca().invert_xaxis()
#    pylab.grid()
#    
#    pylab.subplot(1,2,2)
    pylab.plot(h, eCTSE[:,1] + + 1e-17, 'r.-', label = 'df/dx')
    pylab.plot(h, eCTSE[:,2], 'b--', label = 'd2f/dx2')
    pylab.plot(h, eCTSE[:,3], 'g.-', label = 'd3f/dx3')
    pylab.legend(loc='upper left')
    pylab.xscale('log')
    pylab.yscale('log')
    pylab.xlabel('h')
    pylab.ylabel('Relative error')
    pylab.title("CTSE")
    pylab.gca().invert_xaxis()
    pylab.grid()
    
    pylab.show()
    return 

#pylab.savefig()


