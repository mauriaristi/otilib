# This file tests OTIs as a means to implement Univariate Taylor Polynomials.

import pyoti.sparse as oti
import numpy as np

oti.set_printoptions(terms_print=-1)

x = 0.5+oti.e(1,order=4)
y = 0.8+oti.e(2,order=4)


# OTI mode
f = oti.sin((x**0.5)*(y**0.3))

print(80*'=')
print(' Evaluated function with OTI algebra')
print(f)
print(80*'-')
print(' Second order mixed coeff [1,2] = {0}'.format(f.get_im([1,2])))

print(' Fourth order mixed imcoef [1,1,2,2] = {0}'.format(f.get_im([1,1,2,2])))
print(' Fourth order mixed deriv d4f/dx2dy2 = {0}'.format(f.get_deriv([1,1,2,2])))
print(80*'=')

#Univariate TP mode

fx = 1.0#/np.sqrt(4)
fy = 1.0#/np.sqrt(4)

x = 0.5 + fx*oti.e(1,order=4)
y = 0.8 + fy*oti.e(1,order=4)

f = oti.sin((x**0.5)*(y**0.3))

print(80*'=')
print('Evaluated function with UTP')
print(f)
print(80*'-')
print(f.get_deriv([1,1]))
print(80*'=')

