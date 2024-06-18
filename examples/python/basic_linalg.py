# -------------------------------------------------------------------------
# This file provides an example for using pyoti to compute derivatives in 
# linear algebra operations with Order Truncated Imaginary (OTI) numbers.
#
# Author: Mauricio Aristizabal, PhD
# Date: June 17 2024
#
# -------------------------------------------------------------------------

# 1. Import the library.
import pyoti.sparse as oti


# 2. Define A as an identity matrix.
#    values from 0 to 2*pi.
# 

A = oti.array([[1, 0],
               [0, 1]])
print('A:')
print(A)

# Add a perturbation along epsilon_1 to the first element of the matrix.
A[0,0] += oti.e(1)
A[1,0] += oti.e(2)

print('\nA:')
print(A)

# Compute the inverse of A. Inv only supports 1x1, 2x2 or 3x3 matrices.
Ainv = oti.inv(A)

print('\ninv(A):')
print(Ainv)

# In this case the imaginary coefficients of f are arrays. 