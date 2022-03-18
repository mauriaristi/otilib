import numpy as np
import pyoti.sparse as oti

def cf(K, CF, dof):
#Se imponen C.F. por el metodo TGV o "penalty"
	if K.dtype == "complex":
		tgv = 1e100
		f = np.zeros(len(K))
	else:
		tgv = 1e100+0*oti.e(1) #numero tgv muy 
		f = np.zeros(len(K)) + 0*oti.e(1)
		CF[:,3] =  CF[:,3] + 0*oti.e(1)
	ax = np.where((CF[:,1] == "u") & (CF[:,2] == "x"))#fila de CF en los que hay cf esenciales
	ay = np.where((CF[:,1] == "u") & (CF[:,2] == "y"))
	bx = np.where((CF[:,1] == "f") & (CF[:,2] == "x")) #fila de CF en los que hay cf naturales
	by = np.where((CF[:,1] == "f") & (CF[:,2] == "y"))
	n_essx = CF[ax,0].astype(int) #nodos con cf esenciales
	n_essy = CF[ay,0].astype(int)
	n_natx = CF[bx,0].astype(int) #nodos con cf naturales
	n_naty = CF[by,0].astype(int)
	K_tgv = K.copy()
	K_tgv[2*n_essx  ,	2*n_essx] 	= tgv #introduce tgv en la matriz K
	K_tgv[2*n_essy+1, 	2*n_essy+1] = tgv
	f[2*n_essx] 	= CF[ax,3]*tgv
	f[2*n_essy+1] 	= CF[ay,3]*tgv
	f[2*n_natx] 	= CF[bx,3]
	f[2*n_naty+1] 	= CF[by,3]
	return (K_tgv, f)

def solu(K, f):
	Kr_inv = np.linalg.inv(K)
	ur = np.dot(Kr_inv, f)
	return (ur, Kr_inv)

def MDuals_complex(K, f):
	Kr = np.real(K)
	Kep = np.imag(K)
	fr = np.real(f)
	fep = np.imag(f)
	ur, Kr_inv = solu(Kr,fr)
	uep = np.dot(Kr_inv, (fep - np.dot(Kep,ur)))
	return(ur, uep)

def MDuals_oti(K, f):
	Kr = otireal(K)
	Kep = oti.get_deriv(K,[1])	
	fr = otireal(f)
	fep = oti.get_deriv(f,[1])
	ur, Kr_inv = solu(Kr,fr)
	uep = np.dot(Kr_inv, (fep - np.dot(Kep,ur)))
	return(ur, uep)

def otireal(otiM):
	filas = otiM.shape[0]
	if otiM.ndim == 2:
		colums = otiM.shape[1]
		Mr = np.zeros([filas,colums])
		for i in range(filas):
			for j in range(colums):
				Mr[i,j] = otiM[i,j][[0,0]]
	else:
		Mr = np.zeros(filas)
		for i in range(filas):
			Mr[i] = otiM[i][[0,0]]
	return (Mr)

def complex(K, f):
	Kr = np.real(K)
	Kr_inv = np.linalg.inv(Kr)
	Ki = np.imag(K)
	fr = np.real(f)
	fi = np.imag(f)
	A = Kr + np.dot(Ki, np.dot(Kr_inv, Ki))
	b = fr + np.dot(Ki, np.dot(Kr_inv, fi))
	ur, A_inv = solu(A, b)
	ui = np.dot(Kr_inv, (fi - np.dot(Ki,ur)))
	return(ur, ui)





