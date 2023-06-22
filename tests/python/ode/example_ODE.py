import pyoti.sparse as oti
import numpy as np
oti.set_printoptions(terms_print=-1)


def f_x(y,t):
    return y*oti.cos(t)

y0 = 1
t0 = 0

order = 4

y = oti.number(y0)
t = t0 + oti.e(1, order = order)


for i in range(order):
    print("-"*50)
    print('Iteration: {0}'.format(i+1))
    # t = t0 + oti.e(1, order = (i+1))
    f=f_x(y,t)
    print('f:',f)
    y.set_deriv(f, [1])
    print('y:',y) 
    
    # y = y.truncate_order(i+2)

    print('y_order:',y.order,y.actual_order)
    print('f_order:',f.order,f.actual_order)

# end for

print('='*50)





# Print solution to this problem:
y_actual = oti.exp(oti.sin(t))
f_actual = f_x(y_actual,t)
print('Derivative of the analytical solutions:')
print('f:',f_actual)
print('y:',y_actual)
