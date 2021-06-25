import numpy as np


def lect1D(Directorio_problema):
#LECTURA caso 1D
	Dir = Directorio_problema+"/"
	nodos = np.loadtxt(Dir + "Geo.txt") 					# nodos: 		[x] 									(filas = id nodo)
	elementos = np.loadtxt(Dir + "Topo.txt", dtype = int)	# elementos: 	[id n_ini] [id n_fin] 					(filas = id elemento)
	materiales = np.loadtxt(Dir + "Mat.txt")				# materiales: 	[Area]	[Modulo de elasticidad] 		(filas = id elemento correspondiente)
	Cond_f = np.loadtxt(Dir + "Cond_front.txt")				# cond front: 	[id nodo]	[Esen(0)/Natu(1)]  [valor]	(filas = sin significado)
	return (nodos, elementos, materiales, Cond_f)

def lect2D(Directorio_problema):
#LECTURA caso 2D
	Dir = Directorio_problema+"/"
	nodos = np.loadtxt(Dir + "Geo.txt") 							# nodos: 		[x] [y]													(filas = id nodo)
	elementos = np.loadtxt(Dir + "Topo.txt", dtype = int)			# elementos: 	[id n_ini] [id n_fin] 									(filas = id elemento)
	materiales = np.loadtxt(Dir + "Mat.txt")						# materiales: 	[Area]	[Modulo de elasticidad] 						(filas = id elemento correspondiente)
	Cond_f = np.loadtxt(Dir + "Cond_front.txt", dtype = object)		# cond front: 	[id nodo]	[tipo (u/f)]  [dir (x/y)]	[valor]			(filas = sin significado)
	Cond_f[:,0] = (Cond_f[:,0]).astype(int)
	Cond_f[:,1:3] = (Cond_f[:,1:3]).astype(str)
	Cond_f[:,3] = (Cond_f[:,3]).astype(float)
	return (nodos, elementos, materiales, Cond_f)

