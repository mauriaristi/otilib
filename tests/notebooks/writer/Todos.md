* TODOs


1. Add Function to automate CR to MDUAL conversion. ("Des-CauchyRiemann-izar")
2. Pretty printing support. 
2. Add Matrix inverse function. (not necessary for large systems)
3. Implement block solver with Lapack functions (dsysv, *dgesv*, dgetrf)
	- Get LU factorization using *dgetrf* to get LDA (LU factorized A)
	- Use LDA to solve the right-hand sides with *dgetrs*.

Compile with intel fortran compiler: -qmkl