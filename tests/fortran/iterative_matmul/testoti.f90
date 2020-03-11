PROGRAM MAIN

    USE otim2n3
    IMPLICIT NONE
    INTEGER, PARAMETER :: sizex = 3
    TYPE(ONUMM2N3)       :: X, Y, Z   !>OTI VARIABLE
    TYPE(ONUMM2N3)       :: A(sizex,sizex), B(sizex,sizex), C(sizex,sizex)   !>OTI VARIABLE
    INTEGER :: I
    INTEGER, PARAMETER :: NITER=1000000
    REAL(KIND=8)::   NITER_R=NITER,  CPU_TIMES ,      &                !>Step
        time_start(3), time_finish(3)          !>Stores time
    COMPLEX*16 :: XZ, YZ, ZZ
    REAL*8 :: XR, YR, ZR

    REAL*8 :: AR(sizex,sizex), BR(sizex,sizex), CR(sizex,sizex)
    COMPLEX*16 :: AZ(sizex,sizex), BZ(sizex,sizex), CZ(sizex,sizex)
    ! ============================================================
    
    PRINT *, " "
    PRINT *, " THIS MODULE TESTS THE FORTRAN OTI IMPLEMENTATION."
    PRINT *, " "

    XR = 1.5D0
    XZ = XR
    X  = XR

    YR = 5.2D0
    YZ = YR
    Y  = YR

    ZR = 5.2D0
    ZZ = ZR
    Z  = ZR



    ! Real Case:
    CALL CPU_TIME(time_start(1))
    DO i=1,NITER
        ! Multiplication with assignation
        YR = ZR + XR
        ZR = XR + YR
    END DO
    CALL CPU_TIME(time_finish(1))

    CPU_TIMES = 1.0d9*( time_finish(1) - time_start(1) ) / NITER_R ! In us.
    PRINT "(2(A,F20.3,8X))", '-- REAL Scalar Addition CPU_TIME [ns]:', &!
                            CPU_TIMES

    CALL CPU_TIME(time_start(1))
    DO i=1,NITER
        ! Multiplication with assignation
        YR = ZR*XR
        ZR = XR*YR
    END DO
    CALL CPU_TIME(time_finish(1))

    CPU_TIMES = 1.0d9*( time_finish(1) - time_start(1) ) / NITER_R ! In us.
    PRINT "(2(A,F20.3,8X))", '-- REAL Scalar Multiplication CPU_TIME [ns]:', &!
                            CPU_TIMES
    
    ! Measure time.
    CALL CPU_TIME(time_start(1))
    DO i=1,NITER
        ! Multiplication with assignation
        AR = MATMUL(CR,BR)
        CR = MATMUL(AR,BR)
    END DO
    CALL CPU_TIME(time_finish(1))

    CPU_TIMES = 1.0d9*( time_finish(1) - time_start(1) ) / NITER_R ! In us.

    PRINT "(2(A,F20.3,8X))", '-- REAL MATMUL CPU_TIME [ns]:', &!
                            CPU_TIMES



    PRINT *, " "
    ! Complex Case:
    CALL CPU_TIME(time_start(1))
    DO i=1,NITER
        ! Multiplication with assignation
        YZ = ZZ+XZ
        ZZ = XZ+YZ
    END DO
    CALL CPU_TIME(time_finish(1))

    CPU_TIMES = 1.0d9*( time_finish(1) - time_start(1) ) / NITER_R ! In us.
    PRINT "(2(A,F20.3,8X))", '-- COMPLEX Scalar Addition CPU_TIME [ns]:', &!
                            CPU_TIMES

    CALL CPU_TIME(time_start(1))
    DO i=1,NITER
        ! Multiplication with assignation
        YZ = ZZ*XZ
        ZZ = XZ*YZ
    END DO
    CALL CPU_TIME(time_finish(1))

    CPU_TIMES = 1.0d9*( time_finish(1) - time_start(1) ) / NITER_R ! In us.
    PRINT "(2(A,F20.3,8X))", '-- COMPLEX Scalar Multiplication CPU_TIME [ns]:', &!
                            CPU_TIMES
    
    ! Measure time.
    CALL CPU_TIME(time_start(1))
    DO i=1,NITER
        ! Multiplication with assignation
        AZ = MATMUL(CZ, BZ)
        CZ = MATMUL(AZ, BZ)
    END DO
    CALL CPU_TIME(time_finish(1))

    CPU_TIMES = 1.0d9*( time_finish(1) - time_start(1) ) / NITER_R ! In us.

    PRINT "(2(A,F20.3,8X))", '-- COMPLEX MATMUL CPU_TIME [ns]:', &!
                            CPU_TIMES


    PRINT *, " "    
    CALL CPU_TIME(time_start(1))
    DO i=1,NITER
        ! Multiplication with assignation
        Y = Z + X
        Z = X + Y
    END DO
    CALL CPU_TIME(time_finish(1))

    CPU_TIMES = 1.0d9*( time_finish(1) - time_start(1) ) / NITER_R ! In us.
    PRINT "(2(A,F20.3,8X))", '-- OTI Scalar Addition CPU_TIME [ns]:', &!
                            CPU_TIMES



    CALL CPU_TIME(time_start(1))
    DO i=1,NITER
        ! Multiplication with assignation
        Y = Z * X
        Z = X * Y
    END DO
    CALL CPU_TIME(time_finish(1))

    CPU_TIMES = 1.0d9*( time_finish(1) - time_start(1) ) / NITER_R ! In us.
    PRINT "(2(A,F20.3,8X))", '-- OTI Scalar Multiplication CPU_TIME [ns]:', &!
                            CPU_TIMES
    

    ! Measure time.
    CALL CPU_TIME(time_start(1))
    DO i=1,NITER
        ! Multiplication with assignation
        A = MATMUL(C , B )
        C = MATMUL(A , B )
    END DO
    CALL CPU_TIME(time_finish(1))

    CPU_TIMES = 1.0d9*( time_finish(1) - time_start(1) ) / NITER_R ! In us.

    PRINT "(2(A,F20.3,8X))", '-- OTI MATMUL CPU_TIME [ns]:', &!
                            CPU_TIMES

    PRINT *, " "
    PRINT *, " PROGRAM ENDED SUCCESSFULLY."
    PRINT *, " "



END PROGRAM MAIN
