# -*- coding: utf-8 -*-
"""
Created on Fri Jun 14 15:28:16 2019

@author: asus
"""
import math
import cmath

def f(x):
    return math.sin(x)

def zf(x):
    return cmath.sin(x)

def dfdx(x):
    return math.cos(x)

def diffin(x,h):
    #print ("f(x+h):      ",f(x+h))
    #print ("f(x):        ",f(x)  )
    #print ("f(x+h)-f(x): ",f(x+h) - f(x)  )
    return (f(x+h) - f(x))/h
    #return (f(x+h) - f(x-h))/(2*h)
    

def ctse(x,h):
     zx = x + h*1j
     zfeval= zf(zx)
     f = zfeval.real
     df = zfeval.imag/h
     return f, df
       