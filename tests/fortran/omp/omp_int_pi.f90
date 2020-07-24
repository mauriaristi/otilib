PROGRAM OMP_INT_PI

    USE OMP_LIB

    IMPLICIT NONE

    INTEGER :: ID, I
    INTEGER, PARAMETER::NDIVS = 100000000
    INTEGER, PARAMETER::NTHREADS =8
    REAL*16 :: X, STEP, F, PI, STARTT, ENDT, SUM

    STEP = 1.0d0 / REAL( NDIVS, KIND=16 )
    STARTT = OMP_GET_WTIME()
    PI = 0.0d0
    
    CALL OMP_SET_NUM_THREADS(NTHREADS)

    !$OMP PARALLEL PRIVATE(ID,I, SUM)
    
        ID =  omp_get_thread_num()
        I = ID
        SUM = 0.0d0

        DO WHILE (I .le. NDIVS)
            
            X = (I)*STEP
            SUM = SUM + STEP*4.0d0/(1.0d0+X**2)
            I = I+NTHREADS
        END DO

        !$OMP CRITICAL
            PI = PI + SUM
        !$OMP END CRITICAL
        
    
    !$OMP END PARALLEL
    
    ENDT = OMP_GET_WTIME()
    
    PRINT*, PI
    PRINT*, "TOOK:",ENDT-STARTT


END PROGRAM OMP_INT_PI