import pyoti.sparse as oti
import numpy as np

# Define variables and apply perturbations
x = np.pi/4 + oti.e(1,order=2)

# Evaluate function.
f = oti.sin(x)

print(f)
# >>>  0.707107 + 0.707107 * e([1]) - 0.353553 * e([[1,2]])

# Extract the function and its derivatives:

print(f'f(x):      {f.real}')
print(f'df/dx:     {f.get_deriv([1  ])}')
print(f'd^2f/dx^2: {f.get_deriv([1,1])}')

# >>> f(x):      0.7071067811865475
# >>> df/dx:     0.7071067811865476
# >>> d^2f/dx^2: -0.7071067811865475