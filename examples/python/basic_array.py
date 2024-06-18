# -------------------------------------------------------------------------
# This file provides an example for using pyoti to compute derivatives when
# using "vector" functions and Order Truncated Imaginary (OTI) numbers.
#
# Author: Mauricio Aristizabal, PhD
# Date: June 17 2024
#
# -------------------------------------------------------------------------

# 1. Import the library.
import pyoti.sparse as oti

# There is limited support for operations with numpy array.
# This is required in this example to generate 
import numpy as np

# 2. Define a real variable x as an array of 100 equally spaced 
#    values from 0 to 2*pi.
# 

x_np = np.linspace(0,np.pi,5)
print('x_np:')
print(x_np)

# Use the pyoti function oti.array to convert the x_np to an OTI-array.
# This is, a MATrix of Sparse OTIs (matso)
x = oti.array(x_np)

print()
print('x:')
print(x)

# Note: OTI arrays are *always* 2 dimensional.

# The inputs to oti.array can be lists, numpy arrays, and other elements.
# See documentation.

# OTI arrays are interoperable with scalar OTI numbers. For instance,
x += oti.e(1)

# Adds each element of x an OTI number with 1 along epsilon_1
print()
print('x after adding e(1)')
print(x)

# 3. Evaluate a function to compute the derivatives.
#

f = oti.sin(x)

# f now contains all the first order derivatives with respect to x.

print()
print('f = sin(x)')
print(f)

# 4. Getting the real part and its components.

print('\nReal part of f\n', f.real)
print('\ne(1) part of f\n', f.get_im(1) )

# In this case the imaginary coefficients of f are arrays. 