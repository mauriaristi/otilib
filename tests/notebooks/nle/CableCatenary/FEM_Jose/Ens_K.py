import numpy as np
import pyoti.sparse as oti

#K global para cerhca 1D
def K(dof, eles, nodos, mat):
	nn = len(nodos)
	neles = len(eles)
	dimK = nn*dof
	K = np.zeros((dimK, dimK), dtype = mat.dtype)
	for i in range(neles):
		Ke = Kloc(i, eles, nodos, mat)
		l = 2*eles[i,0]
		m = 2*eles[i,1]
		K[l,  l  ] = K[l,  l  ] + Ke[0,0]
		K[l+1,l  ] = K[l+1,l  ] + Ke[1,0]
		K[l,  l+1] = K[l,  l+1] + Ke[0,1]
		K[l+1,l+1] = K[l+1,l+1] + Ke[1,1]
		K[l,  m  ] = K[l,  m  ] + Ke[0,2]
		K[l+1,m  ] = K[l+1,m  ] + Ke[1,2]
		K[l,  m+1] = K[l,  m+1] + Ke[0,3]
		K[l+1,m+1] = K[l+1,m+1] + Ke[1,3]
		K[m,  l  ] = K[m,  l  ] + Ke[2,0]
		K[m+1,l  ] = K[m+1,l  ] + Ke[3,0]
		K[m,  l+1] = K[m,  l+1] + Ke[2,1]
		K[m+1,l+1] = K[m+1,l+1] + Ke[3,1]
		K[m,  m  ] = K[m,  m  ] + Ke[2,2]
		K[m+1,m  ] = K[m+1,m  ] + Ke[3,2]
		K[m,  m+1] = K[m,  m+1] + Ke[2,3]
		K[m+1,m+1] = K[m+1,m+1] + Ke[3,3]
	return(K)

#K local para cercha 1D
def Kloc(ele, eles, nodos, mat):
	A = mat[ele,0]
	E = mat[ele,1]
	L, x1, x2, y1, y2 = Len(nodos, eles, ele)
	k = (A*(L**(-1)))*E
	T = Trans(L, x1, x2, y1, y2)
	ki = np.array(([1 , -1], [-1, 1]))
	Kig = np.dot(np.dot(np.transpose(T), ki),T)
	Ke = Kig*k
	return (Ke)

#Calculo longitudes de elementos 2d
def Len(nodos, eles, i):
	x1 = nodos[eles[i,0],0]
	x2 = nodos[eles[i,1],0]
	y1 = nodos[eles[i,0],1]
	y2 = nodos[eles[i,1],1]
	L = np.sqrt((x2 - x1)**2 + (y2 - y1)**2)
	return (L, x1, x2, y1, y2)

# Calculo de matriz transformacion T con cosenos directores 2d
def Trans(L, x1, x2, y1, y2):
	cosx = (x2-x1)/L
	cosy = (y2-y1)/L
	T = np.array([[cosx, cosy, 0,0], [0,0,cosx, cosy]])
	return(T)
