# -------------------------------------------------------------------------
# This file provides an example for using pyoti to compute high-order 
# derivatives of a scalar function using Order Truncated Imaginary (OTI) 
# numbers.
#
# Author: Mauricio Aristizabal, PhD
# Date: June 18 2024
#
# -------------------------------------------------------------------------

# 1. Import the library.
import pyoti.sparse as oti



# 2. Define each variable with its correspondign real value and apply
#    independent perturbations along specific imagianry axes.
#
#   -> Note: oti.e(imdir, order=tOrd) is a function that creates an 
#      OTI number with 1 along the imdir direction and sets the 
#      truncation order to tOrd. 
#      Truncation order is typically associated to the maximum order
#      of derivative that is going to be computed.

x = 3.5 + oti.e(1,order=2 )
y = 0.5 + oti.e(2,order=2 )

# 3. Evaluate the function to compute the derivatives.
#
#   -> Note: Many mathematical functions are supported. See doc for 
#      more information.
f = oti.sin(x*y)

# f now contains all the first order derivatives with respect to x and y.
print(f)

# Notice that not all terms are printed.
#
# Use the set_printoptions function to allow printing all terms in the
# oti number.
oti.set_printoptions(terms_print=-1) 

# f now contains all the first order derivatives with respect to x and y.
print(f)

# This should print 
# >>> 0.983986 - 0.089123 * e([1]) - 0.623861 * e([2])
#
#    Which corresponds to the actual function along the real part, and
#    the derivative df/dx along epsilon_1 and df/dy along epsilon_2.
# 

# 4. Getting the real part and its components.

print('\nReal part of f', f.real)

print('\ne(1) part of f', f.get_im(1) )
print('e(2) part of f', f.get_im(2) )

# In this case the imaginary coefficients are of order 1, thus they 
# correspond to the first order derivatives. 
#
# However, higher order derivatives do not match with the imaginary 
# coefficients. To get the derivatives, use get_deriv method.

print('\nd^2f/dx^2 ', f.get_deriv([1,1]) )
print('d^2f/dy^2 ', f.get_deriv([2,2]) )
print('d^2f/dxdy ', f.get_deriv([1,2]) )