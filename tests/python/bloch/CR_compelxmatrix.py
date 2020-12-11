import numpy as np
import scipy.linalg as spla

ka = 1*np.pi
m=1
h=1e-10
c = 1
ka_m = np.array([[ka,0],
                 [0,ka]
                ])

m_m =  np.array([[m,0],
                 [0,m] ])

c_m =  np.array([[c,-h ],
                 [h, c ] ])


one_m =  np.array([[1,0],
                   [0,1] ])


a = np.dot( c_m, ( spla.expm(1j*ka_m) + spla.expm(-1j*ka_m) - one_m*2))

b = -m_m

# Falla esta parte por 
eigval,eigvec = spla.eig(a,b=b)



print("Bloch problem evaluated at: ")
print("ka/pi = ",ka/np.pi)
print("m = ", m)
print("c = ", c)
print()

print("Resulting eigenvalues:")
print(eigval)


